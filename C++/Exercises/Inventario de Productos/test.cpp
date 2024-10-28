#include <iostream>
#include <string>
#include "inventario.hpp"
#include "producto.hpp"
#include "leerdatos.hpp"

const char* opciones[] =
{
    "Crear nuevo fichero",
    "Abrir fichero",
    "Añadir registros",
    "Buscar precio de un registro",
    "Modificar un registro",
    "Salir"
};

int nOpciones = sizeof(opciones) / sizeof(char*);

int main()
{
    Inventario inventario;
    std::string nombreArchivo;
    char referencia[30];
    double numero = 0;

    bool salir = false;
    do
    {
        std::cout << "-------INVENTARIO DE PRODUCTOS-------" << "\n\n";
        try
        {
            int op = -1;

            switch (op = menu(opciones, nOpciones))
            {
            case 1: // crear
                std::cout << "Introduce el nombre del fichero: ";
                leerDato(nombreArchivo);
                inventario.Nuevofichero(nombreArchivo);
                break;

            case 2: // abrir
                std::cout << "Introduce el nombre del fichero: ";
                leerDato(nombreArchivo);
                inventario.Abrirfichero(nombreArchivo);
                break;

            case 3: // añadir
                inventario.AñadirRegistros();
                break;

            case 4: // buscar
                std::cout << "Introduce la referencia del producto a buscar : ";
                leerDato(referencia);
                numero = inventario.BuscarRegistro(referencia);
                if(numero < 0) 
                    std::cout << "No encontrado" << std::endl;
                else
                    std::cout << "Encontrado.\n Precio: " << numero << std::endl;
                break;

            case 5: // modificar
                inventario.Modificar();
                break;

            case 6: // salir
                salir = true;
                break;
            }
        }
        catch(std::ios_base::failure& e )
        {
            std::cerr << e.what() << '\n';
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    } while (!salir);
    
}