#include <iostream>
#include "complejo.hpp"

CComplejo CComplejo::operator-()
{
    return CComplejo(-real, -imag);
}

CComplejo CComplejo::operator-(CComplejo x)
{
    return CComplejo(real - x.real, imag - x.imag);
}

void CComplejo::AsignarComplejo(double r, double i)
{
    real = r;
    imag = i;
}

void CComplejo::ObtenerComplejo(double& r, double& i) const
{
    r = real;
    i = imag;
}