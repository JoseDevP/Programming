#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include <vector>

struct Cosas
{
    int num_cosas;
    std::mutex m;
    explicit Cosas(int num) : num_cosas{num} {}
    int numCosas() {return num_cosas;}
};

void transferir(int id, Cosas& origen, Cosas& destino, int num)
{
    std::scoped_lock<std::mutex, std::mutex> slock(origen.m, destino.m);

    origen.num_cosas -= num;
    std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 50));
    destino.num_cosas += num;

    //desbloquean origen.m y destino.m
}

int main()
{
    Cosas caja1(80);
    Cosas caja2(45);

    std::vector<std::thread> hilos;

    for (unsigned i = 0; i <= 8; i++)
        if(i % 2 != 0)
            hilos.emplace_back(transferir, i, std::ref(caja1), std::ref(caja2), 10);
        else
            hilos.emplace_back(transferir, i, std::ref(caja1), std::ref(caja2), 5);
    
    for (auto& hilo : hilos)
        if(hilo.joinable()) hilo.join();

    std::cout << caja1.numCosas() << std::endl << caja2.numCosas() << std::endl;
    
}