/**Suma de las filas de una matriz bidimensional**/

#include <stdio.h>
#define FILAS_MAX 10
#define COLS_MAX 10

int main(void)
{
    float m[FILAS_MAX][COLS_MAX];
    float suma_fila;
    int filas,cols;
    int fila,col;

    do
    {
        printf("Número de filas de la matriz: \n");
        scanf("%d",&filas);
    } while (filas<1 ||filas>FILAS_MAX);
    
    do
    {
        printf("Numero de columnas de la matriz");
        scanf("%d",&cols);
    } while (cols < 1 || cols > COLS_MAX);

    float resultados[filas];
    printf("Introducir los valores de la matriz.\n");
    for (fila = 0; fila < filas; fila++)
    {
        resultados[fila]=0;
        for (col = 0; col < cols; col++)
        {
            printf("m[%d][%d] =",fila,col);
            scanf("%f",&m[fila][col]);
            resultados[fila]+=m[fila][col];
        }
        printf("Suma de la fila %d = %g\n",fila,resultados[fila]);
    }
        
}