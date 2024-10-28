#include <iostream>
#include "ccuenta.hpp"

CCuenta::CCuenta(std::string nom, std::string cuen, double sal, double tipo) 
: nombre(nom), cuenta(cuen), saldo(sal), tipoDeInteres(tipo)
{
    if(!asignarNombre(nom) || !asignarCuenta(cuen) || !ingreso(sal) || !asignarTipoDeInteres(tipo))
        throw "Datos Incorrectos";
}

CCuenta::CCuenta(const CCuenta& c) : nombre(c.nombre), cuenta(c.cuenta), saldo(c.saldo), tipoDeInteres(c.tipoDeInteres)
{
}

CCuenta& CCuenta::operator=(const CCuenta& c)
{
    if(this == &c) return *this;
    nombre = c.nombre;
    cuenta = c.cuenta;
    saldo = c.saldo;
    tipoDeInteres = c.tipoDeInteres;
    return *this;
}




bool CCuenta::asignarNombre(std::string nom)
{
    if(nom.length() != 0)
        nombre = nom;
    else
        std::cerr << "Error: cadena nombre vacia\n";
    return nom.length() != 0;
}

std::string CCuenta::obtenerNombre() const
{
    return nombre;
}

bool CCuenta::asignarCuenta(std::string cuen)
{
    if(cuen.length() != 0)
        cuenta = cuen;
    else    
        std::cerr << "Error: cuenta no valida\n";
    return cuen.length() != 0;
}

std::string CCuenta::obtenerCuenta() const
{
    return cuenta;
}

double CCuenta::obtenerSaldo() const
{
    return saldo;
}


bool CCuenta::ingreso(double cantidad)
{
    if(cantidad >= 0)   
        saldo += cantidad;
    else
        std::cerr << "Error: ingreso negativo";
    return cantidad >= 0;
}

void CCuenta::reintegro(double cantidad)
{
    if(saldo - cantidad < 0)
    {
        std::cerr << "Error: no dispone de saldo\n";
        return;
    }
    saldo -= cantidad;
}

double CCuenta::obtenerTipoDeInteres() const
{
    return tipoDeInteres;
}

bool CCuenta::asignarTipoDeInteres(double tipo)
{
    if(tipo >= 0)
        tipoDeInteres = tipo;
    else
        std::cerr << "Error: tipo no valido\n";
    return tipo >= 0;
}
