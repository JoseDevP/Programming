#include <iostream>
#include "palabras.hpp"

void CPalabra::insertarPalabra(const std::string& p)
{
    palabras[p]++;   
}

int CPalabra::buscarPalabra(const std::string& p) const
{
    std::map<std::string, int>::const_iterator it = palabras.find(p);
    if(it != palabras.end())
    {
        return it->second;
    }
    return 0;
    
}

void CPalabra::visualizarTablaFrecuencias() const
{
    std::map<std::string, int>::const_iterator it;
    for (it = palabras.begin(); it != palabras.end(); it++)
        std::cout << it->first << "-> " << it->second << std::endl;
    
}