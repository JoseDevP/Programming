/* 
    El calculo de los numeros de Fibonacci es un ejemplo de una defincion matematica
    recursiva que se enuncia asi:
    el número de Fibonacci f(i) siendo i el numero de orden (0,1,2,3,4,5...)
    del numero a calcular, es igual a al numero de fibonacci f(i-1) mas el numero
    de fibonacci f(i-2) sabiendo que f(0) es 0 y f(1) 1;

    Programa que pregunte cuantos numero de Fibonacci quiere calcular.
    Almacene esos numeros en una matriz del tamaño necesario
    Muestre los numeros.

        int fibonacci(int n);
    
    La funcion fibonacci devolvera como resultado el numero de Fibonacci cuyo 
    numero de orden (0,1,2...)sea n
*/

#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n);

int main(void)
{
    int correcto=0, n=0, f=0;
    do
    {
        printf("Introduce cuantos numeros de fibonacci quiere calcular: ");
        correcto=scanf("%d",&n);
    } while (!correcto || n<0);

    int *numsFibo=(int *)malloc(n*sizeof(int));

    if (numsFibo == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        numsFibo[i] = fibonacci(i);
        printf("Fibonacci(%d) = %d\n", i, numsFibo[i]);
    }

    free(numsFibo); 
    return 0;
    
}

int fibonacci(int n)
{
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return 1;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}