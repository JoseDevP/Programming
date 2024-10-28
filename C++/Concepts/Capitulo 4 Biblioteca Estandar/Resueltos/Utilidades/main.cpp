#include <iostream>
#include "utilidades.hpp"

int main()
{
    int i = 0;
    double d = 0.0;
    char cad[40];
    bool b = true;

    int opcion = 0;
    static const char* opciones[] = 
    {
        "Leer un int", 
        "Leer un double",
        "Leer una cadena",
        "Finalizar"
    };

    const int num_opciones = sizeof(opciones) / sizeof(char *);
    enum op {LeerInt = 1, LeerDouble, LeerCadena, Finalizar};

    do
    {
        system("cls");
        opcion = CrearMenu(opciones, num_opciones);
        switch (opcion)
        {
        case LeerInt:
            if(leerInt(i))
                std::cout << i << std::endl;
            else
                std::cout << "eof\n";
                system("pause");
                break;
            break;
        case LeerDouble:
            if(leerDouble(d))
                std::cout << d << std::endl;
            else
                std::cout << "eof\n";
                system("pause");
                break;
            break;
        case LeerCadena:
            if(leerCadena(cad,sizeof(cad)))
                std::cout << cad << std::endl;
            else
                std::cout << "eof\n";
                system("pause");
                break;
            break;
            break;
        case Finalizar:
            break;
        }
    } while (opcion != Finalizar);
    
}