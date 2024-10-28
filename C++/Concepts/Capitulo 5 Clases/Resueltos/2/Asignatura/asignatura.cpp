#include <iostream>
#include "asignatura.hpp"

CAsignatura::CAsignatura(int id, std::string nom) : ID(id), nombre(nom)
{
    asignarID(id);
    fecha.asignarFecha();
    convocatorias.reserve(6);
}

void CAsignatura::asignarID(int id)
{
    if(id < 1)
    {
        std::cerr << "error: id no valido";
        ID = 999999;
    }
}

int CAsignatura::obtenerID() const
{
    return ID;
}

void CAsignatura::asignarNombre(std::string nom)
{
    nombre = nom;
}

std::string CAsignatura::obtenerNombre() const
{
    return nombre;
}

void CAsignatura::asignarFecha(CFecha& f)
{
    fecha = f;
}

const CFecha& CAsignatura::obtenerFecha() const
{
    return fecha;
}

CConvocatoria& CAsignatura::obtenerConvocatoria(unsigned int i)
{
    static CConvocatoria c;
    size_t n = convocatoriasConsumidas();
    if((n == 0)) return c;
    --i;
    if(i >= 0 && i < n)
        return convocatorias[i];
    else
    {
        std::cerr << "error: convocatorias consumidas " << n << std::endl;
        return c;
    }
}

void CAsignatura::anyadirConvocatoria(CConvocatoria& c)
{
    convocatorias.push_back(c);
}

size_t CAsignatura::convocatoriasConsumidas()
{
    return convocatorias.size(); 
}
