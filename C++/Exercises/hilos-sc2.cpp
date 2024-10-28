#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <memory>

class Buffer
{
    private:
        std::unique_ptr<int[]> muestras;
        int nMuestras;
        int ind;
        std::recursive_mutex mutex_adquirir;
    public:
        Buffer(int n = 10) : muestras(new int[n]), nMuestras(n), ind(0) 
        {
            std::fill_n(muestras.get() , nMuestras, 0);
        }

        friend void AdquirirDatos(Buffer& buffer, int id);
        friend void TomarMuestra(Buffer& buffer);
};

int random(int n = std::numeric_limits<int>::max())
{
    static bool primera_vez = true;
    if(primera_vez)
    {
        srand(time(0));
        primera_vez = false;
    }
    return (rand() % n) + 1;
}

void TomarMuestra(Buffer& buffer)
{
    std::lock_guard<std::recursive_mutex> cs_lockg(buffer.mutex_adquirir);
    int x = 0;
    x = random();
    buffer.muestras[buffer.ind] = x;
}

void AdquirirDatos(Buffer& buffer, int id)
{
    static std::mutex io_mutex;

    do
    {
        std::lock_guard<std::recursive_mutex> cs_lockg(buffer.mutex_adquirir);

        if(buffer.ind >= buffer.nMuestras) return;
        TomarMuestra(buffer);
        {
            std::lock_guard<std::mutex> io_lockg(io_mutex);
            std::cout << "hilo-" << id << " tomó la muestra " << buffer.ind << std::endl;
        }

        buffer.ind++;
    } while (buffer.ind < buffer.nMuestras);
    
}

int main()
{
    const int NHILOS = 2;
    const int CAPACIDAD = 20;
    int id;

    Buffer buffer(CAPACIDAD);

    std::vector<std::thread> hilos;
    for (id = 0; id < NHILOS; id++)
        hilos.emplace_back(AdquirirDatos, std::ref(buffer), id);

    for (id = 0; id < NHILOS; id++)
        if(hilos[id].joinable()) hilos[id].join();
}