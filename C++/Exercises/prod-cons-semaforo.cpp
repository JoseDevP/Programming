#include <iostream>
#include <iomanip>
#include <thread>
#include <mutex>
#include <chrono>
#include "semaphore.hpp"

const int ELEMENTOS_BUFFER = 16;
const int TOTAL_DATOS = 30;

void productor();
void consumidor();

struct 
{
    int buffer[ELEMENTOS_BUFFER];
    int ind_p, ind_c;
    std::mutex exmut;
    semaphore sem_vacios{ELEMENTOS_BUFFER};
    semaphore sem_llenos;
} st_buffer;

int main()
{
    st_buffer.ind_p = st_buffer.ind_c = 0;

    std::thread hilo_p(productor);
    std::thread hilo_c(consumidor);

    hilo_p.join();
    hilo_c.join();

    system("pause");
}

void productor()
{
    int i, a;
    for (i = 0; i < TOTAL_DATOS; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 10));

        st_buffer.sem_vacios.wait();

        {
            std::scoped_lock<std::mutex> slock(st_buffer.exmut);

            a = rand();
            st_buffer.buffer[st_buffer.ind_p] = a;
            st_buffer.ind_p = (st_buffer.ind_p + 1) % (ELEMENTOS_BUFFER);
            std::cout << "buffer <-- " << std::setw(6) << a << std::endl;
        }

        st_buffer.sem_llenos.notify();
    }
}

void consumidor()
{
    int i, a;
    for (i = 0; i < TOTAL_DATOS; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 10));

        st_buffer.sem_llenos.wait();

        {
            std::scoped_lock<std::mutex> slock(st_buffer.exmut);

            a = st_buffer.buffer[st_buffer.ind_c];
            st_buffer.ind_c = (st_buffer.ind_c + 1) % (ELEMENTOS_BUFFER);
            std::cout << "buffer <-- " << std::setw(6) << a << std::endl;
        }

        st_buffer.sem_vacios.notify();
    }
}
