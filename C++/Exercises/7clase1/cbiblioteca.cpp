#include <iostream>
#include "cbiblioteca.hpp"

CBiblioteca::~CBiblioteca()
{
    for (size_t i = 0; i < fichas.size(); i++)
        delete fichas[i];
    fichas.clear();
}

CBiblioteca::CBiblioteca(const CBiblioteca& b)
{
    *this = b;
}

CBiblioteca& CBiblioteca::operator=(const CBiblioteca& b)
{
    if(this == &b) return *this;

    if(fichas.size() != 0)
    {
        for (size_t i = 0; i < fichas.size(); i++)
            delete fichas[i];
        fichas.clear();
    } 

    for (size_t i = 0; i < b.longitud(); i++)
        fichas.push_back(b[i]->clonar());
    
    return *this;
}

CFicha* CBiblioteca::operator[](size_t i) const
{
    return fichas[i];
}

void CBiblioteca::anyadirFicha(CFicha* f)
{
    fichas.push_back(f->clonar());
}

int CBiblioteca::buscarFicha(std::string referencia, int n)
{
    for (size_t i = n; i < fichas.size(); i++)
    {
        if(fichas[i]->obtenerReferencia() == referencia)
            return i;
    }
    return -1;
}

bool CBiblioteca::eliminarFicha(std::string referencia)
{
    int i = buscarFicha(referencia,0);
    if(i == -1) return false;
    delete fichas[i];
    fichas.erase(fichas.begin() + i);
    return true;
}

size_t CBiblioteca::longitud() const
{
    return fichas.size();
}







