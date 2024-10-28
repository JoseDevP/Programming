#include <iostream>
#include <vector>

//plantilla general
template<typename T> T menor(T a, T b)
{
    std::cout << "General" << std::endl;
    return (a < b) ? a : b;
}

//sobrecagarga. Especialiacion parcial
template<typename T> std::vector<T> menor(std::vector<T> a, std::vector<T> b)
{
    std::cout << "Parcial" << std::endl;
    return (a < b) ? a : b;
}

//Funcion
double menor(double a, double b)
{
    std::cout << "Funcion" << std::endl;
    return (a < b) ? a : b;
}

//Especializacion explicita
template<> std::vector<double> menor<double>(std::vector<double> a, std::vector<double> b)
{
    std::cout << "Explicita" << std::endl;
    return (a < b) ? a : b;
}

int main()
{
    std::vector<double> v1(10), v2(8), vd;

    vd = menor<double>(v1,v2); //explicita
    
    vd = menor<std::vector<double>>(v1, v2); //general

    vd = menor(v1, v2); //explicita

    double result = menor(3.5, 2.5); //funcion

    std::vector<int> v3(10), v4(8), vi;

    vi = menor(v3, v4); //parcial
}