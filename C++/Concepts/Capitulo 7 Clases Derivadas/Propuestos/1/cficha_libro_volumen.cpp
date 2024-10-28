#include <iostream>

#include "cficha_libro_volumen.hpp"

CFichaLibroVolumen::CFichaLibroVolumen(std::string ref, std::string tit, std::string au, std::string ed, 
int nVol) : CFichaLibro(au, ed), numeroVolumen(nVol)
{
    asignarVolumen(nVol);
}

void CFichaLibroVolumen::asignarVolumen(int nVol)
{
    numeroVolumen = nVol;
}

int CFichaLibroVolumen::obtenerVolumen() const
{
    return numeroVolumen;
}

