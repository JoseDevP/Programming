#include <iostream>
#include "alumno.hpp"

CAlumno::CAlumno (long dni, std::string nom, std::string dir) :
DNI(dni), nombre(nom), direccion(dir)
{
    asignarDNI(dni);
    asignatura.reserve(10);
}

CAlumno::CAlumno (const CAlumno& x)
{
    *this = x;
}

CAlumno::~CAlumno()
{
    for (unsigned int i = 0; i < numeroAsignaturas(); i++)
        delete asignatura[i];
    
}

CAlumno CAlumno::operator=(const CAlumno& x)
{
    if(asignatura.size())
    {
        for (unsigned int i = 0; i < asignatura.size(); i++)
            delete asignatura[i];
        asignatura.clear();
    }

    DNI = x.DNI;
    
    nombre = x.nombre;

    direccion = x.direccion;

    for (unsigned int i = 0; i < x.asignatura.size(); i++)
        asignatura.push_back(new CAsignatura(*(x.asignatura[i])));
        return *this;
    
}

void CAlumno::asignarDNI(long dni)
{
    if(dni < 0)
    {
        std::cerr <<"error: DNI no valido\n";
        dni = 0;
    }
    DNI = dni;
}

long CAlumno::obtenerDNI() const
{
    return DNI;
}

void CAlumno::asignarNombre(std::string& nom)
{
    nombre = nom;
}

std::string CAlumno::obtenerNombre() const
{
    return nombre;
}

void CAlumno::asignarDireccion(std::string& dir)
{
    direccion = dir;
}

std::string CAlumno::obtenerDireccion() const
{
    return direccion;
}

CAsignatura* CAlumno::obtenerAsignatura(unsigned int i)
{
    if(numeroAsignaturas() == 0) return 0;
    if(i >= 0 && i < numeroAsignaturas())
        return asignatura[i];
    else
    {
        std::cerr << "error: indice fuera de limites\n";
        return 0;
    }
}

bool CAlumno::estaEnActa(int id, int& i)
{
    if(numeroAsignaturas() == 0)    return false;
    for ( i = 0; i < numeroAsignaturas(); i++)
    {
        CAsignatura* asig = obtenerAsignatura(i);
        if(asig->obtenerID() != id) continue;
        int nconv = asig->convocatoriasConsumidas();
        if(nconv > 0)
            if( asig->obtenerConvocatoria(nconv).obtenerNota() >= 5)
                return false;
        if(nconv == 6)
        {
            std::cerr << "error: convocatorias agotadas\n";
            break;
        }
        return true;
    }
    return false;
}

void CAlumno::anyadirAsignatura(CAsignatura* asig)
{
    asignatura.push_back(new CAsignatura(*asig));
}

size_t CAlumno::numeroAsignaturas() const
{
    return asignatura.size();
}