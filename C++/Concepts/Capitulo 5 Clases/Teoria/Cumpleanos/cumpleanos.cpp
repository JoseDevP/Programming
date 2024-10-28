#include <iostream>
#include <cstring>
#include "cumpleanos.hpp"

CCumpleaños::CCumpleaños(const char* nom, int dd, int mm, int aaaa, long t)
{
    nombre = nullptr;
    asignarTelefono(t);
    asignarNombre(nom);
    fecha_nacimiento.asignarFecha(dd, mm, aaaa);
}

void CCumpleaños::asignarNombre(const char* nom)
{
    if(nombre != nullptr)
        delete[] nombre;
    nombre = asignarCadena(nom);
}

void CCumpleaños::asignarTelefono(long t)
{
    if(t < 0)
        throw std::out_of_range("El telofono no puede ser menor que 0");
    telefono = t;
}

char* CCumpleaños::asignarCadena(const char* pcad) const
{
    char* pcadena;
    if(pcad == nullptr) return nullptr;
    pcadena = new char[strlen(pcad) + 1];
    strcpy(pcadena, pcad);
    return pcadena;
}

