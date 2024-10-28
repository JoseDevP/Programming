/*Medir tiempos de ejecucion*/

#include "tiempo.h"

int main(void)
{
    register unsigned long i;
    float k;

    T_INICIAL(bucle con variable register unsigned long);
        for (i = 0; i < 10000000; i++)
    T_FINAL;

    T_INICIAL(bucle con variable float);
        for ( k = 0; k < 10000000; k++)
    T_FINAL;
    
}