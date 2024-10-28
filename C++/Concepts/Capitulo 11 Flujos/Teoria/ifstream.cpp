#include <iostream>
#include <fstream>
#include <string>
#include <limits>

struct registro
{
    std::string nombre;
    int anyoNaci;
    std::string tefno;
};

void mostrarDatos(registro reg);

int main()
{
    registro reg;

    std::string nombreArchivo = "datos.dat";

    std::ifstream ifs(nombreArchivo);

    if(!ifs.good())
    {
        std::cout << "Error: no se puede abrir el archivo" << nombreArchivo 
        << " para escribir\n";
        return 0;
    }

    do
    {
        std::getline(ifs, reg.nombre);
        if(ifs.eof()) break;
        ifs >> reg.anyoNaci;
        ifs.ignore(); //eliminar \n
        std::getline(ifs, reg.tefno);
        mostrarDatos(reg); std::cout << std::endl;
    } while (true);

    ifs.close();
}

void mostrarDatos(registro reg)
{
    std::cout << "Nombre:   " << reg.nombre << std::endl;
    std::cout << "Año:      " << reg.anyoNaci << std::endl;
    std::cout << "Teléfono: " << reg.tefno << std::endl;
}