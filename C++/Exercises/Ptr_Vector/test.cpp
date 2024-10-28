#include <iostream>
#include "cvector.hpp"
#include "ptr_vector.hpp"
#include "iniciar.hpp"

void visualizar(CVector& v)
{
    for (int f = 0; f < v.longitud(); f++)
    {
        std::cout << v[f] << " ";
    }
    std::cout << std::endl;
} 

int main()
{
    CIniciar iniciar;

    Ptr_CVector vector(5);
    for (int i = 0; i < vector->nElementos; i++)
    {
        vector[i] = new CVector (i + 1);
        iniciar.valor(i);
        iniciar(*vector[i]);
        visualizar(*vector[i]);
    }
    
    for (int i = 0; i < vector->nElementos; i++)
        delete vector[i];
    
}