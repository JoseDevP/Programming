#include <iostream>
#include "ccuentaCorrientePlus.hpp"
#include "fecha.hpp"

CCuentaCorrientePlus::CCuentaCorrientePlus(std::string nom, std::string cuen, double sal,
double tipo, double imp , int transEx) : CCuentaCorriente(nom, cuen, sal, tipo, imp, transEx)
{

}

CCuentaCorrientePlus* CCuentaCorrientePlus::clonar()
{
    return new CCuentaCorrientePlus(*this);
}


double CCuentaCorrientePlus::intereses()
{
    int dia, mes, anyo;
    CFecha::obtenerFechaActual(dia, mes, anyo);

    if(dia != 1 || obtenerSaldo() < 3000) return 0.0;

    double interesesProducidos = 0.0;
    interesesProducidos = obtenerSaldo() * obtenerTipoDeInteres() / 1200.0; 
    ingreso(interesesProducidos);
    decrementarTransacciones();

    return interesesProducidos;
}



