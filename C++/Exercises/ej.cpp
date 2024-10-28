#include <iostream>
#include <stdexcept>
#include <cmath>

double dividir(double a, double b)
{
    if(b == 0)
        throw std::invalid_argument ("divisor entre 0");
    return a / b;
}

double raiz_cuadrada(double a)
{
    if( a < 0 )
        throw std::domain_error ("sqrt: argumento negativo");
    return sqrt(a);
}

int main()
{
    double a, b, c;
    std::cout << "Valores de a y b: ";
    std::cin >> a >> b;
    try
    {
        c = a / b;
        c = dividir(a, b);
        b= sqrt(a);
        b = raiz_cuadrada(a);
    }
    catch (std::invalid_argument exc)
    {
        std::cout << exc.what() << std::endl;
    }
    catch(std::domain_error exc)
    {
        std::cout << exc.what() << std::endl;
    }
    catch(std::exception exc)
    {
        std::cout << exc.what() << std::endl;
    }
    
}