#include <iostream>
#include "cvehiculo.hpp"

CVehiculo::CVehiculo(std::string mar, std::string mod, long a) : marca(mar), modelo(mod), año(a) {}

void CVehiculo::asignarMarca(std::string mar)
{
    if( mar.empty() )
    {
        marca = "ninguna";
        return;
    }   
    marca = mar;
}

std::string CVehiculo::obtenerMarca() const
{
    return marca;
}

void CVehiculo::asignarModelo(std::string mod)
{
    if( mod.empty() )
    {
        modelo = "ninguna";
        return;
    }  
    modelo = mod;
}

std::string CVehiculo::obtenerModelo() const
{
    return modelo;
}

void CVehiculo::asignarAño(long a)
{
    if(a < 0) 
    {
        año = 1998;
        return;
    }
    año = a;
}

long CVehiculo::obtenerAño() const
{
    return año;
}

void CVehiculo::describirVehiculo() const
{
    std::cout << "Vehiculo:\n" << "Marca: " << marca << ", " << "Modelo: " << modelo << ", " << "Año: " << año << std::endl; 
}

bool CVehiculo::esVehiculoGrande() const
{
    return false;
}