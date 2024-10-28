/*
    La transformada discreta de Fourier (DFT) de una secuenciad e numeros (x[n]) se 
    define asi:
            N-1 
    X[k] =  E  x(n).e^-j*k*((2*pi)/2)*n;    n=0,1,...,N-1;  k=0,1,...,N-1 
            n=0
    x[n]E R(Cuerpo de los numeros reales)
    x[k]E C(Cuerpo de los numeros complejos)

    Se desea escribir un programa que calcule la DFT de una secuencia de números
    reales,

    a)Escribir las funciones
        complejo sumar(complejo a, complejo b);
        complejo multiplicar(complejo a, complejo b);

    para trabajar con números complejos definidos de la forma:

        typedef struct
        {
            double r, i; //Parte real e imaginaria
        }complejo;

    La funcion sumar devuelve un complejo resultado de sumar el complejo a y el 
    complejo b pasados como argumentos, y la funcion multiplicar devuelve el producto.

    b)Escribir una función que calcule la DFT. La declaración es:
        void DFT(complejo *X, double *x, int N);

    Tenga en cuenta las siguientes consideraciones:
    1. e^fx =cos(x) + j sen(x);
    2.Para efectuar los calculos se pueden utilizar las siguientes funciones 
    declaradas en el archivo de cabecera math.h: exp(x), cos(x), sin(x).
    3.pi=3.141592654.

    c)Escribir un programa que lea del archivo estandar de entrada una secuencia de 
    numeros reales y escriba en el archivo estandar de salida la secuencia correspondiente
    a la DFT
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct 
{
    double real, imag;
}complejo;

complejo sumar(complejo a, complejo b)
{
    complejo temp;
    temp.real=a.real+b.real;
    temp.imag=a.imag+b.imag;
    return temp;
}

complejo multiplicar(complejo a, complejo b)
{
    complejo temp;
    temp.real=a.real*b.real -a.imag *b.imag;
    temp.imag=a.real*b.imag+a.imag*b.real;
    return temp;
}

void DFT(complejo *X, double *x, int N)
{
    double t, pi=3.141592654;
    complejo a,b;

    for (int k = 0; k<N; k++)
    {
        X[k].real=0; X[k].imag=0;
        for (int n = 0; n < N; n++)
        {
            a.real=x[n]; a.imag=0;
            t=k * 2 *pi / N *n;
            b.real=cos(-t); b.imag=sin(-t);
            b=multiplicar(a,b);
            X[k]=sumar(X[k],b);
        }   
    }   
}

int main(void)
{
    complejo *X;
    double x;
    int N;

    printf("")
}