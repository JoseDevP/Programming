#include <iostream>
#include <string>
#include <limits>

#include "concesionario.hpp"
#include "cvehiculo.hpp"
#include "ccoche.hpp"
#include "cmoto.hpp"
#include "ccamion.hpp"



int menu(const char* opciones[], int numOpciones)
{
    int op = -1;
    int i = 0;
    std::cout << "Opciones: " << std::endl;
    for (i = 0; i < numOpciones; i++)
        std::cout << i + 1 << ": " << opciones[i] << std::endl;
    std::cout << "\n";
    do
    {
        std::cout << "Introduce numero de opcion deseado ->  "; std::cin >> op;
        if(op < 0 || op > numOpciones)
            std::cout << "No valida\n";
    } while (op < 0 || op > numOpciones );
    std::cout << "\n\n";
    return op;
}

double leerNumero()
{
    double num;
    std::cin >> num;
    while(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> num;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return num;
}

CVehiculo* crearVehiculo()
{
    std::string tipoVehiculo;

    std::string marca;
    std::string modelo;
    long año;

    std::cout << "Tipo vehiculo (Coche / Moto / Camion): "; std::getline(std::cin, tipoVehiculo);


    std::cout << "Marca: "; std::getline(std::cin, marca);
    std::cout << "Modelo: "; std::getline(std::cin, modelo);
    año = long(leerNumero());


    if(tipoVehiculo == "Coche")
    {
        std::cout << "Numero de puertas: ";
        int numPuertas = int(leerNumero());
        CVehiculo* v = new CCoche(marca, modelo, año, numPuertas);
        return v;
    }
    if(tipoVehiculo == "Moto")
    {
        std::string tipoMotor;
        std::cout << "Tipo de Motor: "; std::getline(std::cin, tipoMotor);
        CVehiculo* v = new CMoto(marca, modelo, año, tipoMotor);
        return v;
    }
    if(tipoVehiculo == "Camion")
    {
        std::cout << "Capacidad de carga: ";
        double capacidadCarga = leerNumero();
        CVehiculo* v = new CCamion(marca, modelo, año, capacidadCarga);
        return v;
    }
    else 
        return nullptr;
}


int main()
{
    CConcesionario concesionario;
    CVehiculo * v = nullptr;

    const char* opciones[] = 
    {
        "Ver Vehiculos",
        "Añadir Vehiculo",
        "Eliminar Vehiculo",
        "Numero de Vehiculos",
        "Salir"
    };
    int numOpciones = sizeof(opciones) / sizeof(char*);

    int opcion = -1;
    std::string marca;
    std::string modelo;

    do
    {
        opcion = menu(opciones, numOpciones);

        switch (opcion)
        {
        case 1: //Ver Vehiculos
            if(concesionario.cantidadDeVehiculos() != 0)
            {
                concesionario.descripcion();
            }
            else
                std::cout << "Concesionario vacio" << std::endl;
            break;

        case 2: //Añadir Vehiculo
            if((v = crearVehiculo()) != nullptr)
            {
                concesionario.anyadirVehiculo(v);
                delete v;
                std::cout << "Vehiculo añadido";
            }
            else
                std::cout << "El tipo de vehiculo no es valido";
            break;

        case 3: //Eliminar Vehiculo
            std::cout << "Indique la marca del vehiculo a eliminar: "; std::getline(std::cin, marca);
            std::cout << "Indique el modelo del vehiculo a eliminar: "; std::getline(std::cin, modelo);
            if(concesionario.eliminarVehiculo(marca,modelo))
                std::cout << "Eliminado" << std::endl;
            else
                std::cout << "No encontrado" << std::endl;
            break;

        case 4: //Numero de Vehiculos
            std::cout << "Cantidad de vehiculos: " << concesionario.cantidadDeVehiculos() << std::endl;
            break;
        
        case 5: //Salir
            break;
        }

    } while (opcion != 5);
    
}