#include <iostream>
#include "cterminoenx.hpp"

void CTerminoEnX::asignarExponenteEnX(int exp)
{
    if(exp < 1 )
    {
        exponenteEnX = 1;
    }
    exponenteEnX = exp;
}

CTerminoEnX CTerminoEnX::operator+(const CTerminoEnX& t)
{
    asignarCoeficiente(obtenerCoeficiente() + t.obtenerCoeficiente());
    return *this;
}
