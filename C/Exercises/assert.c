/*
    Escribir una macro ASSERT(expresion) cuyo comportamiento sea el siguiente: si al evaluar la
    la expresion el resultado es 0, la macro no imprimira un mensaje de diagnostico y abortara
    el programa; en otro caso, no hara nada.

    Realizar un progrma que utilice la macro anterior para verificar que los indices de una matriz
    esten dentro de los limites permitidos
*/

#include <stdio.h>
#include <stdlib.h>
#define N 10

#define ASSERT(expresion_de_bool)\
if(!(expresion_de_bool))\
{\
    printf("%s(%d):Indice Fuera de limites\n",__FILE__,__LINE__);\
    exit(0);\
}

int main(void)
{
    int a[N], i=0;

    printf("Indice del elemento que se quiere modificar ");
    scanf("%d",&i);
    ASSERT(i>=0 && i<N);

    printf("a[i]= ");scanf("%d",&a[i]);
}