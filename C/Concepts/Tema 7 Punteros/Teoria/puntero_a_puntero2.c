/*Puntero a puntero 2*/

#include <stdio.h>

int main(void)
{
    int a[5][5];
    
    int num=0;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            a[i][j]=num++;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%3d ",a[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");
    printf("\n");

    int *punt1[5];
    for (int i = 0; i < 5; i++)
    {
        punt1[i]=a[i];
    }

    int **punt2=punt1;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%3d ",punt2[i][j]);
        }
        printf("\n");

    }

    printf("\n");
    printf("\n");

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%3d ",*(*(punt2+i)+j));
        }
        printf("\n");

    }
}