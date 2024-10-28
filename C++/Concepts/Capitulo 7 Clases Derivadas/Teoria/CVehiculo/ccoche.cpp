#include <iostream>

#include "ccoche.hpp"

void CCoche::asignarNumeroPuertas(int n)
{
    if( n < 1)
    {
        numPuertas = 1;
        return;
    }  
    numPuertas = n;
}

int CCoche::obtenerNumeroPuertas() const
{
    return numPuertas;
}

void CCoche::describirVehiculo() const 
{
    std::cout << "Marca: " << obtenerMarca() << ", " << "Modelo: " << obtenerModelo() << ", " 
    << "Año: " << obtenerAño() << ", " << "Numero de puertas: " << numPuertas << std::endl; 
}