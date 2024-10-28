#include <iostream>
#include "matrizDouble2D.hpp"
#include "utilidades.hpp"


void ConstruirMatriz(MatrizDouble2D& m, int filas, int cols)
{
    m = MatrizDouble2D(filas, MatrizDouble1D(cols, 0));
}

void LeerMatriz(MatrizDouble2D& m)
{
    for (size_t fila = 0; fila < m.size(); fila++)
    {
        for (size_t col = 0; col < m[fila].size(); col++)
        {
            std::cout << "m[" << fila << "][" << col << "]= ";
            leerDouble(m[fila][col]); 
        }
        
    }
    
}

void LeerMatrizIt(MatrizDouble2D& m)
{
    MatrizDouble2D::iterator ifilas;
    MatrizDouble1D::iterator icols;
    size_t fila, col;

    for (fila = 0, ifilas = m.begin(); ifilas != m.end(); ifilas++, fila++)
    {
        for (col = 0, icols = (*ifilas).begin(); icols != (*ifilas).end(); icols++, col++)
        {
            std::cout << "m[" << fila << "][" << col << "]= ";
            leerDouble(m[fila][col]); 
        }
        
    }
    
}

void MostrarMatriz(MatrizDouble2D& m)
{
    for (size_t fila = 0; fila < m.size(); fila++)
    {
        for (size_t cols = 0; cols < m[fila].size(); cols++)
        {
            std::cout << m[fila][cols] << " ";
        }
        std::cout << std::endl;
    }    
}

void MostrarMatrizIt(MatrizDouble2D& m)
{
    MatrizDouble2D::iterator ifilas;
    MatrizDouble1D::iterator  icols;
    size_t fila, col;
    
    for (fila = 0, ifilas = m.begin(); ifilas != m.end(); ifilas++, fila++)
    {
        for (col = 0, icols = (*ifilas).begin(); icols != (*ifilas).end(); icols++, col++)
        {
            std::cout << "m[" << fila << "][" << col << "]= " << *icols << std::endl;
        }
        
    }
    
}

void MostrarMatrizC(MatrizDouble2D& m)
{
    int f = 0, c= 0;
    for (MatrizDouble1D fila: m)
    {
        for (double& e : fila)
        {
            std::cout << "m[" << f << "][" << c++ << "]= " << e << std::endl;
        }
        f++; c = 0;
    }
    
}

void LeerMatrizC(MatrizDouble2D& m)
{
    int f = 0, c= 0;
    for(MatrizDouble1D fila : m)
    {
        for (double& e : fila)
        {
            std::cout << "m[" << f << "][" << c++ << "]= ";
            leerDouble(e);
        }
        f++; c = 0;
    }
}


char si_no()
{
    char respuesta = 'n';
    do
    {
        std::cout << "s/n >> "; respuesta = tolower(std::cin.get());
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
    } while (respuesta != 's' && respuesta != 'n');
    return respuesta;
}

