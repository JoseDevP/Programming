/*misFunciones.c*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "struc_fun.h"


int main(void)
{
    int filas=2, cols=3;
    tmatriz2D *m=NULL;
    m=AsignarMem2D(filas,cols);
    if(m->p==NULL)
    {
        printf("Insuficiente Memoria\n");
        return -1;
    }

    //Operaciones con la matriz
    //...

    AsignarDatos(m);

    Visualizar(m);

    LiberarMem2D(m);
    return 0;
}

tmatriz2D *AsignarMem2D(int filas, int cols)
{
    static tmatriz2D x;
    x.p=(double **)asignarMemoriaMatriz2D(x.filas,x.cols,sizeof(double));
    return &x;
}

void LiberarMem2D(tmatriz2D *x)
{
    liberarMemoriaMatriz2D((void **)x->p, x->filas);
}

void Visualizar(tmatriz2D *x)
{
    visualizar(x->p, x->filas, x->cols);
}

void AsignarDatos(tmatriz2D *x)
{
    for (int f = 0; f < x->filas; f++)
    {
        for (int c = 0; c < x->cols; c++)
        {
            printf("Elemento[%d][%d]: ",f, c);
            scanf("%lf",&x->p[f][c]);
        }
        
    }
    
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

void **asignarMemoriaMatriz2D( int filas, int cols, size_t tamElemento)
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
    
    return p;
}

void liberarMemoriaMatriz2D(void ** m,int filas)
{
    for (size_t i = 0; i < filas; i++)
    {
        free(m[i]);
    }
    free(m);
    
}

