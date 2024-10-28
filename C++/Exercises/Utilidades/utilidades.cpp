#include <iostream>
#include <limits>
#include "utilidades.hpp"

bool leerDouble(double& dato)
{
    bool eof = false, fail = false;
    
    do
    {
        std::cout << ">> "; std::cin >> dato;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        fail = std::cin.fail(); eof = std::cin.eof();
        if(eof)
        {
            std::cin.clear();
            return false;
        }
        if(fail)
        {
            std::cout << "error: dato no valido\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (fail);   
    return true;
}

bool leerInt(int& dato)
{
    bool fail=false, eof=false;

    do
    {
        std::cout << ">> "; std::cin >> dato;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        fail = std::cin.fail(); eof = std::cin.eof();
        if(eof)
        {
            std::cin.clear();
            return false;
        }
        if(fail)
        {
            std::cout << "error: dato no valido\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (fail);
    return true;
    
}

bool leerCadena(char* dato, int n)
{
    bool fail=false, eof=false;

    do
    {
        std::cout << ">> "; std::cin.getline(dato,n,'\n');
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        fail = std::cin.fail(); eof = std::cin.eof();
        if(eof)
        {
            std::cin.clear();
            return false;
        }
        if(fail)
        {
            std::cout << "error: dato no valido\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (fail);
    return true;
    
}

int CrearMenu(const char* OpMenu[], int num_opciones)
{
    int opcion;
    system("cls");
    std::cout << "Elija la opcion:\n" << std::endl;
    for (int i = 0; i < num_opciones; i++)
        std::cout << "\t" << i+1 << ". " << OpMenu[i] << std::endl;
    
    do
    {
        leerInt(opcion);
        if(opcion < 1 || opcion > num_opciones)
            std::cout << "Opcion Incorrecta\n" << std::endl;
    } while (opcion < 1 || opcion > num_opciones);
    return opcion;
}






