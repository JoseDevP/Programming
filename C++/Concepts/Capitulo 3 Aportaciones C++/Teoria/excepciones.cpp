#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>

void incrementarContador(std::vector<int>& v, char& c)
{
    v.at(c-'a')++;
}

int main()
{
    const int N_ELEMENTOS = 'z' - 'a' + 1;
    std::vector<int> c(N_ELEMENTOS);
    char car;

    std::cout << "Introducir texto.\n";
    std::cout << "Para finalizar introducir la mara EOF\n\n";
    while (std::cin.get(car), !std::cin.eof())
    {
        try
        {
            incrementarContador(c, car);
        }
        catch(std::out_of_range)
        {
            std::cerr << "error de rango producido por el caracter de "
                      << "valor ASCII " << static_cast<int>(car) << std::endl
                      << "Para finalizar introducir la marca eof\n\n";
        }
    }
    
    for (car = 'a'; car <= 'z'; car++)
        std::cout << "  " << car;
    std::cout << "\n ----------------------------------------------------"
              "----------------------------------------------\n";
    for (car = 'a'; car <= 'z'; car++)
        std::cout << std::setw(3) << c[car - 'a'];
     
    
}