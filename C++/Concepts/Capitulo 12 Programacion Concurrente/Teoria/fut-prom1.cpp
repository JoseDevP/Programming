#include <iostream>
#include <thread>
#include <string>
#include <future>

int main()
{
    auto promesa = std::promise<std::string>();
    auto futuro = promesa.get_future();

    auto tarea1 = std::thread([&] 
    {
        std::string valor = "Un mensaje";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        promesa.set_value(valor);
    });

    auto tarea2 = std::thread([&]
    {
        std::cout << futuro.get() << "\n";
    });

    std::cout << "Tareas en proceso...\n";

    tarea1.join();
    tarea2.join();
}