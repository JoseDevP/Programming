/* Matriz dinámica de cadenas de caracteres*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

char *readString(char *str, int n);
int leerCadenas(char **nombre,int nFilas);
void ordenarCadenas(char **nombre,int filas);
void visualizarCadenas(char **nombre,int filas);
void liberarMemoria(char **nombre,int filas);

int main(void)
{
    setlocale(0,"");
    char **nombre= NULL;
    int nFilas=0;
    int correcto=0,filas=0;
    do
    {
        printf("Numero de filas de la matriz:    ");
        correcto=scanf("%d",&nFilas);
        while(getchar() != '\n');
    } while (!correcto || nFilas<1);
    
    if((nombre=(char **)malloc(nFilas*sizeof(char *))) == NULL)
    {
        printf("Insuficiente espacio en la memoria");
        return 0;
    }

    filas=leerCadenas(nombre,nFilas);

    if(filas == 1) return -1;

    printf("\n\n");

    ordenarCadenas(nombre,filas);

    visualizarCadenas(nombre,filas);

    return 0;

}

char *readString(char *str, int n)
{
    char *fin, *c;
    fin=fgets(str,n,stdin);
    if((c=strchr(str,'\n')))
        *c=0;
    else if(!feof(stdin))
        while(getchar() != '\n');
    return fin;
}

int leerCadenas(char **nombre,int nFilas)
{
    int f=0, longitud=0;
    char cadena[81];
    printf("Introducir cadenas de caracteres\n");
    printf("Para finalizar introduzca una cadena nula\n");
    printf("Esto es, pulse solo <Entrar>.\n\n");

    while (f<nFilas && (longitud =strlen(readString(cadena,81)))>0)
    {
        if((nombre[f] = (char *)malloc(longitud + 1))==NULL) // longitud + caracter nulo
        {
            printf("Insuficiente espacio de memoria disponible\n");
            liberarMemoria(nombre,f);
            return -1;
        }
        strcpy(nombre[f],cadena);
        f++;
    }
    return f;
}

void ordenarCadenas(char **nombre,int filas)
{
    char *aux;
    int i=0, s=1;
    while ((s==1) && (--filas >0))
    {
        s=0;
        for (int i = 1; i <= filas; i++)
            if(strcmp(nombre[i-1],nombre[i]) >0)
            {
                aux = nombre[i-1];
                nombre[i-1]=nombre[i];
                nombre[i]=aux;
                s=1;
            }
        
    }
    
}

void visualizarCadenas(char **nombre,int filas)
{
    for (int i = 0; i < filas; i++)
        printf("%s\n",nombre[i]);
}

void liberarMemoria(char **nombre,int filas)
{
    for (int i = 0; i < filas; i++)
    {
        free(nombre[i]);
    }
    free(nombre);
    
}