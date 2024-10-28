#include <iostream>
#include <thread>
#include <chrono>

class CTareaHilo
{
    private:
        int n;
        int id;
    public:
        CTareaHilo(int c = 0, int i = 0) : n(c), id(i) {}
        void operator() ()
        {
            for (int i = 0; i < 4; i++)
            {
                std::cout << "hilo " << id << " ejecutandose\n";
                ++n;
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
            }
        }

        int obtenerN() {return n;}
};

int main()
{
    int n1 = 0, n2 = 0;
    CTareaHilo tarea1;
    CTareaHilo tarea2(n2, 1);

    std::thread hilo1(tarea1);
    std::thread hilo2(std::ref(tarea2));

    hilo1.join();
    hilo2.join();

    n1 = tarea1.obtenerN();
    n2 = tarea2.obtenerN();

    std::cout << "Valor final de n1: " << n1 << '\n';
    std::cout << "Valor final de n2: " << n2 << '\n';
}



