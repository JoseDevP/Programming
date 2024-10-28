#include <iostream>

#include "cficha.hpp"
#include "cficha_libro.hpp"

CFichaLibro::CFichaLibro(std::string ref, std::string tit, std::string au, std::string ed ) :
CFicha(ref, tit), autor(au), editorial(ed)
{
    asignarAutor(au);
    asignarEditorial(ed);
}

void CFichaLibro::asignarAutor(std::string au)
{
    autor = au;
}

std::string CFichaLibro::obtenerAutor() const
{
    return autor;
}

void CFichaLibro::asignarEditorial(std::string ed)
{
    editorial = ed;
}

std::string CFichaLibro::obtenerEditorial() const
{
    return editorial;
}