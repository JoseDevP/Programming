#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::string nombreArchivo;

    std::cout << "Archivo: "; std::getline(std::cin, nombreArchivo);

    std::fstream ifs(nombreArchivo, std::ios::in);
    if(!ifs)
    {
        std::cerr << "Error: no se puede abrir el archivo\n";
        return -1;
    }

    const int N = 80;
    char linea[80];
    int ncars = 0;

    do
    {
        ifs.getline(linea, N, '\n');
        if(ifs.eof()) break;
        std::cout << linea;

        //si no se encontro el delimitador se activo failbit
        if( (ncars = ifs.gcount()) == N -1) ifs.clear();

        //Si se encontro el delminatdor: \n ==>> \0
        if(linea[ncars - 1] == '\0') std::cout << std::endl;

    } while (true);

    if(!ifs.eof() && ifs.fail())
    {
        std::cerr << "Error al leer el archivo\n";
        ifs.clear();
    }

    ifs.close();
}