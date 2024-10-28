#include <iostream>
#include <fstream>
#include <string>
#include "persona.hpp"
#include "telefono.hpp"
#include "leerdatos.hpp"

int main()
{
    static const char* opciones[] =
    {
        "Nuevo archivo",
        "Abrir archivo",
        "Añadir registros",
        "Buscar un registro",
        "Buscar siguiente",
        "Modificar un registro",
        "Salir"
    };

    int nOpciones = sizeof(opciones) / sizeof(char*);

    std::string cadenabuscar, nombreArchivo, str;
    CTelefonos fs;
    CPersona reg;
    long nreg;
    bool salir = false;

    while (true)
    {
        str = "ninguno";
        if(fs.Modo() == 1)
            str = nombreArchivo + " abierto para leer y escribir";
        else if(fs.Modo() == 2)
            str = nombreArchivo + " abierto para añadir";
        std::cout << "\nArchivo actual: " << str;

        try
        {
            switch (menu(opciones,nOpciones))
            {
            case 1: // nuevo
                std::cout << "\nNombre del archivo: ";
                leerDato(nombreArchivo);
                fs.Nuevo(nombreArchivo);
                break;

            case 2: // abrir
                std::cout << "\nNombre del archivo: ";
                leerDato(nombreArchivo);
                fs.Abrir(nombreArchivo);
                break;

            case 3: // añadir
                fs.Agregar();
                break;

            case 4: // buscar
                std::cout << "Nombre total o parcial (entrar => siguiente): ";
                leerDato(cadenabuscar);
                nreg = fs.Buscar(cadenabuscar.c_str(), 1);
                if(nreg == -1)
                    std::cout << "busqueda fallida\n";
                else
                {
                    reg = fs.LeerReg(nreg);
                    std::cout << reg << std::endl;
                }
                break;

            case 5: // buscar sigfuiente
                nreg = fs.Buscar(cadenabuscar.c_str(),nreg + 1);
                if(nreg == -1)
                    std::cout << "busqueda fallida\n";
                else
                {
                    reg = fs.LeerReg(nreg);
                    std::cout << reg << std::endl;
                }
                break;

            case 6: // modificar
                fs.Modificar();
                break;
            case 7: // salir
                salir = true;
                break;
            }
        }
        catch(std::ios_base::failure& e)
        {
            std::cerr << e.what() << '\n';
        }
        if(salir) break;
         
    }
    
}