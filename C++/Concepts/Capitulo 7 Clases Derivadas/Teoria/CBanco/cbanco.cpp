#include <iostream>
#include "cbanco.hpp"

CBanco::CBanco()
{
    cuentas.reserve(100);
}

CBanco::~CBanco()
{
    for (size_t i = 0; i < cuentas.size(); i++)
        delete cuentas[i];        
}

CBanco::CBanco(const CBanco& x)
{
    *this = x; //invoca a operator=
    
}

CBanco& CBanco::operator=(const CBanco& x)
{
    if(this == &x) return *this; 
    if(cuentas.size())
    {
        CBanco::~CBanco();
        cuentas.resize(x.cuentas.size());
    }
    for (size_t i = 0; i < x.cuentas.size(); i++)
        cuentas.push_back(x.cuentas[i]->clonar());
    return *this;
}

CCuenta* CBanco::operator[](size_t i) const
{
    if(i >= 0 || i < cuentas.size())
        return cuentas[i];
    else
    {
        std::cerr << "error: indice fuera de limites\n";
        return 0;
    }
}

void CBanco::anyadir(CCuenta* obj)
{
    cuentas.push_back( obj->clonar() );
}

bool CBanco::eliminar(std::string cuenta)
{
    int i = buscar(cuenta);
    if(i != -1)
    {
        delete cuentas[i];
        cuentas.erase(cuentas.begin() + i);
        return true;
    }
    return false;
}

int CBanco::buscar(std::string str, int pos) const
{
    std::string nom, cuen;
    if(str.empty()) return -1;
    if(pos < 0) pos = 0;
    for (size_t i = pos; i < cuentas.size(); i++)
    {
        nom = cuentas[i]->obtenerNombre();
        if(nom.empty()) continue;
        if(nom.find(str) != std::string::npos)
            return i;
        cuen = cuentas[i]->obtenerCuenta();
        if(cuen.empty()) continue;
        if(str == cuen)
            return i;
    }
    return -1;
}

size_t CBanco::longitud() const
{
    return cuentas.size();
}

std::string CBanco::tipoCuenta(CCuenta* cuenta)
{
    std::string tipo = "";
    if(dynamic_cast<CCuentaAhorro*>(cuenta))
        tipo = "CCuentaAhorro";
    else if(dynamic_cast<CCuentaCorriente*>(cuenta))
        tipo = "CCuentaCorriente";
    else if(dynamic_cast<CCuentaCorrientePlus*>(cuenta))
        tipo = "CCuentaCorrientePlus";
    return tipo;
}