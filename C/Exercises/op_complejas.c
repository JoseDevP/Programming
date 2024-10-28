/*Operaciones con complejos: test.c*/
#include <stdio.h>
#include "op_complejas.h"

int main(void)
{
    tcomplejo c1,c2,c3;

    c1=leerComplejo();
    c2=leerComplejo();
    c3=sumarComplejos(c1,c2);

    printf("La suma es: ");
    mostrarComplejo(c3);
    c3=multiplicarComplejos(c1,c2);
    printf("\nEl producto es: ");
    mostrarComplejo(c3);
    printf("\n");
}

tcomplejo leerComplejo()
{
    tcomplejo c={0.0F,0.0F};
    int r=0;

    printf("Introducir complejo de la forma: x yj\n");
    do
    {
        r=scanf("%f %f", &c.r, &c.i);
        while(getchar()!='\n');
    } while (r != 2);
    return c;
    
}

void mostrarComplejo(tcomplejo c)
{
    printf("%8.2f%+8.2fj",c.r,c.i);
}

tcomplejo multiplicarComplejos(tcomplejo a, tcomplejo b)
{
    tcomplejo c;
    c.r=a.r*b.r -a.i*b.i;
    c.i=a.r*b.i +a.i*b.r;
    return c;
}

tcomplejo sumarComplejos(tcomplejo a, tcomplejo b)
{
    tcomplejo c;
    c.r=a.r+b.r;
    c.i=a.i+b.i;
    return c;
}