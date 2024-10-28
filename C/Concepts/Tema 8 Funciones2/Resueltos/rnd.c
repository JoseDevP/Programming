/*
    Utilizando la función rnd siguiente  (*prandom es un valor entre 0 y 65535):
        double rnd(long p*random)
        {
            *prandom = (25173 * *prandom + 13849) % 65536;
            return((double)*prandom/65536); //entre 0 y 1
        }

    Realizar un programa que muestre seis numeros aleatorios diferentes entre 1 y 49 
    ordenados ascendentemente.
*/

#include <stdio.h>
#include <stdlib.h>

inline extern double rnd(long *prandom)
{
    *prandom = (25173 * *prandom + 13849) % 65536;
    return 1 + ((double)*prandom / 65536) * 48; // Devuelve un número aleatorio entre 1 y 49
}

typedef double (*pFunc)(long *);

void ordenarNumeros(double num[], int cantidad, pFunc getRandom);
void visualizar(double v[], int ne);

int main(void)
{
    pFunc r = rnd;
    double numeros[6] = {0};
    int cantidad = 6;
    ordenarNumeros(numeros, cantidad, r);
    visualizar(numeros, cantidad);
    return 0;
}

void ordenarNumeros(double num[], int cantidad, pFunc getRandom)
{
    long prandom = 10; // Semilla inicial
    for (int i = 0; i < cantidad; i++)
    {
        int unique = 0;
        while (!unique)
        {
            unique = 1;
            double nuevoNumero = getRandom(&prandom);
            for (int j = 0; j < i; j++)
            {
                if (num[j] == nuevoNumero)
                {
                    unique = 0;
                    break;
                }
            }
            if (unique)
            {
                num[i] = nuevoNumero;
            }
        }
    }

    int i, k;
    double x;
    for (i = 1; i < cantidad; i++)
    {
        x = num[i];
        k = i - 1;
        while (k >= 0 && num[k] > x)
        {
            num[k + 1] = num[k];
            k--;
        }
        num[k + 1] = x;
    }
}

void visualizar(double v[], int ne)
{
    int i;
    for (i = 0; i < ne; i++)
        printf("%g ", v[i]);
    printf("\n");
}
