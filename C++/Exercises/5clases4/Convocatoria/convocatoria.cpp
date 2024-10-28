#include <iostream>
#include "../Fecha/fecha.hpp"
#include "convocatoria.hpp"

using namespace cfe;

CConvocatoria::CConvocatoria(int c, float n)
{
    asignarConvocatoria(c);
    asignarFecha();
    asignarNota(n);
}

void CConvocatoria::asignarConvocatoria(int conv)
{
    if(convocatoria > 6)
    {
        std::cerr << "error: convocatorias agotadas\n";
        return;

    }
    if( (conv < 0 || conv > 6) )
    {
        std::cerr << "error: convocatorias no valido";
        convocatoria = 0;
        return;
    }
    convocatoria = conv;
}

int CConvocatoria::obtenerConvocatoria() const
{
    return convocatoria;
}

void CConvocatoria::asignarFecha(int mes, int anyo )
{
    int d, m, a;
    if(CFecha().asignarFecha(1,mes,anyo))
    {
        m = mes; a = anyo;
    }
    else
        CFecha::obtenerFechaActual(d,m,a);
    char sfecha[7];
    sprintf(sfecha, "%.2d%.4d",m,a);
    fecha = std::string(sfecha);
}

std::string CConvocatoria::obtenerFecha() const
{
    return fecha;
}

void CConvocatoria::asignarNota(float n)
{
    if( (n < 0 || n > 10) )
    {
        std::cerr << "error: nota no valida";
        nota = 0;
        return;
    }
    nota = n;
}

float CConvocatoria::obtenerNota() const
{
    return nota;
}