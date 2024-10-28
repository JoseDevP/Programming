#include <stdio.h>
#include "iniciar.hpp"

CIniciar::CIniciar(double x)
{
    val = x;
}

void CIniciar::operator()(CVector& v)
{
    for (int i = 0; i < v.longitud(); i++)
        v[i] = val;
}

void CIniciar::valor(double x)
{
    val = x;
}