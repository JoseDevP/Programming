#include <iostream>
#include "persona.hpp"


CPersona::CPersona(std::string nom, std::string dir, long tel) 
: nombre{nom}, direccion{dir}, telefono{tel}
{  } 

void CPersona::asignarNombre(const std::string& nom)
{
    nombre = nom;
}

std::string CPersona::obtenerNombre() const
{
    return nombre;
}

void CPersona::asignarDireccion(const std::string& dir)
{
    direccion = dir;
}

std::string CPersona::obtenerDireccion() const
{
    return direccion;
}

void CPersona::asignarTelefono(long tel)
{
    telefono = tel;
}

long CPersona::obtenerTelefono() const
{
    return telefono;
}