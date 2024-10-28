#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define FILAS_MAX 100
#define COLS_MAX 40

char* readString(char*,int);

int main(void)
{
    char nombre[FILAS_MAX][COLS_MAX];
    int nFilas=0;
    int fila=0,r=0;
    char* fin,respuesta;

    do
    {
        printf("Numero de filas de la matriz: ");
        r=scanf("%d",&nFilas);
        while(getchar()!='\n');
    } while (nFilas<1 || nFilas > FILAS_MAX || r==0);

    printf("Escriba los nombres que desea introducir.\n");
    printf("Puede finalizar introduciendo la marca EOF\n");
    for (fila = 0; fila < nFilas; fila++)
    {
        printf("Nombre[%d]: ",fila);
        fin=readString(nombre[fila],COLS_MAX);
        if(feof(stdin) || ferror(stdin) || fin==NULL)
        {
            break;
        }
    }

    nFilas=fila;

    do
    {
        printf("¿Desea visualizar el contenido de la matriz? (s/n): ");
        respuesta=tolower(getchar());
        while(getchar()!='\n');
    } while (respuesta!='s' && respuesta!='n');
    
    if(respuesta=='s')
    {
        printf("\n");
        for (fila = 0; fila < nFilas; fila++)
        {
            printf("%s\n",nombre[fila]);
        }
        
    }
    
    
}

char* readString(char* str,int n)
{
    char* fin, *c=0;
    fin=fgets(str,n,stdin);
    if (c=strchr(str,'\n')) *c=0;
    else if (!feof(stdin))
    {
        while (getchar()!='\n');
    }
    return fin;
    
}
