using Microsoft.EntityFrameworkCore;
using MoviesAPI.Data;
using MoviesAPI.MoviesMappers;
using MoviesAPI.Repository;
using MoviesAPI.Repository.IRepository;

var builder = WebApplication.CreateBuilder(args);

// Add services to the container.

//Unit Of work
builder.Services.AddScoped<IUnitOfWork, UnitOfWork>();

//mapper
builder.Services.AddAutoMapper(typeof(MoviesMapper));

//dbcontext
builder.Services.AddDbContext<ApplicationDbContext>(opt =>
    opt.UseSqlServer(builder.Configuration.GetConnectionString("SqlDataBase"))
);

builder.Services.AddControllers();
// Learn more about configuring Swagger/OpenAPI at https://aka.ms/aspnetcore/swashbuckle
builder.Services.AddEndpointsApiExplorer();
builder.Services.AddSwaggerGen();

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
    app.UseSwaggerUI();
}

app.UseHttpsRedirection();

app.UseCors("CorsPolitic");

app.UseAuthorization();

app.MapControllers();

app.Run();
