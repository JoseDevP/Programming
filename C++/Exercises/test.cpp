#include <iostream>
#include <iomanip>

int main(int argc, char* argv[])
{
    int n;
    while (std::cin >> n)
    {
        std::cout << std::setw(6) << n;
        if(argc > 1 && argv[1][0] == '-' && argv[1][1] == 'l' )
            std::cout << ((n % 2) ? " Es impar" : " Es par");
        std::cout << "\n";  
    }
    
}