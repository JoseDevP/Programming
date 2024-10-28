#if !defined (_CGREP_HPP_)
#define _CGREP_HPP_

#include<iostream>
#include <cstring>
#include <fstream>

class CGrep
{
    private:
        static bool Existe(char* nombf);
    public:
        static bool BuscarCadena(char* c1, char* c2);
        static void BuscarEnFich(char* f1, char* cad);
};

bool CGrep::BuscarCadena(char* cadena1, char* cadena2)
{
    return strstr(cadena1, cadena2) != nullptr;
}

void CGrep::BuscarEnFich(char* nomf, char* cadena)
{
    std::fstream fs;

    if(strlen(nomf) == 0)
    {
        std::cout << "Especificar un nombre para el archivo.\n";
        return;
    }

    if(!Existe(nomf))
    {
        std::cout << "El archivo " << nomf << " no existe.\n";
        return;
    }

    fs.open(nomf, std::ios::in);

    char linea[100];
    int nroLinea = 0;

    fs.getline(linea, 100);

    while (!fs.eof())
    {
        nroLinea++;
        if(BuscarCadena(linea, cadena))
            std::cout << nomf << " " << nroLinea << " " << linea << std::endl;
        fs.getline(linea, 100);
    }
    
    fs.close();
}

bool CGrep::Existe(char* nomf)
{
    std::fstream fs;

    fs.open(nomf, std::ios::in);

    if(fs.fail())
    {
        fs.clear();
        return false;
    }
    fs.close();
    return true;
}

#endif