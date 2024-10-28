#include <iostream>

using namespace std;

#include "CCuenta.h"

CCuenta::CCuenta()
{
    saldo=0;
    tipoDeInteres=0;
}

CCuenta::CCuenta(string nom, string cue, double sal, double tipo)
{
    asignarNombre(nom);
    asignarCuenta(cue);
    saldo=0; ingreso(sal);
    asignarTipoDeInteres(tipo);
}

void CCuenta::asignarNombre(string nom)
{
    if(nom.length() == 0)
    {
        cout << "Error: cadena vacia\n";
        return;
    }
    nombre = nom;
}

string CCuenta::obtenerNombre()
{
    return nombre;
}

void CCuenta::asignarCuenta(string cue)
{
    if(cue.length() == 0)
    {
        cout << "Error: cadena vacia\n";
        return;
    }
    cuenta=cue;
}

string CCuenta::obtenerCuenta()
{
    return cuenta;
}

double CCuenta::obtenerSaldo()
{
    return saldo;
}

void CCuenta::ingreso(double cantidad)
{
    if (cantidad < 0)
    {
        cout << "Error: cantidad negativa\n";
        return;
    }
    saldo+=cantidad;
}

void CCuenta::reintegro(double cantidad)
{
    if(saldo - cantidad < 0)
    {
        cout << "Error: tipo de interes no válido\n";
        return;
    }
    saldo-=cantidad;
}

void CCuenta::asignarTipoDeInteres(double tipo)
{
    if (tipo < 0)
    {
        cout << "Error: tipo de interes no válido\n";
        return;
    }
    tipoDeInteres=tipo;
}

double CCuenta::obtenerTipoDeInteres()
{
    return tipoDeInteres;
}