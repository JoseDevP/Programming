#include <iostream>
#include <limits>

int main()
{
    double notas[7] = {0};
    int i = 0;
    std::cout << "Introduce notas. Finalice con eof.\n\n";
    do
    {
        std::cout << "Nota [" << i << "]: ";
        std::cin >> notas[i++];
        if(!std::cin.eof() &&  std::cin.fail())
        {
            std::cerr << '\a' << "\ndato incorrecto\n";
            std::cin.clear();
            //std::cin.ignore(std::numeric_limits<int>::max(),'\n');
            std::cin.ignore(std::cin.rdbuf()->in_avail());
            i--;
        }
    } while (!std::cin.eof() && !std::cin.bad() && i<7);
    
}
