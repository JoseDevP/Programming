#include <iostream>
#include <string>
#include <exception>

int main()
{
    char cadena[40] = {"Hola mundo"}; 
    char car;
    std::string str(cadena);

    //iterator begin end at
    std::string::iterator i;

    for (i = str.begin(); i != str.end(); i++)
        std::cout << *i;

    std::cout << '\n';

    std::string::reverse_iterator e;

    for (e = str.rbegin(); e != str.rend(); e++)
        std::cout << *e;
    
    std::cout << '\n';
    
    try
    {
        car = str.at(23);
    }
    catch(std::out_of_range)
    {
        std::cerr << "error de rango producido por el caracter de "
                  << "valor ASCII " << static_cast<int>(car) << std::endl;
    }

    //assign
    std::string str2;
    str2.assign(str); // o =

    std::cout << '\n';

    std::cout << "Copiado " << std::endl;

    for (i = str.begin(); i != str.end(); i++)
        std::cout << *i;

    std::cout << '\n';

    //convertir a cadena de c c_str
    const char * cadena_c = str2.c_str();
    std::cout << "Cadena en c: " << cadena_c << std::endl;

    //copy
    str.copy(cadena, str.length(), 0);

    //compare en otro archivo

    //insert
    std::string str3 = "abcd"; 
    std::string str4 = "lmn"; 

    str3 += str4;
    str3.insert(2,"ijk");
    str3.append(str4);

    std::cout << str3 << std::endl;
    int pos;
    pos = str3.find("ijk");
    std::cout << "ijk found in position " << pos << std::endl; 
    str3.replace(str3.find("ijk"),str3.find("ijk"), "substituido");
    std::cout << str3 << std::endl;

    
}