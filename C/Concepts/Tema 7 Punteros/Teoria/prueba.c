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
    int **p;
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
    
    p=(int **)asignarMemoriaMatriz2D(nFilas,nCols,sizeof(int));
    if (p==NULL)
        return -1;

    mostrarMatriz(p,nFilas,nCols);

    liberarMemoriaMatriz2D((void **)p,nFilas);

    return 0;
    
}

void **asignarMemoriaMatriz2D(int nFilas, int nCols, size_t tamElemento)
{
    void **p;
    p=(void **)malloc(nFilas * sizeof(void *));
    if(p==NULL) return NULL;
    for (int i = 0; i < nFilas; i++)
    {
        if((p[i]=malloc(nCols*tamElemento))==NULL)
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
    for (int i = 0; i < nFilas; i++)
    {
        free(pm[i]);
    }
    
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