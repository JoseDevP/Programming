#include <iostream>
#include "matrizBidimensional.hpp"

using namespace std;


void DestruirMatriz(matriz2d& m)
{
    if(m.p == nullptr)  return;
    for (size_t i = 0; i < m.filas; i++)
        delete[] m.p[i];
    delete[] m.p;
    m.p=nullptr;
}

bool ConstruirMatriz(matriz2d& m)
{
    m.p = (double **) new (nothrow) double*[m.filas]; 
    if(m.p == nullptr) return false;
    fill(m.p, m.p + m.filas, nullptr);

    for (int i = 0; i < m.filas; i++)
    {
        m.p[i] = (double *) new (nothrow) double[m.cols];
        if(m.p[i] == nullptr)
        {
            DestruirMatriz(m);
            return false;
        }
        fill(m.p[i] , m.p[i] + m.cols, 0);
    }
    return true;
}

void LeerMatriz(matriz2d& m)
{
    if(m.p == nullptr)  return;
    for (size_t i = 0; i < m.filas; i++)
    {
        for (size_t j = 0; j < m.cols; j++)
        {
            cout << "matriz[" << i << "] [" << j << "]:  ";
            cin >> m.p[i][j];
        }
        
    }
    
}

void MostrarMatriz(matriz2d& m)
{
    if(m.p == nullptr)  return;
    for (size_t i = 0; i < m.filas; i++)
    {
        for (size_t j = 0; j < m.cols; j++)
        {
            cout << m.p[i][j] << " ";
        }
        cout << endl;
    }
}

int CrearMenu(const char * opMenu[], int num_opciones)
{
    int opcion;
    system("cls");
    cout << "\nElija una opción:\n" << endl;
    for (int i = 0; i < num_opciones; i++)
        cout << "\t" << i + 1 << ". "  << opMenu[i] << endl;

    do
    {
        cout << ">> "; cin >> opcion;
        if(opcion < 1 || opcion > num_opciones)
            cout << "Opcion Incorrecta\n" << endl; 
    } while (opcion < 1 || opcion > num_opciones);
    
    return opcion;
}

