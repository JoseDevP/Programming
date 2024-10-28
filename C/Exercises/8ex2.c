/*
    Suponiendo un texto escrito en minusculas y sin signos de puntuacion,es decir, 
    una palabra estará separada de otra por un espacio en blanco, realizar un programa
    que lea texto de la entrada estanndar y de como resultado la frecuencia con que
    aparece cada palabra leída del texto.
    El resultado se almacenará en una matriz en la que cada elemento será una
    estructura del tipo siguiente:

        typedef struct
        {
            char *palabra;
            int contador;
        }telem;

    La estructura del programa estará formulada por la función main y por las funciones
    siguientes:

        int buscarPalabra(telem *a, char *palabra);
        void insertarPalabra(telem *a, char *palabra);
        void visualizarMatriz(telem *a);

    La funcion main asignara memoria para una matriz de n elementos, iniciara los
    elementos de la matriz a cero, utilizando las funciones aneroiros calculara la 
    frecuencia con la que aparece cada una de las palabras y visualizará el resultado.

    La funcion buscarPalabra verificará si la palabra leida de la entrada estamdar
    esta en la matriz a. Esta funcion devolvera un valor distinto de 0 si la palabra
    esta en la mtriz y un 0 en caso contrario.

    La funcion insertarPalabra permitirá añadir una nueva palabra al final de la 
    matriz a. Tenga en cuenta que cada palabra en la matriz esta referenciada
    por un puntero.

    La funcion visualizarPalabra visualizara cada una de las palabras de la matriz
    seguida del numero de veces que apareció.
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
