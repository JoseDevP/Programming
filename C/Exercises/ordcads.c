#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define CADS 6
#define TCAD 81

char *readString(char *str, int n);
int leerCadenas(char cad[][TCAD],char *pcad[],int nmc);
void ordenarCadenas(char *pcad[],int nc);
void visualizarCadenas(char *pcad[],int nc);

int main(void)
{
    setlocale(0,"");
    char cad[CADS][TCAD];
    char *pcad[CADS];
    int ncads=0;

    printf("Ordenación de cadenas de caracteres.\n");
    printf("Introduce las cadenas a ordenar.\n");
    printf("Pulse <Entrar> para salir. \n");

    if((ncads = leerCadenas(cad,pcad,CADS)) > 0)
    {
        printf("Cadenas leídas %d\n\n",ncads);
        printf("Proceso de ordenación.\n\n",ncads);
        ordenarCadenas(pcad,ncads);
        visualizarCadenas(pcad,ncads);
    }
    else
        printf("Matriz vacía\n");
        
}

char *readString(char *str, int n)
{
    char *fin, *c;
    fin=fgets(str,n,stdin);
    if(c=strchr(str,'\n'))
        *c='\0';
    else if(!feof(stdin))
        while(getchar() != '\n');
    return fin;
}

int leerCadenas(char cad[][TCAD], char *pcad[], int nmc)//nmc numero maximo cadenas
{
    int ncads=0;
    if(nmc<1) return -1;
    while (strlen(readString(cad[ncads],TCAD)) > 0)
    {
        pcad[ncads] = cad[ncads]; ncads++;
        if(ncads==nmc) break;
    }
    return ncads;
}

void ordenarCadenas(char *pcad[],int nc)
{
    char *aux=NULL;
    int i=0,s=1;
    while ((s==1) && (--nc>0))
    {
        s=0;
        for (int i = 1; i <= nc; i++)
            if(strcmp(pcad[i-1],pcad[i])>0)
            {
                aux=pcad[i-1];
                pcad[i-1] = pcad[i];
                pcad[i] = aux;
                s = 1;
            }
        
    }
    
}

void visualizarCadenas(char *pcad[],int nc)
{
    while (--nc >= 0)
    {
        printf("%s\n",*pcad++);
    }
    
}