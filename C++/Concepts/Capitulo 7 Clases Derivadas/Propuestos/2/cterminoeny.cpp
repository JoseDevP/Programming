#include <iostream>
#include "cterminoeny.hpp"

void CTerminoEnY::asignarExponenteEnY(int exp)
{
    if(exp < 1 )
    {
        exponenteEnY = 1;
    }
    exponenteEnY = exp;
}

CTerminoEnY CTerminoEnY::operator+(const CTerminoEnY& t)
{
    asignarCoeficiente(obtenerCoeficiente() + t.obtenerCoeficiente());
    return *this;
}
