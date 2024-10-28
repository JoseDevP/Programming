#include <iostream>
#include <iomanip>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <cassert>


const int ELEMENTOS_BUFFER = 16;
const int TOTAL_DATOS = 100;

typedef struct 
{
    int buffer[ELEMENTOS_BUFFER];
    int ocupados;
    int ind_p, ind_c;
    std::mutex exmut;
    std::condition_variable vacios;
    std::condition_variable llenos;
} st_buffer_t;

void productor(st_buffer_t& st_b)
{
    int i, a;
    for ( i = 0; i < TOTAL_DATOS; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 10));

        std::unique_lock<std::mutex> ulock(st_b.exmut);
        while (st_b.ocupados == ELEMENTOS_BUFFER)
            st_b.vacios.wait(ulock);

        assert(st_b.ocupados < ELEMENTOS_BUFFER);

        a = rand();
        st_b.buffer[st_b.ind_p] = a;
        st_b.ind_p = (st_b.ind_p + 1) % (ELEMENTOS_BUFFER);
        st_b.ocupados++;

        std::cout << "buffer <-- " << std::setw(6) << a << " hilo productor\n";
        st_b.llenos.notify_one();
    }
    
}

void consumidor(st_buffer_t& st_b)
{
    int i, a;
    for (i = 0; i < TOTAL_DATOS; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 10));

        std::unique_lock<std::mutex> ulock(st_b.exmut);

        while (st_b.ocupados == 0)
            st_b.llenos.wait(ulock);

        a = st_b.buffer[st_b.ind_c];
        st_b.ind_c = (st_b.ind_c + 1) % (ELEMENTOS_BUFFER);
        st_b.ocupados--;

        std::cout << "buffer <-- " << std::setw(6) << a << " hilo productor\n";
        st_b.vacios.notify_one();
    }
    
}


int main()
{
    st_buffer_t st_buffer{ {0}, 0, 0, 0};

    std::thread hilo_p(productor, std::ref(st_buffer));
    std::thread hilo_c(consumidor, std::ref(st_buffer));

    hilo_p.join();
    hilo_c.join();

    system("pause");
}