/*
    Se define f(t) como:

    f(t)={fe^-r^2 *d *t   si t>=0
         {      0         si t<0

    Programa que nos permita evaluar f(t)

    a)Funcion que permita evaluar el integrnado e^-r^2. El prototipo de
     esta funcion sera:

        double f(double t);
    
    Para implementarla se aconseja usar la funcion exp(t) que permite
     evaluar e^t y que se 
    encuentra en el archivo de cabecera math.h
        double(exp(double t))

    b)Funcion que genere numeros seudoaleatorios dentro de un determinado
     rango.
        double rnd(long &r)
    rnd cada vez que se invoque generara un numero seudoaleatorio entre 0
     y t.

    c)Escribir un programa que pida un valor de t y utilizando las 
    funciones anteriores
    calcule f(t)

    -La funcion e^-r^2 es positiva monótona decreciente. En 0 vale 1 y
     tiende a 0 cuando 
    t crece. La primitiva de esta funcion no se conoce:

    -La forma de solucionar este problema es análoga al cálculo del 
    volumen de una esfera
    realizado en elo apartado Ejercicios Resueltos.
*/
#include <stdio.h>
#include "math.h"

double f(double t);
double calcular_Funcion(int t, double f_val, double d, double r) ;
double rnd(long *prandom, int t);

int main(void)
{
    long random;
    int t=0, correcto=0;

    double f_val = 1.0; 
    double d = 1.0; 
    double r = 1.0;

    do
    {
        printf("Introduce un valor para t");
        correcto=scanf("%d",&t);
    } while (!correcto);
    
    if(t>=0)
    {
        double result = calcular_Funcion(t, f_val, d, r);
        printf("f(%d) = %f\n", t, result);
    }
    else if(t<0)
    {
        printf("El valor de t debe ser mayor o igual a 0.\n");
    }
    printf("%d",t);
}

double calcular_Funcion(int t, double f_val, double d, double r) 
{
    // Calcula e^(-r^2) usando la función f
    double exponential_part = f(r);
    // Calcula f(t)
    return f_val * exponential_part * d * t;
}

double f(double r)
{
    return exp(-r * r);
}


double rnd(long *prandom, int t)
{               
  *prandom = (25173 * *prandom + 13849) % 65536;
  return ((double) *prandom / 65535)*t;
}