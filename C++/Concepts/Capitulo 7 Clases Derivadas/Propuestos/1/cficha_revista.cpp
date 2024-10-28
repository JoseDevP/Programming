#include <iostream>

#include "cficha_revista.hpp"

CFichaRevista::CFichaRevista(std::string ref, std::string tit, int nRev, long aPub) : 
CFicha(ref, tit), numeroRevista(nRev), añoPublicacion(aPub)
{
    asignarNumero(nRev);
    asignarAño(aPub);
}

void CFichaRevista::asignarNumero(int nRev)
{
    if( nRev < 0 )
    {
        std::cerr << "Error: el numero de revista debe ser positivo";
        numeroRevista = 0; 
    }
    numeroRevista = nRev;
}

int CFichaRevista::obtenerNumero() const
{
    return numeroRevista;
}

void CFichaRevista::asignarAño(long aPub)
{
    if( aPub < 0 )
    {
        std::cerr << "Error: el año de publicacion debe ser positivo";
        añoPublicacion = 0; 
    }
    añoPublicacion = aPub;
}

long CFichaRevista::obtenerAño() const
{
    return añoPublicacion;
}

