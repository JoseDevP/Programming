#include <iostream>
#include "ccuentaCorriente.hpp"
#include "fecha.hpp"

CCuentaCorriente::CCuentaCorriente(std::string nom, std::string cuen, double sal,double tipo, double imp, int transEx)
: CCuenta(nom, cuen, sal, tipo), importePorTrans(imp), transExcentas(transEx)
{
    transacciones = 0;
    if(!asignarImportePorTrans(imp) || !asignarTransExentas(transEx))
        throw "Datos incorrectos";
}

void CCuentaCorriente::decrementarTransacciones()
{
    transacciones--;
}

bool CCuentaCorriente::asignarImportePorTrans(double imp)
{
    if(imp >= 0)
        importePorTrans = imp;
    else
        std::cerr << "Error: cantidad negativa\n";
    return imp >= 0;
}

double CCuentaCorriente::obtenerImportePorTrans() const
{
    return importePorTrans;
}

bool CCuentaCorriente::asignarTransExentas(int transEx)
{
    if(transEx >= 0)
        transExcentas = transEx;
    else
        std::cerr << "Error: cantidad negativa\n";
    return transEx >= 0;
}

int CCuentaCorriente::obtenerTransExentas() const
{
    return transExcentas;
}

void CCuentaCorriente::ingreso(double cantidad)
{
    CCuenta::ingreso(cantidad);
    transacciones++;
}

void CCuentaCorriente::reintegro(double cantidad)
{
    CCuenta::reintegro(cantidad);
    transacciones++;
}

void CCuentaCorriente::comisiones()
{
    int dia, mes, anyo;
    CFecha::obtenerFechaActual(dia, mes, anyo);
    if(dia == 1)
    {
        int n= transacciones - transExcentas;
        if(n > 0)   reintegro(n * importePorTrans);
        transacciones = 0;
    }
}

double CCuentaCorriente::intereses()
{
    int dia, mes, anyo;
    CFecha::obtenerFechaActual(dia, mes, anyo);
    if(dia != 1) return 0.0;

    double interesesProducidos = 0.0;

    if(obtenerSaldo() <= 3000)
        interesesProducidos = obtenerSaldo() * 0.5 /1200.0;
    else
    {
        interesesProducidos = 3000 * 0.5 /1200.0 + (obtenerSaldo() - 3000) * obtenerTipoDeInteres() /1200.0;
    }
    ingreso(interesesProducidos);
    decrementarTransacciones();

    return interesesProducidos;
}