#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "nodo.h"

void error()
{
    printf("Error en la asignacion de datos\n");
    exit(1);
}

nodo *nuevoNodo()
{
    nodo *q=(nodo *)malloc(sizeof(nodo));
    if(!q) return NULL;
    q->izdo=NULL;
    q->dcho=NULL;

    return q;
}

int comparar(char *al1, char *al2)
{

    return strcmp(al1,al2);

}

int insertar(nodo **raiz, char *a)
{
    nodo *actual=*raiz, *anterior=NULL;
    int nComp=0;

    while (actual != NULL)
    {
        anterior=actual;

        if((nComp=comparar(a,actual->linea)) == 0)
        {
            printf("Ya insertado\n");
            return 0;
        }
        else if(nComp < 0)
            actual=actual->izdo;
        else
            actual=actual->dcho;

    }
    
    if(anterior==NULL)
    {
        *raiz=nuevoNodo();
        if(!*raiz)  error();
        (*raiz)->linea = malloc(strlen(a) + 1);
        strcpy((*raiz)->linea,a);
        return 1;
    }
    else
    {
        nodo *nuevo=nuevoNodo();
        if(!nuevo)  error();
        nuevo->linea = malloc(strlen(a) + 1);
        strcpy(nuevo->linea,a);

        if(nComp < 0)
            anterior->izdo=nuevo;
        else
            anterior->dcho=nuevo;
        return 1;
    
    }
    
}

void visu_ascen(nodo *raiz)
{
    nodo *actual=raiz;

    if(actual != NULL)
    {
        visu_ascen(actual->izdo);
        printf("%s\n", actual->linea);
        visu_ascen(actual->dcho);
    }
}

void visu_descen(nodo *raiz)
{
    nodo *actual=raiz;

    if(actual != NULL)
    {
        visu_descen(actual->dcho);
        printf("%s\n", actual->linea);
        visu_descen(actual->izdo);
    }
}

void memoryFree(nodo **raiz)
{
    nodo *actual=*raiz;

    if(actual != NULL)
    {
        memoryFree(&actual->izdo);
        memoryFree(&actual->dcho);
        free(actual->linea);
        free(actual);
    }
}


char *leerLinea(char *r, int n)
{
    char *c, *fin;
    fin=fgets(r,n,stdin);
    if(c=strchr(r,'\n'))
        *c='\0';
    else if(feof(stdin))
        while(getchar() != '\n');
    return fin;
}

nodo *crear_arbol(void)
{
    nodo* raiz = NULL;
    char linea[50];
    
    printf("Introducir líneas (presione Enter en una línea vacía para terminar):\n");
    
    while (1)
    {
        printf("Introducir:\n");
        leerLinea(linea, 50);
        
        if (strlen(linea) == 0)
        {
            break;
        }
        
        insertar(&raiz, linea);
    }
    
    return raiz;  
}

void imprimir_arbol(nodo *q, char orden)
{
    if(orden == 'a')
        visu_ascen(q);
    else if(orden == 'd')
        visu_descen(q);
}

int main(int argc, char *argv[])
{
    if(argc != 2 )
    {
        printf("Sintaxis:\n");
        printf("4 -a\n");
        printf("4 -d\n");
    }
    else
    {
        nodo *raiz=NULL;
        raiz=crear_arbol();

        if(argv[1][0]=='-' && argv[1][1]=='a')
        {
            printf("Ascendentemente\n");
            visu_ascen(raiz);
        }
        else if(argv[1][0]=='-' && argv[1][1]=='d')
        {
            printf("\nDescendentemente\n");
            visu_descen(raiz);
        }

        memoryFree(&raiz);
        free(raiz);
    }

}