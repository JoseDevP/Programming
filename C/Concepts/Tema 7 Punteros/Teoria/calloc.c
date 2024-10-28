/*calloc.c*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *p=NULL;

    if((p=(int *)calloc(100,sizeof(int)))==NULL)
    {
        printf("Insuficiente espacio de memoria\n");
    }
    
    printf("Ha ocupado %zu bytes",(100*(sizeof(int))));

}