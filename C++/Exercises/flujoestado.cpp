#include <iostream>

int main()
{
    int n = 0, estado = 0;

    std::cout << "Dato (entero, cadena, Ctrl+z, etc.): ";
    std::cin >> n;

    //metodo 1
    if( std::cin.good() )
        std::cout << "correcto\n";
    else if ( std::cin.eof() )
        std::cout << "\nfin de la entrada\n";
    else if ( std::cin.fail())
        std::cerr << '\a' << "\ndato incorrecto\n"; 
    else if ( std::cin.bad() )
        std::cerr << '\a' << "\error fatal\n";


    n = 0; estado = 0;
    std::cout << "Dato (entero, cadena, Ctrl+z, etc.): ";
    std::cin >> n;

    //metodo 2
    estado = std::cin.rdstate();
    if( estado == std::ios::goodbit )
        std::cout << "correcto\n";
    else if ( (estado & std::ios::eofbit) == std::ios::eofbit )
        std::cout << "\nfin de la entrada\n";
    else if ( (estado & std::ios::failbit) == std::ios::failbit )
        std::cerr << '\a' << "\ndato incorrecto\n"; 
    else if ( (estado & std::ios::badbit) == std::ios::badbit ) 
        std::cerr << '\a' << "\error fatal\n";

}