#include "complejos.hpp"
#include <iostream>


int main()
{
    CComplejo a(3.5, -0.7), b(2.0, 1.5), c(-1, 1), d;
    double mod = a.mod();
    double alfa = a.arg();

    a = -c;
    a += b;
    if(a != CComplejo(0.0)) c = b / a;
    d = po_bi(mod, alfa);
    d = tan(b);
    d = pow(a, b);
    std::cout << "d = " << d << std::endl;
    a = log(CComplejo(0,0));
}