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

void leerDatos(registro reg[], int n);

int main()
{
    const int n = 2;
    registro reg[n];

    leerDatos(reg, n);

    std::string nombreArchivo = "datos.dat";

    std::ofstream ofs(nombreArchivo);

    if(!ofs.good())
    {
        std::cout << "Error: no se puede abrir el archivo" << nombreArchivo 
        << " para escribir\n";
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        ofs << reg[i].nombre << std::endl;
        ofs << reg[i].anyoNaci << std::endl;
        ofs << reg[i].tefno << std::endl;
    }

    ofs.close();
}

void leerDatos(registro reg[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << "Nombre:   "; std::getline(std::cin, reg[i].nombre);
        std::cout << "Año:      "; std::cin >> reg[i].anyoNaci;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Teléfono: "; std::getline(std::cin, reg[i].tefno);
    }
}