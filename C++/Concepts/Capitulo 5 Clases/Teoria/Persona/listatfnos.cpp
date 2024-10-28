#include <iostream>
#include "listatfnos.hpp"

CListaTfnos::CListaTfnos()
{
    listaTelefonos.reserve(100);
}

CPersona CListaTfnos::registro(unsigned int i)
{
    return listaTelefonos.at(i);
}

void CListaTfnos::anyadir(CPersona obj)
{
    listaTelefonos.push_back(obj);
}

bool CListaTfnos::eliminar(long tel)
{
    for (size_t i = 0; i < listaTelefonos.size(); i++)
        if (listaTelefonos[i].obtenerTelefono() == tel)
        {
            listaTelefonos.erase(listaTelefonos.begin() + i );
            return true;
        }
    return false;
}

int CListaTfnos::buscar(std::string str, int pos)
{
    std::string nom;
    if(str.empty()) return -1;
    if(pos < 0) pos = 0;
    for (size_t i = pos; i < listaTelefonos.size(); i++)
    {
        nom = listaTelefonos[i].obtenerNombre();
        if(nom.empty()) continue;
        if(nom.find(str) != std::string::npos)
            return i;
    }
    return -1;
}

size_t CListaTfnos::longitud()
{
    return listaTelefonos.size();
}