/*
    Realizar un programa que elea un conjunto de valores reales a través del teclado,
    los almcene en una matriz dinamica de m filas por n columnas, y a continuación 
    visualize esta matriz por filas.

    La estructura del programa esta formada, además de por la funcion main, por las
    funciones siguientes:

        void leer(float **m, int fi, int col);

    Esta matriz se creará dinamicamente invocando a la función:
        float **AsigMem(int fi, int col)
    
*/

#include <stdio.h>
#include <stdlib.h>

void leer(float **m, int fi, int col);
void visualizar(float **m, int fi, int col);
float **AsigMem(int fi, int col);
void liberarMemoria(float ***cadena,int, int);

int main(void)
{
    float **m; //puntero a array de punteros
    int correcto=0, fi=0, col=0;
    do
    {
        printf("Filas: ");
        correcto=scanf("%d",&fi);
        while(getchar() != '\n');
    } while (!correcto || fi<0);

    do
    {
        printf("Columnas: ");
        correcto=scanf("%d",&col);
        while(getchar() != '\n');
    } while (!correcto || col<0);
    
    m=AsigMem(fi,col);

    leer(m, fi, col);

    visualizar(m, fi, col);

    liberarMemoria(&m, fi, col);
}

void leer(float **m, int fi, int col)
{
    int correcto=0;
    for (int i = 0; i < fi; i++)
    {
        for (int j = 0; j < col; j++)
        {
            do
            {
                printf("m[%d][%d]  ",i,j);
                correcto=scanf("%f",&m[i][j]);
                while(getchar() != '\n');
            } while (!correcto);
            
        }
        
    }
    
}

void visualizar(float **m, int fi, int col)
{
    for (int i = 0; i < fi; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%.2f ",m[i][j]);   
        }
        printf("\n");
    }
}

float **AsigMem(int fi, int col)
{
    float **m=NULL;
    if((m=(float **)malloc(fi*sizeof(float *)))==NULL)
    {
        printf("No se ha podido asignar la memoria\n");
        exit(1);
    }

    for (int i = 0; i < fi; i++)
    {
        if((m[i]=malloc(col*sizeof(float)))==0)
        {
            printf("No se ha podido asignar la memoria\n");
            exit(1);
        }
    }
    
    return m;

}

void liberarMemoria(float ***cadena,int fi, int col)
{
    for (int i = 0; i < fi; i++)
    {
        free((*cadena)[i]);    
    }
    free((*cadena));   
}