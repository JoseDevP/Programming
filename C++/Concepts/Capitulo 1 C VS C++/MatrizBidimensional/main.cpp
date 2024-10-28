#include <iostream>
#include "matrizBidimensional.hpp"

using namespace std;

int main()
{
    int opcion =0;
    static const char* opciones[]=
    {
        "Construir Matriz",
        "Leer Matriz",
        "Mostrar Matriz",
        "Destruir Matriz",
        "Finalizar",
    };

    const int num_opciones = sizeof(opciones)/sizeof(char *);

    matriz2d m{nullptr,0,0};

    enum op {Construir = 1, Leer, Mostrar, Destruir, Finalizar};
    do
    {
        system("cls");
        opcion = CrearMenu(opciones,num_opciones);
        switch (opcion)
        {
        case Construir:
            if(m.p != nullptr)
            {
                cout << "Ya existe una matriz. Destruyela para crear otrra.\n";
                system("pause");
                break;
            }
            do
            {
                cout << "Nº de filas de la matriz:  "; cin >> m.filas;
            } while (m.filas < 1);
            do
            {
                cout << "Nº de columnas de la matriz:  "; cin >> m.cols;
            } while (m.cols < 1);
            if(!ConstruirMatriz(m))
            {
                cout << "No se pudo construir la matriz\n";
                return -1;
            }
            cout << "Matriz construida\n";
            system("pause");
            break;
        case Leer:
            if(m.p == nullptr)
                cout << "No existe una matriz\n";
            else    
                LeerMatriz(m);
            system("pause");
            break;
        case Mostrar:
            if(m.p == nullptr)
                cout << "No existe una matriz\n";
            else    
                MostrarMatriz(m);
            system("pause");
            break;
        case Destruir:
            if(m.p == nullptr)
                cout << "No existe una matriz\n";
            else    
                DestruirMatriz(m);
            system("pause");
            break;
        case Finalizar:
            if(m.p != nullptr) DestruirMatriz(m);
            break;
        }
    } while (opcion != Finalizar);
    
    
}