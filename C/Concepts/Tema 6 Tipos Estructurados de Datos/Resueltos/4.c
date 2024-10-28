/*
    Programa para operar con matrices de numeros complejos
    Estrucuras de datos a manejar:

    #define MAX 10

    typedef struct
    {
        float r; //parte real de numero complejo
        float i;//parte imaginaria
    }tcomplejo;

    typedef struct
    {   
        int filas;   //Filas matriz
        int columnas;//Columnas matriz
        tcomplejo c[MAX][MAX];
    }tmatriz;

    a)Escribe una funcion para leer una matriz
        tmatriz LeerMatriz();
        Esta solicita num de filas y columnas de la matriz y todos sus elementos
    b)Funcion que visualize una matriz determinada.
        void VisualizarMatriz(tmatriz m)
    c)Escribir una funcion para multiplicar dos matrices.
        tmatriz Multiplicar(tmatriz a, tmatriz b);
        para invocarla:
            tmatriz a,b,c;
            //...
            c=Multiplicar(a,b);
    d)Utilizando las funciones anteriroes escribir programa que lea dos matrics y visualize el producto


*/
#include <stdio.h>
#include "4.h" //utilizar.h para defindiciones

int main(void)
{
    tmatriz a=LeerMatriz();
    VisualizarMatriz(a);
    puts("\n\n");
    tmatriz b=LeerMatriz();
    VisualizarMatriz(b);
    puts("\n\n");
    puts("Suma de matrices a y b:");
    tmatriz c=sumarMatrices(a,b);
    VisualizarMatriz(c);
    puts("\n\n");
    puts("Multiplicación de matrices a y b:");

}

tmatriz LeerMatriz()
{
    tmatriz matriz;
    //Esta solicita num de filas y columnas de la matriz y todos sus elementos
    int r=0;
    do
    {
        printf("Introduce el numero de filas:");
        r=scanf("%d",&matriz.filas);
    } while (matriz.filas<0 || matriz.filas>MAX || r!=1);
    do
    {
        printf("Introduce el numero de columnas:");
        r=scanf("%d",&matriz.columnas);
    } while (matriz.columnas<0 || matriz.columnas>MAX || r!=1);
    
    while(getchar()!='\n');
    
    for (int i = 0; i < matriz.filas; i++)
    {
        for (int j = 0; j < matriz.columnas; j++)
        {
            printf("Introduce los valores para r+ij en matriz[%d][%d]\n",i,j);
            do
            {
                r=scanf("%f %f",&matriz.c[i][j].r,&matriz.c[i][j].i);
                if(r!=2)
                    while(getchar()!='\n');
            } while (r!=2);
            
        }   
    }
    return matriz;

}

void VisualizarMatriz(tmatriz m)
{
    for (int i = 0; i < m.filas; i++)
    {
        for (int j = 0; j < m.columnas; j++)
        {
           printf("%g+%gj en matriz[%d][%d]\n",m.c[i][j].r,m.c[i][j].i,i,j);
        }
    }
    
}


tmatriz sumarMatrices(tmatriz a, tmatriz b)
{
    tmatriz c;
    c.filas=a.filas;
    c.columnas=a.columnas;
    for (int i = 0; i < a.filas; i++)
    {
        for (int j = 0; j < a.columnas; j++)
        {
           c.c[i][j].r=a.c[i][j].r+b.c[i][j].r;
           c.c[i][j].i=a.c[i][j].i+b.c[i][j].i;
        }
    }
    return c;
}