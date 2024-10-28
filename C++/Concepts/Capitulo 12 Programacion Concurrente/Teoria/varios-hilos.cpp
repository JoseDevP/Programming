#include <iostream>
#include <thread>
#include <chrono>

int tareaHilo1(int n, int id)
{
    for (int i = 0; i < 4; i++)
    {
        std::cout << "hilo " << id << " ejecutandose\n";
        ++n;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    return n; //lo ignora
}

void tareaHijo2(int& n, int id)
{
    for (int i = 0; i < 4; i++)
    {
        std::cout << "hilo " << id << " ejecutandose\n";
        ++n;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

int main()
{
    int n1 = 0, n2 = 0;

    std::thread hilo; //hilo no es un thread
    std::thread hilo1(tareaHilo1, n1, 1); //pasado por valor
    std::thread hilo2(tareaHijo2, std::ref(n2), 2);
    std::thread hilo3(std::move(hilo2)); //ejecuta tareaHijo2. hilo2 ya no es un thread

    hilo1.join();
    hilo3.join();
    std::cout << "Valor final de n1" << n1 << '\n';
    std::cout << "Valor final de n2" << n2 << '\n';

}