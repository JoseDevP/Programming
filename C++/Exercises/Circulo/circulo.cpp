#include <iostream>
#include "circulo.hpp"

void Circulo::msgEsNegativo()
{
    std::cout << "El radio es negativo. Se convierte a positivo\n";
}

Circulo::Circulo(double cx, double cy, double r) : centro {cx ,cy}, radio{r}
{
    if(r < 0)
    {
        msgEsNegativo();
        radio = -r;
    }
}

double Circulo::longCircunferencia()
{
    return 2 * 3.1415926 * radio;
}

double Circulo::areaCirculo()
{
    return 3.1415926 * radio * radio;
}

void Circulo::asignarRadio(double r)
{
    if(r < 0)
    {
        msgEsNegativo(); 
        r = -r;
    } 
    radio = r;
}

void Circulo::coordenadaCentro(double& x, double &y) const
{
    x = centro.X();
    y = centro.Y();
}

