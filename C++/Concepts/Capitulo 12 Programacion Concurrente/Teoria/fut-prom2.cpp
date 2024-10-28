#include <iostream>
#include <map>
#include <thread>
#include <string>
#include <future>

std::string obtenerMensaje(int error)
{
    std::map<int, std::string> mensajes
    {
        {1, "mensaje de error 1"},
        {2, "mensaje de error 2"},
        {3, "mensaje de error 3"},
    };
    return mensajes[error];
}

void productor(int error, std::promise<std::string> p)
{
    try
    {
        std::string s = obtenerMensaje(error);
        std::this_thread::sleep_for(std::chrono::seconds(1));

        if(s.empty()) throw "error no definido";
        p.set_value(s);
    }
    catch(...)
    {
        p.set_exception(std::current_exception());
    }
}

void consumidor(std::future<std::string> f)
{
    try
    {
        std::string s = f.get();
        std::cout << s << "\n";
    }
    catch(const char* a)
    {
        std::cerr << a << '\n';
    }
    
}

int main()
{
    int error = 0;
    std::promise<std::string> promesa;
    std::future<std::string> futuro = promesa.get_future();

    std::thread tarea1(productor, error, std::move(promesa));
    std::thread tarea2(consumidor, std::move(futuro));
}