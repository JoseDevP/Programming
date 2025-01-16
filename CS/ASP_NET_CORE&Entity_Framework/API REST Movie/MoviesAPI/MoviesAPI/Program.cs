using Asp.Versioning;
using Microsoft.AspNetCore.Authentication.JwtBearer;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using Microsoft.IdentityModel.Tokens;
using Microsoft.OpenApi.Models;
using MoviesAPI.Data;
using MoviesAPI.MoviesMappers;
using MoviesAPI.Repository;
using MoviesAPI.Repository.IRepository;
using System.Text;

var builder = WebApplication.CreateBuilder(args);

// Add services to the container.

//Support for cache
builder.Services.AddResponseCaching();

//Unit Of work
builder.Services.AddScoped<IUnitOfWork, UnitOfWork>();

//mapper
builder.Services.AddAutoMapper(typeof(MoviesMapper));

var key = builder.Configuration.GetValue<string>("ApiSettings:SecretKey");

//Versions Support
var apiVersioningBuilder = builder.Services.AddApiVersioning(option=>
{
    option.AssumeDefaultVersionWhenUnspecified = true;
    option.DefaultApiVersion = new ApiVersion(1, 0); //default version 1.0
    option.ReportApiVersions = true; //info about versions supported
    //option.ApiVersionReader = ApiVersionReader.Combine( //combine two methods
    //new QueryStringApiVersionReader("api-version") //version from query string url 
    //);
});

apiVersioningBuilder.AddApiExplorer(
    options=>
    {
        options.GroupNameFormat = "'v'VVV"; //v version, VVV name of version
        options.SubstituteApiVersionInUrl = true;
    });


//Authentication
builder.Services.AddAuthentication(
    x =>
    {
        x.DefaultAuthenticateScheme = JwtBearerDefaults.AuthenticationScheme; //jwt for authentication
        x.DefaultChallengeScheme = JwtBearerDefaults.AuthenticationScheme; //scheme jwbearer is default
    }
).AddJwtBearer(
    x=>
    {
        x.RequireHttpsMetadata = false; //Not required http for metadata ( in production is required) 
        x.SaveToken = true; //jwt must have it in the context of the authentication
        x.TokenValidationParameters = new TokenValidationParameters
        {
            ValidateIssuerSigningKey = true, //signing kkey must be validate
            IssuerSigningKey = new SymmetricSecurityKey(Encoding.ASCII.GetBytes(key)), //signing key must be the same that signed tokens 
            ValidateIssuer = false, //validate or not the emisor of the token
            ValidateAudience = false //validate or not the audience of the token
        };
    }
);

//dbcontext
builder.Services.AddDbContext<ApplicationDbContext>(opt =>
    opt.UseSqlServer(builder.Configuration.GetConnectionString("SqlDataBase"))
);

builder.Services.AddControllers(options =>
{
    options.CacheProfiles.Add("Default", new CacheProfile() { Duration = 10});
});

// Learn more about configuring Swagger/OpenAPI at https://aka.ms/aspnetcore/swashbuckle
builder.Services.AddEndpointsApiExplorer();
builder.Services.AddSwaggerGen(options=>
{
        options.AddSecurityDefinition("Bearer", new OpenApiSecurityScheme
        {
            Description =
            "Authentication JWT using Bearer Scheme. \r\n\r\n " +
            "Word Bearer next [space] ant then your token. \r\n\r\n " +
            "Example: \"Bearer tkj13161561561\"",
            Name = "Authorization",
            In = ParameterLocation.Header,
            Scheme = "Bearer"
        });
        options.AddSecurityRequirement(new OpenApiSecurityRequirement()
        {
            {
                new OpenApiSecurityScheme
                {
                    Reference = new OpenApiReference
                    {
                        Type = ReferenceType.SecurityScheme,
                        Id = "Bearer"
                    },
                    Scheme = "oauth2",
                    Name = "Bearer",
                    In = ParameterLocation.Header
                },
                new List<string>() //You can specify scopes
            }
        });
        options.SwaggerDoc("v1", new OpenApiInfo
        {
                Version = "v1",
                Title = "MoviesApiV1",
                Description="Api from movies v1",
                TermsOfService = new Uri("https://josepage.com"),
                Contact = new OpenApiContact
                {
                    Name = "Jose",
                    Url = new Uri("https://josepage.com")
                },
                License = new OpenApiLicense
                {
                    Name = "Personal License",
                    Url = new Uri("https://josepage.com")
                }
        });
        options.SwaggerDoc("v2", new OpenApiInfo
        {
            Version = "v2",
            Title = "MoviesApiV2",
            Description = "Api from movies v2",
            TermsOfService = new Uri("https://josepage.com"),
            Contact = new OpenApiContact
            {
                Name = "Jose",
                Url = new Uri("https://josepage.com")
            },
            License = new OpenApiLicense
            {
                Name = "Personal License",
                Url = new Uri("https://josepage.com")
            }
        });
}
);

//CORS
builder.Services.AddCors(p => p.AddPolicy("CorsPolitic", build =>
{
    build.WithOrigins("https://localhost:7120").AllowAnyMethod().AllowAnyHeader();
    //build.WithOrigins("*").AllowAnyMethod().AllowAnyHeader(); -> * Para todos 
}
));

var app = builder.Build();

// Configure the HTTP request pipeline.
if (app.Environment.IsDevelopment())
{
    app.UseSwagger();
    app.UseSwaggerUI(options =>
    {
        options.SwaggerEndpoint("/swagger/v1/swagger.json", "MoviesApiV1");
        options.SwaggerEndpoint("/swagger/v2/swagger.json", "MoviesApiV2");
    });
}

app.UseHttpsRedirection();

app.UseCors("CorsPolitic");

//Supor for authentication
app.UseAuthentication();
app.UseAuthorization();

app.MapControllers();

app.Run();
