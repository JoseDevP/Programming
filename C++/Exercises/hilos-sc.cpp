#include <iostream>
#include <thread>
#include <mutex>
#include <limits>
#include <vector>

const int MAX_MUESTRAS = 10;

struct 
{
    int muestras[MAX_MUESTRAS];
    int ind;
    std::mutex mutex_adquirir;
}st_buffer;


int random(int n = std::numeric_limits<int>::max())
{
    static bool primera_vez = true;
    if(primera_vez)
    {
        srand(time(0));
        primera_vez = true;
    }
    return (rand() % n) +1;
}

void AdquirirDatos(int id)
{
    static std::mutex io_mutex;

    int x = 0;
    do
    {
        std::lock_guard<std::mutex> cs_lockg(st_buffer.mutex_adquirir);

        if(st_buffer.ind >= MAX_MUESTRAS)   return;

        x = random();

        {
            std::lock_guard<std::mutex> io_lockg(io_mutex);
            std::cout << "hilo-" << id << " tomó la muestra " << st_buffer.ind << std::endl;
        }
        st_buffer.muestras[st_buffer.ind] = x;
        st_buffer.ind++;

    } while (st_buffer.ind < MAX_MUESTRAS);
    
}

int main()
{
    const int NHILOS = 2;
    int id;

    st_buffer.ind = 0;
    std::fill(st_buffer.muestras,st_buffer.muestras + MAX_MUESTRAS, 0);

    std::vector<std::thread> hilo;

    for (id = 0; id < NHILOS; id++)
        hilo.emplace_back(AdquirirDatos, id);
    
    for ( id = 0; id < NHILOS; id++)
        if(hilo[id].joinable()) hilo[id].join();
    
}