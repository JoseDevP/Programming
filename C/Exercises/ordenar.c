/*Punteros a Funciones*/

#include <stdio.h>

typedef int (*t_comparar)(double,double);

int compararDosElementos(double x, double y)
{
    return x > y; 
}

void ordenar(double v[], int nElementos, t_comparar comparar);
void visualizar(double v[], int ne);

int main(void)
{
    double x[]={1, 3, 5, 7, 2, 4, 6};

    t_comparar delegado = compararDosElementos;
    ordenar(x, sizeof(x)/sizeof(double), delegado);
    visualizar(x, sizeof(x)/sizeof(double));

}

void ordenar(double vector[], int nElementos, t_comparar comparar)
{
    int i, k;
    double x;

    for (int i = 1; i < nElementos; i++)
    {
        x=vector[i];
        k=i-1;
        while (k >= 0 && comparar(x, vector[k]))
        {
            vector[k+1]=vector[k];
            k--;
        }
        vector[k+1]=x;
    }
    
}

void visualizar(double v[], int ne)
{
    int i;
    for (int i = 0; i < ne; i++)
        printf("%g ",v[i]);
    printf("\n");
    
}