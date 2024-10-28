#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
    std::fstream ifs;
    try
    {
        if(argc != 2) throw "Nro incorrecto de argumentos";

        ifs.open(argv[1], std::ios::in);
        if(!ifs)
            throw "No se puede abrir el archivo";

        char car;
        while ( ifs.get(car) ) std::cout << car;
        if ( !ifs.eof() ) throw "Error al leer el archivo";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}