#if !defined(_LEER_DATOS_HPP_)
#define _LEER_DATOS_HPP_

#include <iostream>
#include <string>
#include <limits>

template<typename T> bool leerDato(T& dato)
{
    std::cin.exceptions(std::ios::failbit | std::ios::badbit);

    try
    {
        std::cin >> dato;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.exceptions(std::ios::goodbit);
        return true;
    }
    catch(std::ios_base::failure& e)
    {
        //eof o fallo
        if(std::cin.eof())
        {
            std::cin.clear();
            std::cin.exceptions(std::ios::goodbit);
            return false;
        }
        else
        {
            std::cerr << e.what() << ": entrada invalida" << '\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.exceptions(std::ios::goodbit);
            return leerDato(dato);
        } 
    }
    
}

bool leerDato(std::string& dato)
{
    std::cin.exceptions(std::ios::failbit | std::ios::badbit);

    try
    {
        std::getline(std::cin, dato);
        std::cin.exceptions(std::ios::goodbit);
        return true;
    }
    catch(std::ios_base::failure& e)
    {
        //eof o fallo
        if(std::cin.eof())
        {
            std::cin.clear();
            std::cin.exceptions(std::ios::goodbit);
            return false;
        }
        else
        {
            std::cerr << e.what() << ": entrada invalida" << '\n';
            std::cin.clear();
            std::cin.exceptions(std::ios::goodbit);
            return leerDato(dato);
        } 
    }
}

int menu(const char* opciones[], int nOpciones)
{
    int i = 0;
    int opcion = -1;

    for (int i = 0; i < nOpciones; i++)
        std::cout << i+1 << ". " << opciones[i] << std::endl;

    do
    {
        std::cout << "opcion->  ";
        leerDato(opcion);
        if(opcion < 1  || opcion > nOpciones)
            std::cout << "Opcion fuera de rango\n";
    } while ( opcion < 1  || opcion > nOpciones);
     
    return opcion; 
}

#endif