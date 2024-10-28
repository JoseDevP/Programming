#include <iostream>
#include <string>
#include <fstream>

int main()
{
    //meter datos
    std::string nombreArchivo;
    std::cout << "Archivo: "; std::getline(std::cin, nombreArchivo);

    std::filebuf buf;
    buf.open(nombreArchivo, std::ios::out);

    std::ostream os(&buf);

    std::string linea;
    std::cout << "Linea: "; std::getline(std::cin, linea);

    os << linea << std::endl;

    buf.close();

    //importar datos
    buf.open(nombreArchivo,std::ios::in);

    std::istream is(&buf);
    
    std::getline(is,linea);

    std::cout << linea << std::endl;

    buf.close();
}