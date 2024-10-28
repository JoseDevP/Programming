/*
    Función para ordenar alfabéticamente una matriz de cadenas de caracteres
    algoritmo="método de la burbuja":
    función burbuja(lista):
    n = longitud(lista)
    para i desde 0 hasta n-1:
        para j desde 0 hasta n-i-2:
            si lista[j] > lista[j+1]:
                intercambiar lista[j] con lista[j+1]

    Utilizar cadenas.c para leer y viusualizar una matriz de caracteres.
    Utilizando el metodo de la burbuja escribe una función ordenar que se ajuste a prototipo:
        void ordenar(char cad[][COLS_MAX],int nc);
*/
#include <stdio.h>
#include <string.h>
#define FILAS_MAX 100
#define COLS_MAX 40

void ordenar(char cad[][COLS_MAX],int nc);
char *readString(char *str, int n);

int main(void)
{
    char cadena[FILAS_MAX][COLS_MAX];
    int nFilas = 0;
    int fila = 0, r = 0;
    char *fin, respuesta;   
    do
    {
      printf("N�mero de filas de la matriz:  ");
      r = scanf("%d", &nFilas);
      while (getchar() != '\n'); // limpiar '\n'
    } while (nFilas < 1 || nFilas > FILAS_MAX || r == 0);   
    printf("Escriba los nombres que desea introducir.\n");
    printf("Puede finalizar introduciendo la marca EOF.\n");
    for (fila = 0; fila < nFilas; fila++)
    {
      printf("Cadena[%d]: ", fila);
      fin = readString(cadena[fila], COLS_MAX);
      // Si se puls� [Ctrl][z], salir del bucle
      if (fin == NULL) break;
    }
  
    ordenar(cadena,nFilas);

    puts("\nCadena ordenada:\n");
    for (int i = 0; i < nFilas; i++)
    {
        printf("%s\n",cadena[i]);
    }
    

}

char *readString(char *str, int n)
{
  char *fin, *c = 0;
  fin = fgets(str, n, stdin);
  if (c = strchr(str, '\n'))
    *c = 0; // reemplazar '\n'
  else if (!feof(stdin))
    while (getchar() != '\n'); // limpiar buffer stdin
  return fin;
}

void ordenar(char cad[][COLS_MAX],int nc)
{
    char temp[COLS_MAX];
    for (int i = 0; i < nc-1; i++)
    {
        for (int j = 0; j < nc-1-i; j++)
        {
            if(strcmp(cad[j],cad[j+1])>0)
            {
                strcpy(temp,cad[j]);
                strcpy(cad[j],cad[j+1]);
                strcpy(cad[j+1],temp);
            }
        }
    }
    
}