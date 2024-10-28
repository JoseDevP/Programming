#include <iostream>
#include <limits>

int main()
{
    const int LONG_CAD = 80;
    const int NUM_CAD = 10;
    char nombres[NUM_CAD][LONG_CAD];
    int i = 0;

    std::cout << "Introducir nombres. Finalizar cada linea con <Enter>.\n"
              << "Eof + <Enter> para finalizar.\n\n";

    do
    {
        std::cout << "nombre[" << i << "] = ";
        std::cin.getline(nombres[i],LONG_CAD,'\n');

        if(strlen(nombres[i]) == LONG_CAD-1)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
        } 
        i++;
    } while (!std::cin.eof() && !std::cin.bad() && i < NUM_CAD);
    
    if(std::cin.bad())
    {
        std::cerr << "Error irrecuperable" << std::endl;
        return 1;
    }
    if(std::cin.eof())
    {
        std::cin.clear();
        i--;
    }

    for (int k = 0; k < i; k++)
        std::cout << nombres[k] << std::endl;
    
}