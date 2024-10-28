#include <iostream>
#include <string>
#include <stdexcept>
#include <clocale>

std::tuple<int, std::string, int, char> datosPersona(int id)
{
    if(id == 1) return std::make_tuple(1, "Nombre Apellidos 1", 23 , 'M');
    if(id == 2) return std::make_tuple(2, "Nombre Apellidos 2", 19 , 'M');
    if(id == 3) return std::make_tuple(3, "Nombre Apellidos 3", 30 , 'F');
    throw std::invalid_argument("id no válido: " + std::to_string(id));
}


int main(void)
{
    std::setlocale(LC_ALL,"");
    try
    {
        auto persona1 = datosPersona(1);
        std::cout << std::get<1>(persona1) << ", " 
                  << std::get<2>(persona1) << ", "
                  << std::get<3>(persona1) << "\n";

        std::string nombre;
        int id, edad;
        char sexo;
        std::tie(id,nombre,edad,sexo) = datosPersona(3);
        std::cout << "\nID " << id << "\n" 
                  << "Nombre " << nombre << "\n" 
                  << "Edad " << edad << "\n" 
                  << "Sexo " << sexo << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}