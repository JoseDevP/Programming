#pragma once
#include <iostream>
#include "CCuenta.h"

using namespace std;

class CCuentaAhorro : public CCuenta
{
    private: 
        double cuotaMantenimiento;

    public:
        CCuentaAhorro();
        CCuentaAhorro(string nom, string cue, double sal, double tipo, double mant);
        void asignarCuotaManten(double cantidad);
        double obtenerCuotaManten();
        void reintegro(double cantidad);
};