/*Matriz Unidimensional*/


#include <stdio.h>
#define N_ELEMENTOS 10

int main(void)
{
    int m[N_ELEMENTOS];
    int i=0;

    for (int i = 0; i < N_ELEMENTOS; i++)
    {
        printf("m[%d]=",i);
        scanf("%d",&m[i]);
    }
    
    for (int i = 0; i < N_ELEMENTOS; i++)
    {
        printf("%d ",m[i]);
    }
    
}