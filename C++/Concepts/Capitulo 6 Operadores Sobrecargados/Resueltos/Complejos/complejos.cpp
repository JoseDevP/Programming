#include <iostream>
#include <cmath>
#include "complejos.hpp"

//Mensajes de error
static const char* MensajeError[] = { "division por cero", "log(0)", "en pow(z, e), z = 0" };

//Manipualcion de error
void CComplejo::error(const char* mensaje)
{
    std::cout << "\aerror: " << mensaje << std::endl;
    exit(1);
}

CComplejo po_bi(const double mod, double alfa)
{
    return CComplejo(mod * cos(alfa), mod * sin(alfa) ); 
}

//Aritmeticas

CComplejo operator+(const CComplejo& x, const CComplejo& y)
{
    return CComplejo(x.real + y.real, x.imag + y.imag );
}

CComplejo operator-(const CComplejo& x, const CComplejo& y)
{
    return CComplejo(x.real - y.real, x.imag - y.imag );
}

CComplejo operator*(const CComplejo& x, const CComplejo& y)
{
    return CComplejo(x.real * y.real -x.imag * y.imag, x.real * y.imag + x.imag *y.real);
}

CComplejo operator/(const CComplejo& x, const CComplejo& y)
{
    double r = 0, i = 0, divisor = y.norm();
    if( divisor != 0)
    {
        r = (x.real * y.real + x.imag * y.imag) / divisor;
        i = (x.imag * y.real - x.real * y.imag) / divisor;

    }
    else
        CComplejo::error(MensajeError[0]);
    return CComplejo(r, i);
}

//Comparaciones
bool operator==(const CComplejo& x, const CComplejo& y)
{
    return (x.real == y.real ) && (x.imag == y.imag);
}

bool operator!=(const CComplejo& x, const CComplejo& y)
{
    return !(x == y);
}

bool operator<(const CComplejo& x, const CComplejo& y)
{
    return x.mod() < y.mod();
}

bool operator<=(const CComplejo& x, const CComplejo& y)
{
    return x.mod() <= y.mod();
}

bool operator>(const CComplejo& x, const CComplejo& y)
{
    return x.mod() > y.mod();
}

bool operator>=(const CComplejo& x, const CComplejo& y)
{
    return x.mod() >= y.mod();
}

//Operaciones trigonometricas
CComplejo cos(const CComplejo& c)
{
    return CComplejo(cos(c.real) * cosh(c.imag), -sin(c.real) * sinh(c.imag));
} 

CComplejo sin(const CComplejo& c)
{
    return CComplejo(sin(c.real) * cosh(c.imag), cos(c.real) * sinh(c.imag));
} 

CComplejo tan(const CComplejo& c)
{
    return sin(c) / cos(c);
}

CComplejo cosh(const CComplejo& c)
{
    return CComplejo(cosh(c.real) * cos(c.imag), sinh(c.real) * sin(c.imag));
} 

CComplejo sinh(const CComplejo& c)
{
    return CComplejo(sinh(c.real) * cos(c.imag), cosh(c.real) * sin(c.imag));
} 

CComplejo tanh(const CComplejo& c)
{
    return sinh(c) / cosh(c);
}

//Operaciones logaritmicas
CComplejo exp(const CComplejo& c)
{
    double m = exp(c.real);
    return CComplejo(m *cos(c.imag), m *sin(c.imag));
}
 
CComplejo log(const CComplejo& c)
{
    double m = c.mod();
    if ( m == 0)    CComplejo::error(MensajeError[1]);
    return CComplejo(log(m), c.arg());
}

//Potencia
CComplejo pow(const CComplejo& c, const CComplejo& e)
{
    if(e.real == 0 && e.imag == 0)
        return CComplejo(1, 0);
    else
        if(c.real == 0 && c.imag == 0)
            CComplejo::error(MensajeError[2]);
    return exp(log(c) * e);
}

CComplejo sqrt(const CComplejo& c)
{
    return pow(c, CComplejo(0.5, 0.0));
}

//Visualizar un complejo
std::ostream& operator<<(std::ostream& os, CComplejo& c)
{
    return os << "(" << c.ParteReal() << "," << c.ParteImag() << ")"; 
}

std::istream& operator>>(std::istream& is, CComplejo& c)
{
    double re = 0, im = 0;
    char car = '\0';

    std::cout << "(real, imag): ";
    is >> car;
    if (car == '(')
    {
        is >> re >> car;
        if(car == ',') is >> im >> car;
        if(car != ')') is.clear(std::ios::badbit);
    }
    else
    {
        is.putback(car);
        is >> re;
    }
    if(is) c = CComplejo(re, im);
    return is;
}

