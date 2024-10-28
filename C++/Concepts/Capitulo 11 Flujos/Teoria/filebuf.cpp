#include <iostream>
#include <fstream>

int main()
{
    char nombreArchivo[30];
    std::filebuf buf; 

    std::cout << "Archivo: "; std::cin >> nombreArchivo;
    if(buf.open(nombreArchivo, std::ios::out) == 0)
    {
        std::cerr << "Error: no se puede abrir el archivo";
        return -1;
    }

    std::cout << "El archivo " << nombreArchivo;
    buf.is_open() ? std::cout << " esta abierto\n" : std::cout << " esta cerrado\n";
    buf.close();
}