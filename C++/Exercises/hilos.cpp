#include <iostream>
#include <thread>

void tareaHilo()
{
    std::cout << "Se ejecuta el hilo secundario: tareaHijo\n";

    //...

    std::cout << "El hilo secundario ha finalizado\n";
}

int main()
{
    std::cout << "Se ejecuta el hijo primario: main\n";
    std::thread hilo1(tareaHilo);

    hilo1.join(); //esperar a que el hilo finalice
    std::cout << "El hilo primario finalizó.\n";
}