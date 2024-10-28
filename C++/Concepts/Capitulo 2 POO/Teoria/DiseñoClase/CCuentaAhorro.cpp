#include <iostream>
#include "CCuenta.h"
#include "CCuentaAhorro.h"

using namespace std;


CCuentaAhorro::CCuentaAhorro(){}

CCuentaAhorro::CCuentaAhorro(string nom, string cue, double sal, double tipo, double mant) : CCuenta(nom, cue, sal, tipo)
{
    asignarCuotaManten(mant);
}

void CCuentaAhorro::asignarCuotaManten(double cantidad)
{
    if(cantidad < 0)
    {
        cout << "Error: cantidad negativa\n";
        return;
    }
    cuotaMantenimiento = cantidad;
}
                                                                                      
double CCuentaAhorro::obtenerCuotaManten()
{
    return cuotaMantenimiento;
}

void CCuentaAhorro::reintegro(double cantidad)
{
    double saldo =  CCuenta::obtenerSaldo();
    double tipoDeInteres = CCuenta::obtenerTipoDeInteres();

    if(tipoDeInteres >= 3.5)
    {
        if(saldo - cantidad < 1500)
        {
            cout << "Error: no dispone de esa cantidad\n";
            return;
        }
        CCuenta::reintegro(cantidad);
    }
}


