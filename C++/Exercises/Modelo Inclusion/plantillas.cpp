#include "plantillas.hpp"

template<typename T> T menor(T a, T b)
{
    return (a < b) ? a : b;
}

template<typename T> std::vector<T> menor(std::vector<T> a, std::vector<T> b)
{
    return (a < b) ? a : b;
} 

double menor(double a, double b)
{
    return (a < b) ? a : b;
}

// Instanciaciones explícitas
template int menor<int>(int, int);  
template std::vector<double> menor<double>(std::vector<double>, std::vector<double>); 
template double menor(double,double);