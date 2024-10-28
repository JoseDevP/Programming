#include <iostream>
#include <string>
#include <fstream>

int main()
{
    //meter datos
    std::string nombreArchivo;
    std::cout << "Archivo: "; std::getline(std::cin, nombreArchivo);

    std::ofstream ofs(nombreArchivo + ".bin",std::ios::out|std::ios::binary);

    if(!ofs.good())
    {
        std::cout << "Error: no se puede abrir el archivo\n";
        return -1;
    }
    
    std::string linea;
    std::cout << "Linea: "; std::getline(std::cin, linea);

    ofs.write(linea.c_str(), linea.size());
    ofs.close();

    //obtener datos
    std::ifstream ifs(nombreArchivo + ".bin",std::ios::in|std::ios::binary);

    if(!ifs.good())
    {
        std::cout << "Error: no se puede abrir el archivo\n";
        return -1;
    }

    std::string contenido(linea.size(), '\0');
    
    ifs.read(&contenido[0], linea.size());

    std::cout << contenido << std::endl;

    ifs.close();
}
