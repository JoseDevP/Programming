#include <iostream>
#include "../Fecha/fecha.hpp"
#include "cumpleanos.hpp"

void visualizar(const CCumpleaños&);

int main()
{
    char nombre[80];
    int dia, mes, anyo;
    long telefono;

    try
    {
        CCumpleaños p1("Francisco", 25 ,8 ,1982, 666777888);
        visualizar(p1);

        CCumpleaños p2;

        std::cout << "Nombre:   ";
        std::cin.getline(nombre, 80, '\n');
        p2.asignarNombre(nombre);

        std::cout << "Fecha de nacimiento\n";
        std::cout << "dia: "; std::cin >> dia;
        std::cout << "mes: "; std::cin >> mes;
        std::cout << "anyo: "; std::cin >> anyo;
        p2.fechaNacimiento() = fjc::CFecha(dia,mes,anyo);
        std::cout << "Telefono: ";
        std::cin >> telefono;
        p2.asignarTelefono(telefono);
        visualizar(p2);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

void visualizar(const CCumpleaños& persona)
{
    fjc::CFecha fecha;
    std::cout << "Nombre: " << persona.obtenerNombre() << std::endl;
    std::cout << "Fecha de nacimiento\n";
    fecha = persona.fechaNacimiento();
    std::cout << "dia: " << fecha.obtenerDia() << std::endl; 
    std::cout << "mes: " << fecha.obtenerMes() << std::endl; 
    std::cout << "anyo: " << fecha.obtenerAnyo() << std::endl; 
    std::cout << "Telefono: " << persona.obtenerTelefono();
    std::cout << "\n\n";
}