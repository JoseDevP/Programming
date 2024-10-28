#include <iostream>
#include "complejo.hpp"

void visualizar(const CComplejo&);

int main()
{
    CComplejo a( 1, 1), b, c( 2.5, 2);
    b = -c;
    c = a - b;
    visualizar(c);

    double re, im;
    std::cout << "Número complejo - escriba re im: ";
    std::cin >> re >> im;
    a.AsignarComplejo(re, im);
    visualizar(a);
}

void visualizar(const CComplejo& c)
{
    double re, im;
    c.ObtenerComplejo(re, im);
    std::cout << "(" << re << ", " << im << ")" << std::endl; 
}