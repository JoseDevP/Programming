#include <iostream>
#include <fstream>

int main()
{
    float dato1 = -105.56; // 7 bytes
    float dato2 = -3.1415926; //8 bytes 
    char cadena[20] = "hola"; // 4 bytes

    std::cout << dato1 << std::endl;
    std::cout << dato2 << std::endl;
    std::cout << cadena << std::endl;

    std::fstream fs("datos", std::ios::out);
    fs << dato1 << " " << dato2 << " " << cadena << std::endl;
    std::cout << fs.tellp() << std::endl; //7 + 8 + 4 + 4(dos espacios) = 23 bytes
    fs.close();

    fs.open("datos", std::ios::in);
    fs >> dato1 >> dato2 >> cadena;
    std::cout << dato1 << std::endl;
    std::cout << dato2 << std::endl;
    std::cout << cadena << std::endl;

    fs.close();
}