/*
    Realizar un programa que permita sumar, restar, multiplicar, dividir complejos 
    utilizando los operadores + - * / y asi calcular el argumentyo y el modulo de un 
    complejo

    Suma-> (a, b) + (c, d) = (a + c, b + d) 
    Resta-> (a, b) - (c, d) = (a - c, b - d) 
    Multiplicacion-> (a, b) * (c, d) = (ac - bd, ad + bc)
    Division-> (a, b) / (c, d) = ((ac + bd) / (c^2 + d^2), (bc - ad) / (c^2 + d^2))

    Dado el complejo (a,b) el numero positivo m= sqrt(a^2 + b^2) se denomina modulo 
    o valor absoluto y el angulo a = arc tg(b / a) recibe el nombre de argumento.

*/
#include <iostream>
#include <cmath>

struct complejo
{
    double real, imag;
};

complejo operator+(complejo& a, complejo& b)
{
    complejo temp;
    temp.real = a.real + b.real;
    temp.imag = a.imag + b.imag;
    return temp;
}

complejo operator-(complejo& a, complejo& b)
{
    complejo temp;
    temp.real = a.real - b.real;
    temp.imag = a.imag - b.imag;
    return temp;
}

complejo operator*(complejo& a, complejo& b)
{
    complejo temp;
    temp.real = (a.real * b.real) - (a.imag * b.imag);
    temp.imag = (a.real * b.imag) + (a.imag * b.real);
    return temp;
}

complejo operator/(complejo& a, complejo& b)
{
    complejo temp;
    temp.real = ((a.real * b.real) + (a.imag * b.imag)) / ((b.real * b.real) + (b.imag * b.imag));
    temp.imag = ((a.imag * b.real) - (a.real * b.imag)) / ((b.real * b.real) + (b.imag * b.imag));
    return temp;
}

double moduloComplejo(complejo& a)
{
    return std::sqrt( (a.real * a.real) + (a.imag * a.imag));
}

double argumentoComplejo(complejo& a)
{
    return std::atan2(a.imag, a.real);
}

int main(void)
{
    complejo a, b;
    std::cout << "Introduce el numero real del complejo 1: "; std::cin >> a.real;
    std::cout << "Introduce el numero Imaginario del complejo 1: "; std::cin >> a.imag;
    std::cout << "Introduce el numero real del complejo 2: "; std::cin >> b.real;
    std::cout << "Introduce el numero Imaginario del complejo 2: "; std::cin >> b.imag;

    std::cout << "Suma-> a + b = " << (a+b).real << " + " << (a+b).imag << "i" << std::endl;
    std::cout << "Resta-> a - b = " << (a-b).real << " + " << (a-b).imag << "i" << std::endl;
    std::cout << "Multiplicación-> a * b = " << (a*b).real << " + " << (a*b).imag << "i" << std::endl;
    std::cout << "Division-> a / b = " << (a/b).real << " + " << (a/b).imag << "i" << std::endl;


    std::cout << "Modulo complejo 1-> " << moduloComplejo(a) << std::endl;
    std::cout << "Modulo complejo 2-> " << moduloComplejo(b) << std::endl;
    std::cout << "\n\n";
    std::cout << "Argumento complejo 1-> " << argumentoComplejo(a) << std::endl;
    std::cout << "Argumento complejo 2-> " << argumentoComplejo(b) << std::endl;


}
