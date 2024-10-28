#include <iostream>
#include <string>
#include <map>

int main()
{
    std::map<std::string, long> agenda;
    std::string nombre;
    long telefono = 0;
    std::map<std::string, long>::iterator persona;

    std::cout << "Pares string long (finalizar con Ctrol + z):\n";
    while ( std::cin >> nombre >> telefono) agenda[nombre] = telefono;

    if(!agenda.empty())
    {
        persona = agenda.find("xxxx");
        if(persona != agenda.end())
        {
            std::cout << persona->first << "borrado\n";
            agenda.erase(persona);
        }
    } 

    for (persona = agenda.begin(); persona != agenda.end(); persona++)
        std::cout << " " << (*persona).first << '\t'
                  << (*persona).second << std::endl;

    std::cout << agenda.size() << " elementos\n";
    agenda.clear();
}