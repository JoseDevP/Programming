#include <iostream>
#include "concesionario.hpp"
#include "ccoche.hpp"
#include "cmoto.hpp"
#include "ccamion.hpp"

CConcesionario::~CConcesionario()
{
    for (size_t i = 0; i < vehiculos.size(); i++)
        delete vehiculos[i];
    
    vehiculos.clear();
}

CVehiculo* CConcesionario::operator[](int n)
{
    if(n < 0 || n >= vehiculos.size())   return nullptr;
    return vehiculos[n];
}

bool CConcesionario::anyadirVehiculo(CVehiculo* v)
{
    vehiculos.push_back(v->clonar());
    return true;
}

bool CConcesionario::eliminarVehiculo(std::string marca, std::string modelo)
{
    for (size_t i = 0; i < vehiculos.size(); i++)
    {
        if(vehiculos[i]->obtenerModelo() == modelo && vehiculos[i]->obtenerMarca() == marca)
        {
            delete vehiculos[i];
            vehiculos.erase(vehiculos.begin() + i);
            return true;
        }
    }
    return false;
}

size_t CConcesionario::cantidadDeVehiculos()
{
    return vehiculos.size();
}

void CConcesionario::descripcion()
{
    for (size_t i = 0; i < vehiculos.size(); i++)
    {
        std::cout << i << ".";
        if(dynamic_cast<CCoche*>(vehiculos[i]))
        {
            std::cout << "Coche: " << std::endl;
        }
        else if(dynamic_cast<CMoto*>(vehiculos[i]))
        {
            std::cout << "Moto: " << std::endl;
        }
        else if(dynamic_cast<CCamion*>(vehiculos[i]))
        {
            std::cout << "Camion: " << std::endl;
        }

        vehiculos[i]->describirVehiculo();

        if(vehiculos[i]->esVehiculoGrande())
        {
            std::cout << "Es vehiculo grande" << std::endl;
        }
        else
            std::cout << "Es vehiculo pequeño" << std::endl;
    }
} 
