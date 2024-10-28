/*
    Modifica el programa del ejercicio anterior para que la funcion insertarPalabra
    inserte cada nueva palabra en orden que le corresponde alfabeticamente, moviendo
    los elementos necesarios un lugar hacia atras. De esta forma al finalizar
    la entrada de datos ya saldrá ordenada.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *palabra;
    int contador;
}telem;

char *readString(char *str, int n);
int buscarPalabra(telem *a, char *palabra, int nPalabras);
void insertarPalabra(telem **a, char *palabra,int nPalabras);
void visualizarMatriz(telem *a, int nPalabras);

int main(void)
{
    telem *palabras=(telem *)malloc(sizeof(telem));
    if (palabras == NULL)
    {
        fprintf(stderr, "Error al asignar memoria.\n");
        exit(1);
    }

    int numPalabras=0;

    
    int indice=0;
    printf("Escribe una frase:\n");
    while (1)
    {
        char palabra[20];
        char c;
        indice=0;
        do
        {
            c=getchar();
            if(c != ' ')
            {
                palabra[indice++]=c;
            }
            
        } while ((c != ' ') && (c != '\n') && (c != EOF) && (indice<20));

        palabra[indice] = '\0';
        
        if(palabra[1] != '\0')
        {
            if((buscarPalabra(palabras,palabra,numPalabras))==0)
            {
                numPalabras++;
                insertarPalabra(&palabras, palabra,numPalabras);
            }
        }
        

        if((c == '\n') || (c == EOF))
        {
            break;
        }
    }      
    visualizarMatriz(palabras, numPalabras);

    //liberar memoria7
}

int buscarPalabra(telem *a, char *palabra, int nPalabras)
{
    for (int i = 0; i < nPalabras; i++)
    {
        if((strcmp(a[i].palabra, palabra))==0)
        {
            a[i].contador+=1;
            return 1;
        }
            
    }
    return 0;

}

void insertarPalabra(telem **a, char *palabra, int nPalabras) 
{

    *a = realloc(*a, nPalabras * sizeof(telem));
    if (*a == NULL)
    {
        fprintf(stderr, "Error al reasignar memoria.\n");
        exit(1);
    }
    
    (*a)[nPalabras-1].palabra = strdup(palabra);
    if ((*a)[nPalabras-1].palabra == NULL) {
        fprintf(stderr, "Error al duplicar la palabra.\n");
        exit(1);
    }

    (*a)[nPalabras-1].contador = 1;

    telem temp;
    int pos=nPalabras-1;
    while (pos>0)
    {
        if((strcmp((*a)[pos].palabra,(*a)[pos-1].palabra))<0)
        {
            temp=(*a)[pos];
            (*a)[pos]=(*a)[pos-1];
            (*a)[pos-1]=temp;
        }
        else
            break;
        pos--;
    }


}

void visualizarMatriz(telem *a, int nPalabras)
{
    for (int i = 0; i < nPalabras; i++)
    {
        printf("Palabra: %s, aparece un total de %d veces\n",a[i].palabra,a[i].contador);
    }
    
}

char *readString(char *str, int n)
{
    char *fin,*c;
    fin=fgets(str,n,stdin);
    if(c=strchr(str,'\n'))
        *c='\0';
    else if(!ferror(stdin))
        while(getchar() != '\n');
    return fin;
}

