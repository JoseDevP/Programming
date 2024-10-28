#include <iostream>

#include "cficha.hpp"

CFicha::CFicha(std::string ref, std::string tit) : referencia(ref), titulo(tit)
{
    asignarReferencia(ref);
    asignarTitulo(tit);
}

void CFicha::asignarReferencia(std::string ref)
{
    referencia = ref;
}

std::string CFicha::obtenerReferencia() const
{
    return referencia;
}

void CFicha::asignarTitulo(std::string tit)
{
    titulo = tit;
}

std::string CFicha::obtenerTitulo() const
{
    return titulo;
}



