/*Puntero que apunta a otro puntero*/

#include <stdio.h>

void leerMatriz(int **q, int f, int c)
{
    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("Elemento [%d][%d]: ",i,j);
            //scanf("%d",&q[i][j]);
            scanf("%d",*(q+i)+j);
            //q+i-> como q es p, q+i hace referencia a p[0]+i o sea p[i]
            //que seria a[i] y port tanto q[i]
            //*q[i]=&q[i][0]
            //&q[i][0]+j->&q[i][j]
        }   
    }
}

void visualizarMatriz(int **q,int f, int c)
{
    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < c; j++)
            //printf("%7d",q[i][j]);
            printf("%7d",*(*(q+i)+j));
            //*(q+i)+j->&q[i][j]
            //*(&q[i][j])
        printf("\n");
    }
}

int main(void)
{
    int a[5][5];
    int *p[5];
    //int *(*q)[5]=&p;
    for (int i = 0; i < 5; i++)
        p[i]=a[i];
    
    leerMatriz(p,5,5);
    visualizarMatriz(p,5,5);

}