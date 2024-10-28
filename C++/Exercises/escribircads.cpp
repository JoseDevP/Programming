#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::string nombreArchivo;

    std::cout << "Archivo: "; std::getline(std::cin, nombreArchivo);

    std::fstream ofs(nombreArchivo, std::ios::out);
    if(!ofs)
    {
        std::cerr << "Error: no se puede abrir el archivo\n";
        return -1;
    }

    std::string linea;
    std::cout << "Introducir cadenas de caracateres.\n" 
    << "para finalizar, pulse <Entrar> solo en una linea.\n\n";
    std::getline(std::cin, linea);

    while (!linea.empty())
    {
        ofs << linea << std::endl;
        std::getline(std::cin, linea);
    }
    

    ofs.close();
}