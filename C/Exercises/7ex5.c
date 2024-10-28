/*
    Almacenar matriz bidimensional que generalmente tiene muchos elementos nulos (matriz
     sparse) se puede utilizar una matriz dimensional en la que solo se guarden los elementos
     no nulos precedidos por sus indices,fila y columna, lo que redunda en aprovechamiento
     de espacio
     Ej:
        6 0 0 0 4
        0 5 0 0 2
        2 0 0 0 0
        0 0 7 0 0 
        0 0 0 8 0

    se guarda en una matriz asi:
  fila
    |columna
    | |valor
    | | |        
    0 0 6 /0 4 4 /1 1 5/ 1 4 2/ 2 0 2/ 3 2 7/ 4 3 8 

    para trabajar con esta matriz utilizaremos la siguiente declaracion:

    typedef int tMatrizU[300];

    a)Escribir una funcion que lea una matriz bidimensional por filas y la almacene
    en una matriz m de tipo tMatrizU.

    int CrearMatrizUni(tMatrizU m, int fi ,int co); fi y co: filas y columnas

    b)Escribir una función que permita representar en pantalla la matriz bidimensional
    por filas y columnas.

    int Visualizar(int f,int c, tMatrizU m, int n);

    f y c: fila y columna del elemento que se visuazliza
    n indica el numero de elementos no nulos de la matriz bidimensional
*/

#include <stdio.h>
#include <string.h>

typedef int tMatrizU[300];

int CrearMatrizUni(tMatrizU m, int fi ,int co);
int Visualizar(int f,int c, tMatrizU m, int n);

int main(void)
{
    int nFilas=0;
    int nColumnas=0;

    tMatrizU matriz;

    printf("N filas:\n");
    scanf("%d",&nFilas);

    printf("N columnas:\n");
    scanf("%d",&nColumnas);

    int nVacio=CrearMatrizUni(matriz,nFilas,nColumnas);

    printf("\n\n");

    Visualizar(nFilas,nColumnas,matriz,nVacio);

}

int CrearMatrizUni( tMatrizU m, int fi, int co)
{
  int Num, n = 0; 
  for (int i = 0; i < fi; i++)
  {
    for (int j = 0; j < co; j++)
    {
      Num = 0;
      printf("M[%d][%d] = ", i, j);
      scanf("%d", &Num);
      if (Num != 0)
      {
        m[n*3] = i;
         m[n*3+1] = j;
          m[n*3+2] = Num;
        n++; 
      }
      if( n*3 >= 300)
      {
        printf("\n Matriz llena!\n");
        return n;
      }
    }
  }
  for (int i = 0; i < n*3; i++)
  {
      printf("%d" ,m[i]);
  }  
  return n;
}

int Visualizar(int f,int c, tMatrizU m, int n)
{
    int matriz[f][c];
    memset(matriz,0,sizeof(matriz));
    for (int i = 0; i < n; i++)
    {
        matriz[m[i*3]][m[i*3+1]]=m[i*3+2];
    }

    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}