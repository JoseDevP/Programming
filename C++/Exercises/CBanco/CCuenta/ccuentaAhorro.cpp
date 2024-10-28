#include <iostream>
#include "ccuentaAhorro.hpp"
#include "fecha.hpp"


CCuentaAhorro::CCuentaAhorro(std::string nom, std::string cuen, double sal, double tipo, double mant) 
: CCuenta(nom, cuen, sal, tipo) ,cuotaMantenimiento(mant)
{
    if(!asignarCuotaMantenimiento(mant))
        throw "Datos incorrectos";
}

CCuentaAhorro::CCuentaAhorro(const CCuentaAhorro& ca) : CCuenta(ca), cuotaMantenimiento(ca.cuotaMantenimiento)
{

}

CCuentaAhorro* CCuentaAhorro::clonar()
{
    return new CCuentaAhorro(*this); 
}

CCuentaAhorro& CCuentaAhorro::operator=(const CCuentaAhorro& ca)
{
    if(this == &ca) return *this;
    CCuenta::operator=(ca);
    cuotaMantenimiento = ca.cuotaMantenimiento;
    return *this;
}

bool CCuentaAhorro::asignarCuotaMantenimiento(double cantidad)
{
    if ( cantidad >= 0)
        cuotaMantenimiento = cantidad;
    else
        std::cerr << "Error: cantidad negativa\n";
    return cantidad >= 0;
}

double CCuentaAhorro::obtenerCuotaMantenimiento() const
{
    return cuotaMantenimiento;
}

void CCuentaAhorro::comisiones()
{
    int dia, mes, anyo;
    CFecha::obtenerFechaActual(dia, mes, anyo);

    if(dia == 1) reintegro(cuotaMantenimiento);
}

double CCuentaAhorro::intereses()
{
    int dia, mes, anyo;
    CFecha::obtenerFechaActual(dia, mes, anyo);

    if(dia == 1) 0.0;

    double interesesProducidos = 0.0;
    interesesProducidos = obtenerSaldo() + obtenerTipoDeInteres() / 1200.0;
    ingreso(interesesProducidos);
    return interesesProducidos;
}