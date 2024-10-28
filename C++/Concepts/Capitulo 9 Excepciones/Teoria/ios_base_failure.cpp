#include <iostream>
#include <limits>

double leerDouble()
{
    double datos = 0.0;
    std::cin.exceptions(std::ios::failbit | std::ios::badbit);

    try
    {
        std::cin >> datos;
    }
    catch(std::ios_base::failure& e)
    {
        std::cerr << e.what() << '\n';
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        datos = leerDouble();
    }
    
    std::cin.exceptions(std::ios::goodbit);
    return datos;
}


int main()
{
    
}