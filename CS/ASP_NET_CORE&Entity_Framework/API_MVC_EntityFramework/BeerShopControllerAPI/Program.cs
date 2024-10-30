using Backend.AutoMappers;
using Backend.DTOs;
using Backend.Models;
using Backend.Repository;
using Backend.Services;
using Backend.Validators;
using FluentValidation;
using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.DependencyInjection;

var builder = WebApplication.CreateBuilder(args);

// Add services to the container.

//BEERSERVICE
builder.Services.AddKeyedScoped<ICommonService<BeerDTO, BeerInsertDTO, BeerUpdateDTO>, BeerService>("beerService");
builder.Services.AddKeyedScoped<ICommonService<BrandDTO, BrandInsertDTO, BrandUpdateDTO>, BrandService>("brandService");

//REPOSITORY
builder.Services.AddKeyedScoped<IRepository<Beer>, BeerRepository>("BeerRepository");
builder.Services.AddKeyedScoped<IRepository<Brand>, BrandRepository>("BrandRepository");

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


//Mappers
builder.Services.AddAutoMapper(typeof(MappingProfile));


builder.Services.AddControllers();
// Learn more about configuring Swagger/OpenAPI at https://aka.ms/aspnetcore/swashbuckle
builder.Services.AddEndpointsApiExplorer();
builder.Services.AddSwaggerGen();

var app = builder.Build();

// Configure the HTTP request pipeline.
if (app.Environment.IsDevelopment())
{
    app.UseSwagger();
    app.UseSwaggerUI();
}

app.UseHttpsRedirection();

app.UseAuthorization();

app.MapControllers();

app.Run();
