/*
    Un algoritmo que genere una secuencia aleatoria o aparentemente aleatoria de numeros se 
    llama generador de numeros aleatorios. Muchos programas requieren de un algoritmo como este.
    El algoritmo más comunmente usado para generar números aleatorios es el de congruencia
    lineal que se enuncia de la forma siguiente:

        rk = (multiplicador *rk-1 +incremento) %módulo

    cada numero en la secuencia rk es calculado a partir de su predecesor rk-1. 
    %Es el operador modulo o resto de una division entera.
    Secuencia generada se llama secuencia seudoaleatoria(cada numero generado depende del anterior).

    rand de la biblitoteca de C esta basada ene este algoritmo.

    Ej:funcion algoritmo congruencia lineal genera aleatorio entre 0 y 1 y no causa sobrepasamiento
    en un ordenador que admita un rango de enteros de -2^31 a 2^31-1

    double rnd(long *prandom)
    {
        *prandom=(25173 * *prandom +13849) % 65536;
        return((double)*prandom / 65535);
    }

    obtiene un entero por referencia para que la funcion modifique el agumento con el 
    valor del ultimo numero seudoaleatorio en funcin del anteriro.
    
    numero seudoaleatorio calcula es valor entre 0 y 65535 y que para convertirlo a un valor
    entre 0 y 1 lo dividimos por 65535
    el cociente de tipo double es el valor devuelto por la funcion
*/
#include <stdio.h>
#include <time.h>

double rnd(long *prandom);

int main(void)
{
    long inicio=time(NULL) % 65536; //seed
    long random=inicio; //random =numero entre 0 y 65535
    double n;

    for (short i = 10; i; i--)
    {
        n=rnd(&random);
        printf("%.8g\n",n);
    }
    
}

double rnd(long *prandom)
{
    *prandom=(25173 * *prandom +13849) % 65536;
    return ((double)*prandom / 65535);
}

