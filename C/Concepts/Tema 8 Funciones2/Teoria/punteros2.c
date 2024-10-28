/*
    Matrices dinamicas Multidimensionales
*/

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void visualizar(double **,int,int);
int asignarMemoriaMatriz2D(void ***x, int filas, int cols, size_t size);
void liberarMemoriaMatriz2D(void **,int);

int main(void)
{
    int filas = 2, cols = 3;
    double **m = NULL;
    asignarMemoriaMatriz2D((void***)&m, filas, cols, sizeof(double));
    if(m==NULL)
    {
        printf("Insuficiente memoria\n");
        return -1;
    }

    visualizar(m,filas,cols);

    liberarMemoriaMatriz2D((void**)m,filas);
    return 0;
}

void visualizar(double **x, int filas, int cols)
{
    int f=0, c=0;
    for ( f = 0; f < filas; f++)
    {
        for ( c = 0; c < cols; c++)
        {
            printf("%5g",x[f][c]);
        }
    }
    
}

int asignarMemoriaMatriz2D(void ***x, int filas, int cols, size_t tamElemento)
{
    void **p=0;

    if((p=(void **)malloc(filas*sizeof(void *)))==NULL)
    {
        printf("Error al asignar memoria\n");
        return 0;
    }
    for (int i = 0; i < filas; i++)
    {
        if((p[i]=malloc(cols*tamElemento))==NULL)
        {
            printf("Error al asignar memoria\n");
            liberarMemoriaMatriz2D(p[i],filas);
            return 0;
        }
        memset(p[i],0,cols*sizeof(tamElemento));
    }   
    *x=p;

}

void liberarMemoriaMatriz2D(void ** m,int filas)
{
    for (size_t i = 0; i < filas; i++)
    {
        free(m[i]);
    }
    free(m);
    
}
