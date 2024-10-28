#include <iostream>
#include "racionales.hpp"

CRacional::CRacional(long num, long den ): numerador(num), denominador(den)
{
    if(den == 0) { throw "El denominador no puede ser 0"; };
    if(den < 0)
    {
        numerador = -numerador;
        denominador = -denominador;
    }
    Simplificar();
}

//Operador de conversion
CRacional::operator double()
{
    return static_cast<double>(numerador)/denominador;
}

CRacional::operator CComplejo()
{
    return CComplejo( static_cast<double>(numerador)/denominador );
}

//Asignacion
CRacional& CRacional::operator=(const CRacional& c)
{
    if(this == &c) return *this;
    numerador = c.numerador;
    denominador = c.denominador;
    return *this;
}

CRacional& CRacional::operator+=(const CRacional& r)
{
    numerador = numerador * r.denominador + denominador * r.numerador;
    denominador = denominador * r.denominador;
    return (*this).Simplificar();
}

CRacional& CRacional::operator-=(const CRacional& r)
{
    numerador = numerador * r.denominador - denominador * r.numerador;
    denominador = denominador * r.denominador;
    return (*this).Simplificar(); 
}


//Aritmeticos

//Suma
CRacional CRacional::operator+()
{
    CRacional temp{+numerador, denominador};
    return temp;
}

CRacional  CRacional::operator+(const CRacional& r)
{
    return CRacional{numerador * r.denominador + denominador * r.numerador,
    denominador * r.denominador};
}
//obligar a declarar explicitamente complejos
//int + CRacional es posible ya que aqui int se podria convertir en r1
const CRacional operator+(const CRacional& r1, const CRacional& r2)
{
    CRacional temp(r1);
    return temp += r2;
}

//si no puede convertir hay que redefinir ej:double
const CRacional operator+(const double d, const CRacional& r)
{
    CRacional temp{ static_cast<long>(d)};
    return temp += r;
}

//Resta
CRacional CRacional::operator-()
{
    CRacional temp{-numerador, denominador};
    return temp;
}

CRacional  CRacional::operator-(const CRacional& r)
{
    return CRacional{numerador * r.denominador - denominador * r.numerador,
    denominador * r.denominador};
}

const CRacional operator-(const CRacional& r1, const CRacional& r2)
{
    CRacional temp(r1);
    return temp -= r2;
}

const CRacional operator-(const double d, const CRacional& r)
{
    CRacional temp{ static_cast<long>(d)};
    return temp -= r;
}

//Relacion

const bool CRacional::operator==(const CRacional& r)
{
    return numerador * r.denominador == denominador * r.numerador;
}


const bool operator==(const CRacional& r1, const CRacional& r2)
{
    return r1.numerador * r2.denominador == r1.denominador * r2.numerador;
}

const bool operator==(const double d, const CRacional& r2)
{
    CRacional temp(static_cast<long>(d));
    return temp.numerador * r2.denominador == temp.denominador * r2.numerador;
}

std::ostream& operator<<(std::ostream& os, const CRacional& r)
{
    return os << r.numerador << "/" << r.denominador;
}

//insertar racional
std::istream& operator>>(std::istream& is, CRacional& r)
{
    long num = 0, den = 1;
    char car = '\0';

    std::cout << "(entero/entero)  ";
    is >> num;
    while (is.fail())
    {
        is.clear();
        is.ignore(std::numeric_limits<size_t>::max(), '\n');
        std::cout << "(entero/entero)  ";
        is >> num;
    }
    if(is.peek() != '\n')
    {
        is >> car;
        if(car == '/')
            is >> den;
        else
            is.clear(std::ios::badbit);
    }
    if(is) r = CRacional(num, den);
    return is;
}

//Negacion
bool CRacional::operator!()
{
    return !numerador;
}


//PreIncremento y PostIncremento
CRacional& CRacional::operator++()
{
    numerador += denominador;
    return *this;
}
CRacional CRacional::operator++(int)
{
    CRacional temp{*this};
    numerador += denominador;
    return temp;
}


void Visualizar(const CRacional& r)
{
    std::cout << r.Numerador() << "/";
    std::cout << r.Denominador() << std::endl;
}

CRacional& CRacional::Simplificar()
{
    long mcd, temp, resto;
    mcd = labs(numerador);
    temp = denominador;

    while (temp > 0)
    {
        resto= mcd % temp;
        mcd = temp;
        temp = resto;
    }
    
    if(mcd > 1)
    {
        numerador /= mcd;
        denominador /= mcd;
    }
    return *this;
}
