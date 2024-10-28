/*Programa qye lea y almacene una lista de valores introducida por el teclado.
Una vez leida, buscará los valores máximo y mínimo, y los imprimirá*/
//leer  lista de valores
//Buscar maximo y minimo
#include <stdio.h>
#define NMAX 100

int main(void)
{
    float dato[NMAX];
    float max, min;
    int nElementos=0;
    int i=0;

    printf("Introducir datos.Para finalizar introducir la marca EOF\n");
    printf("dato[%d] = ",i);

    while (i< NMAX && scanf("%f",&dato[i])!=EOF)
    {
        i++;
        printf("datp[%d]= ",i);
    }
    
    nElementos=i;

    if(nElementos>0)
    {
        max=min=dato[0];
        for (int i = 0; i < nElementos; i++)
        {
            if(dato[i]>max)
                max=dato[i];
            if(dato[i]<min)
                min=dato[i];
        }
        printf("Valor máximo %g y valor minimo %g",max,min);
        
    }


}