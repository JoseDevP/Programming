#include <iostream>

#include "ccamion.hpp"

void CCamion::asignarCapacidadCarga(double cCarga)
{
    if( cCarga < 0)
    {
        capacidadCarga = 0;
        return;
    }
    capacidadCarga = cCarga; 
}

double CCamion::obtenerCapacidadCarga() const
{
    return capacidadCarga;
}

void CCamion::describirVehiculo() const 
{
    std::cout << obtenerMarca() << ", " << "Modelo: " << obtenerModelo() << ", " 
    << "Año: " << obtenerAño() << ", " << "Capacidad de carga: " << capacidadCarga << std::endl; 
}

bool CCamion::esVehiculoGrande() const 
{
    return true;
}