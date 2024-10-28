#include <iostream>
#include <iomanip>

int main()
{
    int a =12345;
    float b = 54.865F;

    std::cout << a << std::endl;
    std::cout << '\n' << std::setw(10) << "abc" << std::setw(10) << "abcdef" << std::endl;
    std::cout << std::left; //ajuste a la izquierda
    std::cout << '\n' << std::setw(10) << "abc" << std::setw(10) << "abcdef" << std::endl;
    std::cout << std::endl;
    std::cout << std::right; //ajuste a la derecha

    std::cout << std::fixed << std::setprecision(2);
    std::cout << std::setw(15) << b << std::endl;
    std::cout << std::setw(15) << b/10 << std::endl;
}