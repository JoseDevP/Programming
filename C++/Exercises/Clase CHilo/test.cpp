#include <iostream>
#include <mutex>
#include "hilo.hpp"

std::mutex io_mutex;

class Hilo : public CHilo
{
    public:
        Hilo::Hilo(std::string nombre) : CHilo(nombre) {}

        void Hilo::fnHilo() override
        {
            std::unique_lock<std::mutex> ulock(io_mutex);
            std::cout << "hilo " << obtener_nombre() << ", ID: " << obtener_id() << std::endl;
        }
};

int main()
{
    Hilo hilo1("Hilo 1");
    Hilo hilo2("Hilo 2");
    try
    {
        hilo1.iniciar();
        hilo2.iniciar();

        hilo1.esperar_finalizacion();
        hilo2.esperar_finalizacion();
    }
    catch(std::string& msj)
    {
        std::cerr << msj << '\n';
    }
    
}