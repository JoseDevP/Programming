#include <iostream>
#include "matrizDouble2D.hpp"
#include "utilidades.hpp"

int main()
{
    int opcion = 0;
    static const char* opciones[] = 
    {
        "Construir matriz", 
        "Leer matriz",
        "Mostrar matriz",
        "Finalizar"
    };

    const int num_opciones = sizeof(opciones) / sizeof(char *);
    enum op {Construir = 1, Leer, Mostrar, Finalizar};

    MatrizDouble2D m;
    int filas, cols;

    do
    {
        system("cls");
        opcion = CrearMenu(opciones, num_opciones);
        switch (opcion)
        {
        case Construir:
            if (!m.empty())
            {
                std::cout << "Ya existe una matriz. ¿Desea destruirla? ";
                if(si_no() == '\n') break;
            }
            do
            {
                std::cout << "Nº de filas de la matriz "; leerInt(filas);
            } while (filas < 1);
            do
            {
                std::cout << "Nº de columnas de la matriz "; leerInt(cols);
            } while (cols < 1);
            ConstruirMatriz(m, filas, cols);
            std::cout << "Matriz construida\n";
            system("pause");
            break;
        case Leer:
            if(m.empty())
                std::cout << "No existe una matriz\n";
            else    
                LeerMatrizC(m);
            system("pause");
            break;
        case Mostrar:
            if(m.empty())
                std::cout<< "No existe una matriz\n";
            else
                MostrarMatriz(m);
            system("pause");
            break;
        case Finalizar:
            break;
        }
    } while (opcion != Finalizar);
}