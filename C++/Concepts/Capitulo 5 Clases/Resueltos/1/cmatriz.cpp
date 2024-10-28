#include <iostream>
#include "cmatriz.hpp"

void CMatriz::construir(int n, int* dim)
{
    int i;
    for (int i = 0; i < n; i++)
        if(dim[i] < 1)
        {
            std::cerr << "Dimension nula o negativa\n";
            exit(-1);
        }
    nDims = n;
    dimsMatriz = new int[nDims];
    for (int i = 0; i < n; i++) dimsMatriz[i] = dim[i];
    matriz = new double[totalElementos()]; 
}

CMatriz::CMatriz(int d1, int d2, int d3)
{
    int nDi=0;
    if(d3) nDi = 3; else if(d2) nDi = 2; else if(d1) nDi = 1;
    int dim[] = {d1, d2 ,d3};
    construir(nDi, dim);
}

CMatriz::~CMatriz()
{
    delete[] matriz;
    delete[] dimsMatriz;
}

int CMatriz::totalElementos() const
{
    int i;
    int nTElementos = 1;
    for ( i = 0; i < nDims; i++)
        nTElementos *= dimsMatriz[i];
    return nTElementos;
}

int CMatriz::desplazamiento(int* subind) const
{
    int i;
    int desplazamiento = 0;

    for ( i = 0; i < nDims; i++)
    {
        if(subind[i] < 0 || subind[i] >= dimsMatriz[i])
        {
            std::cout << "Subindice fuera de rango\n";
            return -1;
        }

        desplazamiento += subind[i];
        if(i+1 < nDims)
            desplazamiento *= dimsMatriz[i+1];
    }
    return desplazamiento;
}

void CMatriz::asignarDato(int d, int i1, int i2, int i3)
{
    int subind[] = { i1, i2, i3};
    int i = desplazamiento(subind);
    if(i == -1) exit(-1); //fuera de ranngo
    matriz[i] = d;
}

double CMatriz::obtenerDato(int i1 , int i2, int i3 ) const
{
    int subind[] = { i1, i2, i3};
    int i = desplazamiento(subind);
    if(i == -1) exit(-1); //fuera de ranngo
    return matriz[i];
}


