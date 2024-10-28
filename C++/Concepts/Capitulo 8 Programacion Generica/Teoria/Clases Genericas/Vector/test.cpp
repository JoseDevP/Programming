#include <iostream>
#include <iomanip>
#include <string>
#include "vector.hpp"

template<typename T> void visualizar(const CVector<T>&);

int main()
{
    CVector<double> vector(5);
    vector = 0;
    visualizar(vector);

    for (int i = 0; i < vector.longitud(); i++)
        vector[i] = i + 1;
    visualizar(vector);
}

template<typename T> void visualizar(const CVector<T>& v)
{
    int ne = v.longitud();
    for(int i = 0; i < ne; i++)
        std::cout << std::setw(7) << v[i];
    std::cout << "\n\n";
}