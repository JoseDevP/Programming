#if !defined (_PLANTILLAS_HPP)
#define _PLANTILLAS_HPP

#include <vector>

template<typename T> T menor(T a, T b);
template<typename T> std::vector<T> menor(std::vector<T> a, std::vector<T> b);
double menor(double a, double b);


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

#endif