#include <iostream>
#include <thread>

void tareaHilo()
{
    std::cout << "Se ejecuta el hilo secundario\n";
    for (int i = 0; i < 200000000; i++)
    {
        //hacer algo
    }
    std::cout << "El hilo secundario finalzó\n";
}

void f1()
{
    std::thread hilo1(tareaHilo);
    try
    {
        //hacer algo
        throw "error"; //simulamos excepcion
    }
    catch(...)
    {
        if(hilo1.joinable()) hilo1.join();
        throw;
    }

    if(hilo1.joinable()) hilo1.join();
}

int main()
{
    std::cout << "Se ejecuta el hilo primario main\n";
    try
    {
        f1();
    }
    catch(...)
    {
        std::cout << "error\n";
    }
    std::cout << "El hijo primario finalizo\n";
}