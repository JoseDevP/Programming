#include <iostream>
#include "cterminoenxy.hpp"

CTerminoEnXY CTerminoEnXY::operator+(const CTerminoEnXY& t)
{
    asignarCoeficiente(CTerminoEnX::obtenerCoeficiente() + t.CTerminoEnX::obtenerCoeficiente());
    return *this;
}