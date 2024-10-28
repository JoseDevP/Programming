#include <iostream>
#include <memory>
#include <vector>
#define LONGNOM 30

struct persona
{
    char nombre[LONGNOM];
    long tfno;
};

void leer( std::unique_ptr< std::vector<persona>>& pi)
{
    if (!pi) return;

    for (size_t i = 0; i < (*pi).size(); i++)
    {
        std::cout << "Nombre:  "; std::cin.getline((*pi)[i].nombre, LONGNOM);
        std::cout << "Telefono: "; std::cin >> ((*pi)[i].tfno);
        std::cin.ignore();
    }
}

void mostrar(std::unique_ptr<std::vector<persona>>& pi)
{
    if(!pi) return;
    for (size_t i = 0; i < (*pi).size(); i++)
    {
        std::cout << "Nombre:  " << ( (*pi)[i].nombre ) << std::endl;
        std::cout << "Telefono: " << ( (*pi)[i].tfno ) << std::endl;
    }
}

int main()
{
    int n = 3;

    std::unique_ptr<std::vector<persona>> pi1(new std::vector<persona>(n));
    std::unique_ptr<std::vector<persona>> pi2;
    try
    {
        leer(pi1);
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    //pi2 = pi1 -> error no se puedo copiar unique_ptr
    pi2 = std::move(pi1);
    mostrar(pi2); 

    //reset 
    std::vector<persona>* p = new std::vector<persona>(1);
    std::cout << "Nombre:  "; std::cin .getline((*p)[0].nombre, LONGNOM);
    std::cout << "Teléfono:  "; std::cin >> (*p)[0].tfno;
    pi2.reset(p);

    p = nullptr; //-> lo que habia en p2 se borra y ahora pi2 apunta al nuevo vector, p ahora no apunta a nada
    mostrar(pi2);

    //Utilizacion de ->
    long ne = pi2->size();
    std::cout << "Número de elementos: " << ne << std::endl;

    //Utiolizacion de *
    ne = (*pi2).size();
    std::cout << "Número de elementos: " << ne << std::endl;

    //Utilizacion de release
    p = pi2.release();
    std::cout << "Nombre: " << (*p)[0].nombre << std::endl;
    std::cout << "Teléfono: " << (*p)[0].tfno << std::endl;
    delete p;
}