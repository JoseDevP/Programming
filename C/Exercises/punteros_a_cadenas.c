/*
    Escribir el contenido de una matriz de cadenas de caracteres
*/

#include <stdio.h>
#include <string.h>
#define CADS 5
#define TCAD 81

char *readString(char *,int);

void leerCadenas(char **q,int f)
{
    for (int i = 0; i < f; i++)
    {
        printf("Cadena [%d]: ",i);
        readString(q[i],TCAD);
    }
    
}

void mostrarCadenas(char **q, int f)
{
    for (int i = 0; i < f; i++)
        printf("%s\n",q[i]);
}

int main(void)
{
    char cad[CADS][TCAD];
    char *p[CADS];

    for (int i = 0; i < CADS; i++)  //cada puntero p[i] apunta a cadena[i]
        p[i]=cad[i];

    leerCadenas(p,CADS);
    mostrarCadenas(p,CADS);   
}

char *readString(char *str ,int n)
{
    char *fin, *c=0;
    fin=fgets(str,n,stdin);
    if(c=strchr(str,'\n'))
        *c='\0';
    else if(!feof)
        while(getchar() != '\n');
    return fin;
}