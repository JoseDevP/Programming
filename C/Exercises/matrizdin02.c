/* Matriz dinámica de dos dimensiones*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>

void **asignarMemoriaMatriz2D(int nFilas, int nCols, size_t tamElemento);
void liberarMemoriaMatriz2D(void **pm, int nFilas);
void mostrarMatriz(int **pm, int nFilas, int nCols);

int main(void)
{
    int **m=NULL;
    int nFilas=0, nCols=0;
    int correcto=0;

    do
    {
        printf("Número de filas de la matriz:   ");
        correcto=scanf("%d",&nFilas);
        while(getchar() != '\n');
    } while (!correcto || nFilas <1);
    
    do
    {
        printf("Número de columnas de la matriz:   ");
        correcto=scanf("%d",&nCols);
        while(getchar() != '\n');
    } while (!correcto || nCols <1);
    
    m=(int **)asignarMemoriaMatriz2D(nFilas,nCols,sizeof(int));
    if(m==NULL)
    {
        printf("Insuficiente espacio de memoria\n");
        return -1;
    }

    mostrarMatriz(m,nFilas,nCols);

    liberarMemoriaMatriz2D((void **)m,nFilas);

    return 0;

}

void **asignarMemoriaMatriz2D(int nFilas, int nCols, size_t tamElemento)
{
    void **p=0;
    p=(void **)malloc(nFilas * sizeof(void *));
    if(p==NULL) return NULL;

    for (int i = 0; i < nFilas; i++)
    {
        p[i]=malloc(nCols*tamElemento);
        if(p[i] == NULL)
        {
            liberarMemoriaMatriz2D(p,i);
            return NULL;
        }
        memset(p[i],0,nCols*tamElemento);
    }
    return p;
}

void liberarMemoriaMatriz2D(void **pm, int nFilas)
{
    for (int f = 0; f < nFilas; f++)
        free(pm[f]);
    free(pm);
    
}

void mostrarMatriz(int **pm, int nFilas, int nCols)
{
    for (int f = 0; f < nFilas; f++)
    {
        for (int c = 0; c < nCols; c++)
            printf("%d ",pm[f][c]);
        printf("\n");
        
    }
    
}