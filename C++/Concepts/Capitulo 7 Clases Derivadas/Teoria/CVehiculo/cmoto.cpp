#include <iostream>

#include "cmoto.hpp"

void CMoto::asignarTipoMotor(std::string tmot)
{
    if(tmot.empty()) 
    {
        tipoMotor = "ninguno";
        return;
    }
    tipoMotor = "gasolina";
}

std::string CMoto::obtenerTipoMotor() const
{
    return tipoMotor;
}

void CMoto::describirVehiculo() const 
{
    std::cout << "Marca: " << obtenerMarca() << ", " << "Modelo: " << obtenerModelo() << ", " 
    << "Año: " << obtenerAño() << ", " << "Tipo de motor: " << tipoMotor << std::endl; 
}