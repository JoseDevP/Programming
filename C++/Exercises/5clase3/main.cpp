#include <iostream>
#include "cmatriz.hpp"

int main(void)
{
    const int A = 5;
    const int B = 10;

    int conta = 1;
    CMatriz a(A,B);
    for (int i = 0; i < A; i++)
        for (int j = 0; j < B; j++)
            a.asignarDato(conta++,i,j);

    for (int i = 0; i < A; i++)
        for (int j = 0; j < B; j++)
            std::cout << (a.obtenerDato(i, j)) << " ";
    std::cout << std::endl;
}