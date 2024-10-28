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

int comparar(alumno al1, alumno al2)
{
    if(al1.dni == al2.dni)
        return 0;
    if(al1.dni < al2.dni)
        return -1;
    else
        return 1;
}

int insertar(nodo **raiz, alumno a)
{
    nodo *actual=*raiz, *anterior=NULL;
    int nComp=0;

    while (actual != NULL)
    {
        anterior=actual;

        if((nComp=comparar(a,actual->datos)) == 0)
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
        (*raiz)->datos=a;
        return 1;
    }
    else
    {
        nodo *nuevo=nuevoNodo();
        if(!nuevo)  error();
        nuevo->datos=a;

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
        printf("Alumno: %s Dni: %lu\n", actual->datos.nombre, actual->datos.dni);
        visu_ascen(actual->dcho);
    }
}

void visu_descen(nodo *raiz)
{
    nodo *actual=raiz;

    if(actual != NULL)
    {
        visu_descen(actual->dcho);
        printf("Alumno: %s Dni: %lu\n", actual->datos.nombre, actual->datos.dni);
        visu_descen(actual->izdo);
    }
}

alumno leerAlumno()
{
    alumno nuevo;
    char nombre[60];
    unsigned long dni;

    printf("Introduce el nombre del alumno: ");
    scanf("%[^\n]",nombre);
    printf("Introduce el dni: ");
    scanf("%lu",&dni); while(getchar() != '\n');

    nuevo.dni=dni;
    strcpy(nuevo.nombre,nombre);

    return nuevo;
}

void memoryFree(nodo **raiz)
{
    nodo *actual=*raiz;

    if(actual != NULL)
    {
        memoryFree(&actual->izdo);
        memoryFree(&actual->dcho);
        free(actual);
    }
}

int main(int argc, char *argv[])
{
    if(argc != 3 )
    {
        printf("Sintaxis:\n");
        printf("listar -a archivo\n");
        printf("listar -d archivo\n");
    }
    else
    {
        alumno alu;
        nodo *raiz=NULL;
        FILE *pf=NULL;

        if((pf=fopen(argv[2],"rb"))==NULL)
        {
            printf("Error al abrir el archivo.\n");
            exit(-1);
        }

        while ((fread(&alu,sizeof(alumno),1,pf)) ==1)
        {
            insertar(&raiz,alu);
        }

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
        memoryFree(raiz);
        fclose(pf);
        return 0;
    }
}