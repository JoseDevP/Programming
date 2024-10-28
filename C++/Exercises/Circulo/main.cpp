#include <iostream>
#include "circulo.hpp"

int main()
{
    double x = 100, y = 120, r = -10;
    Circulo c{ x, y, r };
    std::cout << c.areaCirculo() << std::endl;
    c.coordenadaCentro(x, y);
    std::cout << "x = " << x << ", y = " << y << std::endl;
}