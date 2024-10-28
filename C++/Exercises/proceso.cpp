#include <iostream>
#include <ctime>

int random(int n)
{
    static bool primera_vez = true;
    if(primera_vez)
    {
        srand(time(0));
        primera_vez = false;
    }
    return (rand() % n) +1 ;
}

void esperar(int n)
{
    long tmi = clock() + n;
    while (clock() < tmi);
}

void tomarMuestraTipoA(int* n)
{
    *n = random(10);

    for (int i = 0; i < *n; i++)
    {
        std::cout << "Tomando muestra de tipo A\n";
        esperar(500);
    }
}

void tomarMuestraTipoB(int* n)
{
    *n = random(20);

    for (int i = 0; i < *n; i++)
    {
        std::cout << "Tomando muestra de tipo B\n";
        esperar(500);
    }
}

void resultados(int n, int m)
{
    std::cout << "Muestras de tipo A: " << n << std::endl;
    std::cout << "Muestras de tipo B: " << m << std::endl;
    std::cout << "Total: " << ( n + m ) << std::endl;
}

int main()
{
    int nMuestrasTipoA = 0;
    int nMuestrasTipoB = 0;
    tomarMuestraTipoA(&nMuestrasTipoA);
    tomarMuestraTipoB(&nMuestrasTipoB);
    resultados(nMuestrasTipoA, nMuestrasTipoB);
}