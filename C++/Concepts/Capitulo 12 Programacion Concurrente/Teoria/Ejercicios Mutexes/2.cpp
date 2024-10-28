/*Ejercicio 2: Suma recursiva de números (Uso de std::thread y std::recursive_mutex)
Implementa un programa que calcule la suma de una serie de números usando varios hilos.
 Sin embargo, el acceso a la variable compartida donde se almacena el resultado de la suma 
 debe ser protegido usando un std::recursive_mutex, ya que la suma se realizará de forma 
 recursiva dentro de cada hilo.

Requerimientos:
Define una función que sume una serie de números recursivamente.
Protege la variable compartida usando std::recursive_mutex.
Lanza múltiples hilos para calcular la suma de partes diferentes de la serie.
*/
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <numeric> // Para std::accumulate
#include <limits>

int rdm(int n = std::numeric_limits<int>::max())
{
    static bool primera_vez = true;
    if (primera_vez)
    {
        srand(time(0));
        primera_vez = false;
    }
    return (rand() % n) + 1;
}

class Numeros
{
private:
    std::vector<int> vec;
    int suma;
    std::recursive_mutex rec_mutex;

public:
    Numeros(int size) : suma(0)
    {
        for (int i = 0; i < size; i++)
        {
            int n = rdm(100);
            vec.push_back(n);
            std::cout << n << " "; 
        }
        std::cout << std::endl;
    }

    void Sumar(int inicio, int fin)
    {
        if (inicio >= fin) return; 

        {
            std::lock_guard<std::recursive_mutex> lgrm(rec_mutex);
            suma += vec[inicio];
        }

        Sumar(inicio + 1, fin); 
    }

    int obtenerSuma()
    {
        std::lock_guard<std::recursive_mutex> lgrm(rec_mutex);
        return suma;
    }
};

int main()
{
    const int NUM_ELEMENTOS = 10;
    Numeros numeros(NUM_ELEMENTOS);

    std::vector<std::thread> hilos;
    const int NUM_HILOS = 5;

    for (int i = 0; i < NUM_HILOS; ++i)
    {
        int inicio = (NUM_ELEMENTOS / NUM_HILOS) * i;
        int fin = (i == NUM_HILOS - 1) ? NUM_ELEMENTOS : (NUM_ELEMENTOS / NUM_HILOS) * (i + 1);
        hilos.emplace_back(&Numeros::Sumar, &numeros, inicio, fin);
    }

    for (auto& hilo : hilos)
    {
        if (hilo.joinable())
            hilo.join();
    }

    std::cout << "Suma total: " << numeros.obtenerSuma() << std::endl;

    return 0;
}
