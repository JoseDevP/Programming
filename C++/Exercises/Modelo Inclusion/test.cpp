#include <iostream>
#include <vector>
#include "plantillas.hpp"

int main()
{
    std::vector<double> v1(10);
    std::vector<double> v2(8);

    std::cout << menor(10, 27) << '\n';
    std::vector<double> v3 = menor(v1, v2);
    
    std::cout << v3.size() << '\n';
    std::cout << menor(26.2, 26.8) << '\n';
}