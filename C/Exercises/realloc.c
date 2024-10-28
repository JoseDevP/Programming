/*realloc.c*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int *p = NULL, *q = NULL;
    int nbytes=100;

    if((p=(int *)malloc(nbytes))==NULL)
    {
        printf("Insuficiente espacio de memoria\n");
        return -1;
    }
    printf("Se han asignado %d bytes de memoria\n",nbytes);

    //operaciones sobre el bloque de memoria
    //...

    //reasignar el bloque para que pueda contener mas datos
    nbytes*=2;
    if(nbytes==0)
    {
        free(p);
        printf("El bloque ha sido liberado\n");
        return -1;
    }

    q=(int *)realloc(p,nbytes); //puntero adicional para garantizar la conservacion del bloque origian
    if(q == NULL)
    {
        printf("La reasignación no ha sido posible\n");
        printf("Se conserva en el bloque original");
    }
    else
    {
        p=q;
        printf("Bloque reasignado\n");
        printf("Nuevo tamaño %d bytes\n",nbytes);
    }
    
    //operaciones
    //...

    free(p);
    printf("\nEl bloque ha sido liberado\n");
    exit;
}

