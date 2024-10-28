#include <stdio.h>
#include <stdlib.h>

void insercion(double list[],int n_elementos)
{
    double x;

    for (int i = 1; i < n_elementos; i++)
    {
        x=list[i];
        int k=i-1;
        while (k>=0 && x < list[k])
        {
            list[k+1]=list[k];
            k--;
        }
        list[k+1]=x;
        
    }
    
}

int main(void)
{
    int n_elementos=5;

    double m[]={3,2,1,5,4};

    insercion(m,5);

    for (int i = 0; i < n_elementos; i++)
        printf("%g",m[i]);
    printf("\n");

    /*
                            comparaciones           intercambios
    caso mas favorable      n-1                     2(n-1)
    caso medio              (n^2+n-2)/4             (n^2+9n-10)/4
    caso menos favorable    (n^2+n)/2-1             (n^2+3n-4)/2
    
    */
}