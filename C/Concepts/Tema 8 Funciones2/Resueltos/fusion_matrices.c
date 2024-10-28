/*
    Realizar un programa que, partiendo de dos matrices de cadenas de caracteres ordenadas en orden ascendete, construya y visualice
    una tercera matriz tambien ordenada en orden ascendente. La idea que se persigue es construir la tercera lista ordenada, no 
    construirla y despues ordenarla mediante una función.

    Para ello la funcion main proporcionará las dos matrices e invocará una funcion cuyo prototipo será el siguietne:

    int fusionar(char **, int, char **, int, char **);

    El primer parametro de la funcion fusionar es una de las matrices de partida y el segundo parametro indica su numero de elementos,
    El parametro tercero es otra de las matrices de partida y el cuarto parametro su numero de elementos; y el quinto parametro
    es la matriz que almacenará los elementos de las dos anteriores.  

    El proceso de fusión consiste en:

    a)Partiendo de que ya estan construidas las dos matrices de partida, tomar un elemento de cada una de las matrices.
    b)comparar los dos elementoos (uno de cada matriz) y almacenar en la matriz resultado el menor
    c)Tomar el siguiente elemento de la matriz a la que pertenecia el elemento almacenado en la mtris resultado y volver al punto b).
    d)Cuando no queden más elementos en una de las dos matrices de aprtida, se copian directamente en la matriz resultado todso los elementos
    que queden en la otra matriz.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXFILAS 5

int fusionar(char **, int, char **, int, char **);
char **leerMatriz(int);
void visualizarMatriz(char **, int );
void liberarMatriz(char **matriz, int nFilas);
void ordenarMatriz(char **,int );
char *readString(char *str,int n);

int main(void)
{
    int correcto=0, nFilasA=0, nFilasB=0;

    do
    {
        printf("Define el numero de filas que tendran la matriz A:  ");
        correcto=scanf("%d",&nFilasA);
        while(getchar() != '\n');
    } while (!correcto || nFilasA<0 ||nFilasA>MAXFILAS);
    
    do
    {
        printf("Define el numero de filas que tendran la matriz B:  ");
        correcto=scanf("%d",&nFilasB);
        while(getchar() != '\n');
    } while (!correcto || nFilasB<0 ||nFilasB>MAXFILAS);

    printf("Matriz A\n");
    char **matrizA=leerMatriz(nFilasA);
    printf("Matriz B\n");
    char **matrizB=leerMatriz(nFilasB);

    printf("Matriz A\n");
    visualizarMatriz(matrizA, nFilasA);
    
    printf("\n\n");

    printf("Matriz B\n");
    visualizarMatriz(matrizB, nFilasB);

    printf("\n\n");


    char **matrizC=NULL;
    fusionar(matrizA, nFilasA, matrizB, nFilasB, matrizC);

    liberarMatriz(matrizA,nFilasA);
    liberarMatriz(matrizB,nFilasB);

}

char **leerMatriz(int nFilas)
{
    char **matriz;
    if((matriz=(char **)malloc(nFilas*sizeof(char *)))==NULL)
    {
        printf("No se ha podido asignar el espacio\n");
        return NULL;
    }

    char palabra[50];
    for (int i = 0; i < nFilas; i++)
    {
        do
        {
            printf("Escribe la %d palabra:  ",i);
        } while ((readString(palabra,50)) == NULL);
        
        matriz[i] = (char *)malloc((strlen(palabra) + 1) * sizeof(char));
        strcpy(matriz[i],palabra);
    }
    printf("\n");

    ordenarMatriz(matriz,nFilas);

    return matriz;
}

char *readString(char *str, int l)
{
    char *fin, *c;
    fin=fgets(str, l, stdin);
    if (c=strchr(str,'\n'))
        *c='\0';
    else if(!ferror(stdin))
        while ((getchar() != '\n'))
    return fin;
    
}

void visualizarMatriz(char **matriz, int nFilas)
{
    for (int i = 0; i < nFilas; i++)
    {
        printf("%s ",matriz[i]);
    }
       
}

void ordenarMatriz(char **matriz, int nFilas)
{
    char *temp;
    for (int i = 0; i < nFilas-1; i++)
    {
        for (int j = 0; j < nFilas-1-i; j++)
        {
            if(strcmp(matriz[j],matriz[j+1])>0)
            {
                temp=matriz[j];
                matriz[j]=matriz[j+1];
                matriz[j+1]=temp;
            }
        }
    }
    
    
}

void liberarMatriz(char **matriz, int nFilas)
{
    for (int i = 0; i < nFilas; i++)
    {
        free(matriz[i]);
    }
    
    free(matriz);
}

int fusionar(char **matrizA, int nFilas, char **matrizB, int nFilas2, char **matrizC)
{
    int nFilasC;
    
    char **temp;
    if(nFilas<nFilas2)
    {
        temp=matrizA;
        matrizA=matrizB;
        matrizB=matrizA;

        nFilasC=nFilas2;
    }
    else
        nFilasC=nFilas;

    matrizC=(char **)malloc(nFilasC*sizeof(char*));

    int i=0;
    for (int i = 0; i < nFilas2; i++)
    {
        if ((strcmp(matrizA[i],matrizB[i]))<0)
            matrizC[i]=matrizA[i];
        else
            matrizC[i]=matrizB[i];
        
    }
    for (i; i < nFilas; i++)
    {
       matrizC[i]=matrizA[i];
    }
    
    printf("Matriz C\n");
    visualizarMatriz(matrizC, nFilasC);
    liberarMatriz(matrizC, nFilasC);

}