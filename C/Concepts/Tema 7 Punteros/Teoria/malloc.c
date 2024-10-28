/*malloc.c*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *p=NULL;
    int nbytes=100;

    //p=(int *)malloc(nbytes);

    //// si no hay espacio malloc devuelve null
    //if((p==NULL)) 
    //{
    //    printf("Insuficiente espaci              o de memoria\n");
    //    return -1;
    //}

    if((p=(int *)malloc(nbytes)) ==NULL)
    {
        printf("Insuficiente espacio de memoria\n");
        return -1;
    }

    printf("Se han asignado %d bytes de memoria\n",nbytes);
    free(p);
    exit;

}