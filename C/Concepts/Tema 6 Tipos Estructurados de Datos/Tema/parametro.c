/* parametro */

#include <stdio.h>
void CopiarMatriz(int[], int[], int);
void VisualizarMatriz(int [], int);


int main(void)
{
    int x[]={10,20,30,40,50};
    int t=sizeof(x)/sizeof(int);
    int y[t];
    CopiarMatriz(y,x,t);
    VisualizarMatriz(y,t);
}

void CopiarMatriz(int destino[], int origen[], int n)
{
    //copiar b en a
    for (int i = 0; i < n; i++)
    {
        destino[i]=origen[i];
    }
    
}
void VisualizarMatriz(int m[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ",m[i]);
    }
    
}