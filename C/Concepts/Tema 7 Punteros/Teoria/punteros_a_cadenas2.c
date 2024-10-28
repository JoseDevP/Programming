/*
    El objetivo de este ejercicio es leer una serie de cadenas de caracteres, almacenarlas
    en una matriz y luego ordenarlas en orden alfabético utilizando el algoritmo de ordenamiento
    por burbuja. Finalmente, mostrar las cadenas ordenadas en la consola.

Requisitos:
Leer CADS cadenas de caracteres de hasta TCAD-1 caracteres cada una.
Almacenar estas cadenas en una matriz de caracteres.
Ordenar las cadenas en orden alfabético utilizando el algoritmo de ordenamiento por burbuja.
Mostrar las cadenas ordenadas.
*/
#include <stdio.h>
#include <string.h>
#define FILA 5
#define COL 100

char *leer(char *str, int n);
void leerCadena(char **q, int f);
void mostrarCadenas(char **q, int f);
void ordenarCadenas(char **str, int f);


int main(void)
{
    char cadena[FILA][COL];
    char *p[FILA];

    for (int i = 0; i < FILA; i++)
    {
        p[i]=cadena[i];
    }
    
    leerCadena(p,FILA);
    ordenarCadenas(p,FILA);
    printf("\n");
    printf("\n");
    mostrarCadenas(p,FILA);

}

char *leer(char *str, int n)
{
    char *fin,*c=0;
    fin=fgets(str,n,stdin);
    if(c=strchr(str,'\n'))
        *c='\0';
    else if(!feof)
        while(getchar() != '\n');
    return fin; 
}

void leerCadena(char **q, int f)
{
    for (int i = 0; i < f; i++)
    {
        printf("Cadena [%d]: ",i);
        leer(q[i],COL);
    }
    
}

void mostrarCadenas(char **q, int f)
{
    for (int i = 0; i < f; i++)
        printf("%s\n",q[i]);
}

void ordenarCadenas(char **str, int f)
{
    char *temp;
    for (int i = 0; i < f-1; i++)
    {
        for (int j =f-1-i; j >i; j--)
        {
            if(strcmp(str[j],str[j-1])<0)
            {
                temp=str[j];
                str[j]=str[j-1];
                str[j-1]=temp;
            }
                
        }
    }
    
}