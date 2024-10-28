/*Ejercicio 1: Productor-Consumidor (Uso de std::thread, std::mutex, y std::lock_guard)
Implementa el problema del productor-consumidor donde múltiples hilos productores colocan
elementos en un buffer compartido, y varios hilos consumidores retiran elementos del buffer.
Usa un std::mutex para proteger el acceso al buffer y std::lock_guard para manejar el
bloqueo automático.

Requerimientos:
Un buffer de tamaño limitado.
Múltiples hilos productores que añaden números aleatorios al buffer.
Múltiples hilos consumidores que extraen números del buffer.
Usa std::mutex y std::lock_guard para asegurar el acceso seguro al buffer compartido.*/

#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <limits>

int rdm(int n = std::numeric_limits<int>::max())
{
    static bool primera_vez = true;
    if(primera_vez)
    {
        srand(time(0));
        primera_vez = false;
    }
    return (rand() % n) + 1;
}

class Buffer
{
private:
    const int MAX_ELEMENTS = 10; 
    std::vector<int> vector;      
    std::mutex mutex_asignar;     

public:
    Buffer() {}

    bool vacio()
    {
        return vector.empty();
    }

    bool lleno()
    {
        return vector.size() >= MAX_ELEMENTS;
    }

    void añadirNumero()
    {
        int n = rdm(10);
        std::lock_guard<std::mutex> lgm(mutex_asignar); 
        if (!lleno())
        {
            vector.push_back(n);
            std::cout << "Añadido: " << n << " (Tamaño actual: " << vector.size() << ")\n";
        }
    }

    void retirarNumero()
    {
        std::lock_guard<std::mutex> lgm(mutex_asignar);
        if (!vacio())
        {
            int retirado = vector.back();
            vector.pop_back();
            std::cout << "Retirado: " << retirado << " (Tamaño actual: " << vector.size() << ")\n";
        }
    }
};

void productor(Buffer& buffer)
{
    for (int i = 0; i < 10; ++i)
    {
        buffer.añadirNumero();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));  
    }
}


void consumidor(Buffer& buffer)
{
    for (int i = 0; i < 10; ++i)
    {
        buffer.retirarNumero();
        std::this_thread::sleep_for(std::chrono::milliseconds(150));  
    }
}

int main()
{
    Buffer buffer;

    const int MAXIMO_PROD_CONS = 5;

    std::vector<std::thread> productores;
    std::vector<std::thread> consumidores;

    for (int i = 0; i < MAXIMO_PROD_CONS; i++)
        productores.emplace_back(productor, std::ref(buffer));

    for (int i = 0; i < MAXIMO_PROD_CONS; i++)
        consumidores.emplace_back(consumidor, std::ref(buffer));

    for (auto& prod : productores)
        if (prod.joinable()) prod.join();

    for (auto& cons : consumidores)
        if (cons.joinable()) cons.join();

    return 0;
}
