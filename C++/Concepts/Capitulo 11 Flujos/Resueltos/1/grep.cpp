#include <iostream>
#include "cgrep.hpp"

int main(int argc, char* argv[])
{
    if(argc < 3)
        std::cout << "Sintaxis: grep " << "<cadena> " << "<archivo 1> <archivo 2> ...\n";
    else
    {
        for (int i = 2; i < argc; i++)
            CGrep::BuscarEnFich(argv[i], argv[1]);
    }
}