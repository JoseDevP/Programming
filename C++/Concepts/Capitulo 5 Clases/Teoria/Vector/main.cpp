#include <iostream>
#include <iomanip>
#include "pcvector.hpp"
#include "cvector.hpp"

void visualizar(CVector2D&);

int main()
{
    try
    {
        const int Filas = 2, Cols = 3;
        CVector2D m1(Filas, Cols);
        for (int f = 0; f < Filas; f++)
            for (int c = 0; c < Cols; c++)
                m1[f][c] = f + c + 1; 
        visualizar(m1); std::cout << std::endl;
        CVector2D m2(m1);
        m2[0][0] = 2;
        visualizar(m2); std::cout << std::endl;
        CVector2D m3;
        m3 = m2;
        m3[0][0] = 3;
        visualizar(m3); std::cout << std::endl;
    }
    catch(std::bad_alloc e)
    {
        std::cout << "Insuficiente espacio de memoria\n";
    }
}

void visualizar(CVector2D& v)
{
    for (int f = 0; f < v.numFilas(); f++)
    {
        for (int c = 0; c < v.numCols(); c++)
            std::cout << v[f][c] << " ";
        std::cout << std::endl;
    }
} 

