using BeerShop.Aplication.AutoMappers;
using BeerShop.Aplication.DTOs;
using BeerShop.Aplication.DTOs.Beer;
using BeerShop.Aplication.DTOs.Brand;
using BeerShop.Aplication.Services;
using BeerShop.Aplication.Validators.Beer;
using BeerShop.Aplication.Validators.Brand;
using BeerShop.Aplication.Validators.User;
using BeerShop.Core.Interfaces;
using BeerShop.Infrastructure.Configurations;
using BeerShop.Infrastructure.Configurations.MiddleWare;
using BeerShop.Infrastructure.Data;
using BeerShop.Infrastructure.Data.Repository;
using FluentValidation;
using Microsoft.AspNetCore.Authentication.JwtBearer;
using Microsoft.AspNetCore.ResponseCompression;
using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.DependencyInjection;
using Microsoft.IdentityModel.Tokens;
using System.Security.Cryptography;
using System.Text;

var builder = WebApplication.CreateBuilder(args);

// Add services to the container.

//BEERSERVICE
builder.Services.AddKeyedScoped<ICommonService<BeerDTO, BeerInsertDTO, BeerUpdateDTO>, BeerService>("beerService");
builder.Services.AddKeyedScoped<ICommonService<BrandDTO, BrandInsertDTO, BrandUpdateDTO>, BrandService>("brandService");

//REPOSITORY
builder.Services.AddScoped<IUnitOfWork, UnitOfWork>();

//Entity Framework DB
builder.Services.AddDbContext<StoreContext>(options =>
{
    options.UseSqlServer(builder.Configuration.GetConnectionString("StoreConnection"));
});

//Validators
builder.Services.AddScoped<IValidator<BeerInsertDTO>, BeerInsertValidator>();
builder.Services.AddScoped<IValidator<BeerUpdateDTO>, BeerUpdateValidator>();

builder.Services.AddScoped<IValidator<BrandInsertDTO>, BrandInsertValidator>();
builder.Services.AddScoped<IValidator<BrandUpdateDTO>, BrandUpdateValidator>();

builder.Services.AddScoped<IValidator<UserRegisterDTO>, UserRegisterValidator>();
builder.Services.AddScoped<IValidator<UserLogingDTO>, UserLogingValidator>();


//Mappers
builder.Services.AddAutoMapper(typeof(MappingProfile));


builder.Services.AddControllers();
// Learn more about configuring Swagger/OpenAPI at https://aka.ms/aspnetcore/swashbuckle
builder.Services.AddEndpointsApiExplorer();
builder.Services.AddSwaggerGen();

//Authentication
builder.Services.AddAuthentication(options =>
{
    options.DefaultAuthenticateScheme = JwtBearerDefaults.AuthenticationScheme;
    options.DefaultChallengeScheme = JwtBearerDefaults.AuthenticationScheme;
})
.AddJwtBearer(options =>
{
    options.TokenValidationParameters = new TokenValidationParameters
    {
        ValidateIssuer = true,
        ValidateAudience = true,
        ValidateLifetime = true,
        ValidateIssuerSigningKey = true,

        ValidIssuer = builder.Configuration["Jwt:Issuer"],
        ValidAudience = builder.Configuration["Jwt:Audience"],
        IssuerSigningKey = new SymmetricSecurityKey(Encoding.UTF8.GetBytes(builder.Configuration["Jwt:Key"]))
    };
}
);

//JWTService
builder.Services.AddScoped<IJwt, Jwt>();

//IAuthService
builder.Services.AddScoped<IAuthService, AuthService>();

//Cross-Origin Resource Sharing CORS
builder.Services.AddCors(options =>
{
    options.AddPolicy("localhost",
        builder => builder.WithOrigins("https://localhost:7177")
        .AllowAnyMethod()
        .AllowAnyMethod());
});

//ResponseCompression
builder.Services.AddResponseCompression(options =>
{
    options.EnableForHttps = true;
    options.MimeTypes = ResponseCompressionDefaults.MimeTypes.Concat(new[] { "application/json" });
});

var app = builder.Build();

// Configure the HTTP request pipeline.
if (app.Environment.IsDevelopment())
{
    app.UseSwagger();
    app.UseSwaggerUI();
}

//Middleware
app.UseRequestLoggin();
app.UseErrorHandling();
app.UseAuditMiddleware();

app.UseCors("localhost");

app.UseResponseCompression();


app.UseHttpsRedirection();

//autentication
app.UseAuthentication();

app.UseAuthorization();

app.MapControllers();

app.Run();


