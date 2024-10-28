#include <iostream>
#include <condition_variable>
#include <thread>
#include <mutex>
#include <chrono>

struct 
{
    int i;
    std::mutex exmut;
    std::condition_variable vcond;
} st{0};

void esperar(int id)
{
    std::unique_lock<std::mutex> ulock(st.exmut);
    if(st.i == 0)
    {
        std::cerr << "Hilo " << id << " esperando... \n";
        st.vcond.wait(ulock); //esperar y liberar el mutex
    }
    std::cerr << "Hilo " << id << " finalizó la espera.\n";
}

void notificar(int id)
{
    std::this_thread::sleep_for(std::chrono::seconds(4));

    {
        std::unique_lock<std::mutex> ulock(st.exmut);
        st.i = 1;
        std::cerr << "Hilo " << id << " notificando...\n";
    }
    st.vcond.notify_all(); //todos los hilos abandonan la cola de espera
}

int main()
{
    std::thread hilo1(esperar, 1), hilo2(esperar,2), hilo3(notificar,3);

    hilo1.join();
    hilo2.join();
    hilo3.join();
}

