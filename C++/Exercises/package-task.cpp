#include <iostream>
#include <map>
#include <thread>
#include <string>
#include <future>

std::string obtenerMensaje(int error) {
    std::map<int, std::string> mensajes {
        {1, "mensaje de error 1"},
        {2, "mensaje de error 2"},
        {3, "mensaje de error 3"},
    };
    return mensajes[error];
}

std::string productor(int error) 
{
    std::string s = obtenerMensaje(error);
    if (s.empty()) throw "error no definido";
    return s;
}

void consumidor(int error) 
{
    try {
        std::packaged_task<std::string(int)> tarea(productor);

        std::future<std::string> futuro = tarea.get_future();

        std::thread hilo(std::move(tarea), error); 

        std::cout << futuro.get() << "\n"; 

        hilo.join();
    }
    catch (const char* a) {
        std::cerr << a << '\n';
    }
}

int main() {
    int error = 1; 
    consumidor(error);
}
