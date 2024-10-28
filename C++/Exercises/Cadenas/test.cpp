#include <iostream>
#include <iomanip>
#include "formato.hpp"

int main()
{
    CNumEntero n;

    std::cout.setf(std::ios::right);
    n = 123; std::cout << std::setw(20) << n << std::endl;
    n = -12345; std::cout << std::setw(20) << n << std::endl;
    n = 1234567; std::cout << std::setw(20) << n << "\n\n";

    std::cout.setf(std::ios::showpos);
    n = 123; std::cout << std::setw(20) << n << std::endl;
    n = -12345; std::cout << std::setw(20) << n << std::endl;
    n = 1234567; std::cout << std::setw(20) << n << "\n\n";

    std::cout.setf(std::ios::showbase);
    n = 0x123; std::cout << std::setw(20) << std::hex<< n << std::endl;
    n = -0x12345; std::cout << std::setw(20)  << std::hex<< n << std::endl;
    n = 0x1234567; std::cout << std::setw(20) << std::hex << n << "\n\n";

    n = 0123; std::cout << std::setw(20) << std::oct << n << std::endl;
    n = -012345; std::cout << std::setw(20) << std::oct << n << std::endl;
    n = 01234567; std::cout << std::setw(20) << std::oct << n << "\n\n";

    //Forma simplificada
    std::cout .unsetf(std::ios::showpos);
    n = 1234567890; std::cout << std::setw(20) << std::dec << n << std::endl;
    n = -1234567890; std::cout << std::setw(20) << std::dec << n << std::endl;
}