/*
    Matrices dinámicas Dimensionales
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void visualizar(double *, int);

int main(void)
{
    int elems=6;

    double *m=(double *)malloc(elems*sizeof(double));
    if( m == NULL)
    {
        printf("Insuficiente memoria\n");
        return -1;
    }

    memset(m,0,elems*sizeof(double));

    visualizar(m,elems);

    free(m);
    exit(0);
}

void visualizar(double *x, int elems)
{
    for (int i = 0; i < elems; i++)
    {
        printf("%5g",x[i]);
        printf("\n");
    }
    
}