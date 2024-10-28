/*
    Escribir un programa para evaluar la expresion (ax + by)^n.
                n  (n) 
    (ax + by)^n=E  ( )*(ax)^n-k * (by);
               k=0 (k)

    (n)
    ( )=(n!)/(k!(n-k)!)
    (k)

    n!=n*(n-1)*(n-2)*...*2*1

    a)Escribir una función cuyo prototipo sea:
        long factorial(int n);
    La funcion factoria recibe como parametro un entero y devuelve su factorial

    b) Escribir una función con el prototipo:
        long combinaciones(int n, int k);
    La funcion combinaciones recibe como parametros dos enteros n y k, y devuelve como 
                          (n) 
    resultado el valor de ( ) .
                          (k)
    
    c)Escribir una función:
        double potencial(double base, int exponente);
    La funcion potencia recibe como parametros dos enteros, base y exponente
    y devuelve como resultado el valor de base^exponente.

    d)La funcion main leera los valores de a, b, n, x e y, y utilzando las funciones
    anteriores escribira como resultado el valor de (ax+by)^n; 
*/

#include <stdio.h>
#include <stdlib.h>

void leerEntero(char, int*);
long factorial(int n);
long combinaciones(int n, int k);
double potencial(double base, int exponente);

int main(void)
{
    int a=0, b=0, n=0, x=0, y=0;
    leerEntero('a', &a);
    leerEntero('b', &b);
    leerEntero('n', &n);
    leerEntero('x', &x);
    leerEntero('y', &y);

    //Calculo
    double *funcion=(double *)malloc(n*sizeof(double));
    for (int i = 0; i <= n; i++)
    {
        funcion[i]=combinaciones(n, i) * potencial((a*x),(n-i)) * potencial((b*y),i);
        printf("Para k = %d:\n",i);
        printf("Termino = %.2lf\n",funcion[i]);
    }
    double resultado=0;
    for (int i = 0; i <= n; i++)
    {
        resultado+=funcion[i];
    }
    printf("Resultado de (ax +by)^%d=%.2lf ",n,resultado);
    
}

void leerEntero(char nombre, int *entero)
{
    int correcto=0;
    do
    {
        printf("Escribe el valor para %c:  ",nombre);
        correcto=scanf("%d",entero);
        while(getchar() != '\n');
    } while (!correcto);
}

long factorial(int n)
{
    if(n == 0 || n == 1)
    {
        return 1;
    }
    return n*factorial(n-1);
}

long combinaciones(int n, int k)
{
    return ((factorial(n)) / (factorial(k) * factorial(n-k)));
}

double potencial(double base, int exponente)
{
    if (exponente == 0) {
        return 1;  
    } else if (exponente < 0) {
        return 1 / potencial(base, -exponente);  
    } else {
        return base * potencial(base, exponente - 1);  
    }
}
