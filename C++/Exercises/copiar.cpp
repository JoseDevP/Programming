#include <iostream>
#include <fstream>
#include <string>

using namespace std::literals;

int main(int argc, char* argv[])
{
    std::fstream fuente, destino;

    try
    {
        if (argc != 3)
            throw std::string("Nrº incorreccto de argumentos.\n"s + "Formato fuente destino\n"s );
        
        fuente.open(argv[1], std::ios::in);
        if(!fuente)
            throw ("No se puede abrir el achivo" + std::string(argv[1])); 

        destino.open(argv[2], std::ios::out);
        if(!destino)
            throw ("No se puede abrir el achivo" + std::string(argv[2])); 

        char car;
        while (fuente.get(car))
            destino.put(car);
        if(!fuente.eof())
            throw std::string("Error al leer el archivo");
        else
            std::cout << "Se ha copiado 1 archivo\n";
    }
    catch(std::string& s)
    {
        std::cerr << s << '\n';
    }
    
    fuente.close();
    destino.close();
}

