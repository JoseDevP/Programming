#include <iostream>
#include "fecha.hpp"

using namespace fjc;


const CFecha CFecha::fechaPredeterminada = CFecha{1,1,2001};

void CFecha::asignarFechaPredeterminada(int dd, int mm, int aaaa)
{
    
}

CFecha::CFecha(int dd, int mm, int aaaa) : dia{dd}, mes{mm}, anyo{aaaa}
{
    dia = dd; mes = mm; anyo = aaaa;

    if(!fechaValida(dia, mes, anyo))
    {
        std::cout << "Fecha incorrrecta. Se asignar 01/01/2001.\n";
        *this = fechaPredeterminada;
    }
}

bool CFecha::anyoBisiesto(int aaaa) const
{  
    return ((aaaa % 4 ==0) && (aaaa % 100 != 0) ||(aaaa % 400 == 0));
}

bool CFecha::fechaValida(int dd, int mm, int aaaa) const
{
    bool diaCorrecto, mesCorrecto, anyoCorrecto;
    anyoCorrecto = (aaaa >= 1582);
    mesCorrecto = (mm >= 1) && (mm <= 12);
    switch (mm)
    {
    case 2:
        if (anyoBisiesto(aaaa))
            diaCorrecto = (dd >= 1 && dd <= 29);
        else
            diaCorrecto = (dd >= 1 && dd <= 28);
        break;
    
    case 4: case 6: case 9: case 11:
        diaCorrecto = (dd >= 1 && dd <= 30);
        break;
    default:
        diaCorrecto = (dd >= 1 && dd <= 31);
    }

    return diaCorrecto && mesCorrecto && anyoCorrecto;
}

bool CFecha::asignarFecha()
{
    struct tm* fh;
    time_t segundos;

    time(&segundos);
    fh = localtime(&segundos);

    dia = fh->tm_mday;
    mes = fh->tm_mon + 1;
    anyo = fh ->tm_year + 1900;
    return true;
}

bool CFecha::asignarFecha(int dd)
{
    asignarFecha();
    if(!fechaValida(dd, mes, anyo))
    {
        std::cout << "Fecha incorrecta. Se asigna 01/01/2001.\n";
        *this = fechaPredeterminada;
        return false;
    }
    dia == dd;
    return true;
}

bool CFecha::asignarFecha(int dd, int mm)
{
    asignarFecha();
    if(!fechaValida(dd, mm, anyo))
    {
        std::cout << "Fecha incorrecta. Se asigna 01/01/2001.\n";
        *this = fechaPredeterminada;
        return false;
    }
    dia == dd;
    mes = mm;
    return true;
}

bool CFecha::asignarFecha(int dd, int mm, int aaaa)
{
    asignarFecha();
    if(!fechaValida(dd,mm,aaaa))
    {   
        std::cout << "Fecha incorrecta. Se asigna 01/01/2001.\n";
        *this = fechaPredeterminada;
        return false;
    }
    dia = dd; mes = mm; anyo = aaaa;
    return true;
}

void CFecha::obtenerFecha(int& dd, int&mm, int&aaaa)
{
    dd = dia; mm = mes; aaaa = anyo;
}

const int& CFecha::obtenerDia() const
{
    return dia;
}

const int& CFecha::obtenerMes() const
{
    return mes;
}

const int& CFecha::obtenerAnyo() const
{
    return anyo;
}

CFecha::~CFecha()
{
    std::cout << "Objeto CFecha destruido\n";
}

void obtenerFechaActual(int& dd, int& mm, int& aaaa)
{
    struct tm* fh;
    time_t segundos;
    time(&segundos);
    fh = localtime(&segundos);
    dd = fh->tm_mday; mm = fh->tm_mon+1; aaaa = fh->tm_year+1900;
}
