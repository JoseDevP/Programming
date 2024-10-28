#include <iostream>
#include <limits>

int main()
{
    char car=0;
    std::cout << "Introducir un carácter: ";

    std::cin.get(car);
    std::cin.ignore(std::numeric_limits<int>::max(), '\n');
    std::cout << "Carácter: " << car
              << ", valor ASCII: " << static_cast<int>(car) << std::endl;
}