#include <iostream>
#include "cadenas.hpp"

int main()
{
    CCadena a[10], b;
    char sCadena[] ="abcdef";

    a[0] ="xxx";
    a[2] = a[1] = a[0];
    a[3] = sCadena;

    CCadena x = a[3];
    a[4] = a[0] + sCadena;
    a[5] ="yyy" + CCadena("zzz");

    b=CCadena('/',10); 
    std::cout << b[4] << '\n';
    std::cout << "Introduce caden: "; std::cin >> a[6];
    (a[6] > b) ? std::cout << a[6] << '\n' : std::cout << b << '\n';

    if(a[0] == "xxx" && "yyy" > a[3])
        a[7] += "zzz";
    if("xxx" != a[1] || sCadena < a[2])
        a[8] = a[8] +"fin";
    for (int i = 0; i < 10; i++)
        std::cout << a[i] << " " << a[i].ObtenerLong() << '\n';
    
}