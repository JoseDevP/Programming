/*Copiar una matriz en otra*/
#include <stdio.h>
#define FILAS 2
#define COLS 3

void CopiarMatriz(void *dest,void *orig,int n);

int main(void)
{
    int m1[FILAS][COLS]={24,30,15,45,34,7};
    int m2[FILAS][COLS];

    CopiarMatriz(m2,m1,sizeof(m1));

    for (int f = 0; f < FILAS; f++)
    {
        for (int c = 0; c < COLS; c++)
            printf("%d ",m2[f][c]);
        printf("\n");
        
    }
    
}

void CopiarMatriz(void *dest,void *orig,int n)
{
    char *destino=(char *)dest;
    char *origen=(char *)orig;

    for (int i = 0; i < n; i++)
    {
        destino[i]=origen[i];
    }
    
}