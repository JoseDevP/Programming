/*
    Un cuadrado mágico se compone de números enteros comprendido entre 1 y n^2,
    donde n es un numero impar que indica el orden de la matriz cuadrada que contiene 
    los numeros que forman dicho cuadrado mágico. 
    La matriz que forma este cuadrado mágico cumple que la suma de los valores que componen
    cada fila, cada cilumna y cada diagonal es la misma.
    Ej: 
        Cuadrado magico de orden 3, n=3, implica una matriz de 3x3.
        Por lo tanto los valroes de la matriz estan entre 1 y 9 dispuesto asi=
            8   1   6
            3   5   7
            4   9   2

    Realizar un programa que visualice un cuadrado magico de orden impar n.
    El programa verificará que n es impar y esta comprendido entre 3 y 15.

    Una forma de construirlo es situra el numero 1 en el centro de la primera linea,
    el numero siguiente en la casilla situada encima  y a la derecha, y asi sucesivamente
    Es preciso tener en cuenta que el cuadrado se cierra sobre si mismo. 
    Es decir que la linea encima de lña primera es la ultima y la columna a la derecha
    de la ultima es la primera.

    Siguiendo esta regla, cuando el numero caiga en una casilla ocupada se elige la casilla 
    situada debajo del ultimo numero situado.

    a)Es_impar  Verifica si n es impar
    b)Cuadrado_mágico  Esta función construirá cuadrado mágico 
*/

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int Es_impar(int tamaño);
int **crearMatriz(int tamaño);
void Cuadrado_mágico(int **matriz, int tamaño);
void visualizarCuadrado(int **matriz, int tamaño);
void liberarMemoria(int **matriz, int tamaño);

int main(void)
{
    int **matriz;
    int tamaño=0, correcto=0;
    do
    {
        printf("Introduce el tamaño de la matriz\n");
        printf("Tiene que ser Impar\n");
        printf("Tamaño: ");
        correcto=scanf("%d",&tamaño);
        while(getchar() != '\n');
        system("cls");
    } while (Es_impar(tamaño) || !correcto  || tamaño<3 || tamaño>15);

    matriz=crearMatriz(tamaño);

    Cuadrado_mágico(matriz, tamaño);

    visualizarCuadrado(matriz, tamaño);

    liberarMemoria(matriz,tamaño);
    
}

int Es_impar(int tamaño)
{
    return(tamaño%2!=0);
}

void liberarMemoria(int **matriz, int tamaño)
{
    for (int i = 0; i < tamaño; i++)
    {
        free(matriz[i]);
    }
    free(matriz);

}

int **crearMatriz(int tamaño)
{
    int **matriz=NULL;
    if((matriz=(int **)malloc(tamaño*sizeof(int *)))==NULL)
    {
        printf("No se ha podido asignar el espacio de memoria de la matriz.\n");
        return NULL;
    }

    for (int i = 0; i < tamaño; i++)
    {
        if((matriz[i]=(int *)malloc(tamaño*sizeof(int)))==NULL)
        {
            printf("No se ha podido asignar el espacio de memoria de la matriz[i].\n");
            liberarMemoria(matriz,tamaño);
            return NULL;
        }
        memset(matriz[i],0,tamaño*sizeof(int));
    }
    return matriz;
}

void Cuadrado_mágico(int **matriz, int tamaño)
{
    int tamañoMax=tamaño*tamaño;
    int num=1, i=0, j=tamaño/2;

    matriz[i][j]=num;

    while (num < tamañoMax)
    {

        int newi = (i - 1 + tamaño) % tamaño; 
        int newj = (j + 1) % tamaño;          

        if (matriz[newi][newj] != 0) 
        {
           newi = (i + 1) % tamaño;
           newj = j;  
        }

        i = newi;
        j = newj;
        matriz[i][j]=++num;      
    }
    
}

void visualizarCuadrado(int **matriz, int tamaño)
{
    for (int i = 0; i < tamaño; i++)
    {
        for (int j = 0; j < tamaño; j++)
        {
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }
    
}