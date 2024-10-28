/*Crea una lista lineal simplemente enlazada*/

/*
        mostrarLista
        liberarMemoria
        error1 al anyadir
        main
            Pedir datos: Nombre Alumno y Nota y los añade
            //Añadir un objeto al principio 

            //Añadir un objeto en la posicion pos

            //Mostrar el primero

            //Mostrar el ultimo

            //Mostrar todos

            //Borrar elemento del indice 2

            //Modificar el elemento del indice 1

            //Mostrar todos

            //Borra lista
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

typedef struct 
{
    char name[50];
    double mark;
}Data;

void mostrarLista(List lista)
{
    printf("\n\n Lista:\n");
    Datos *alumno=NULL;
    for (int i = 0; i < lista.nElements; i++)
    {
        alumno=(Datos *)get(i,lista);
        printf("Nombre %s, Nota: %g\n",alumno->name,alumno->mark);
    }
    
}

void liberarMemoria(List *lista)
{
    Datos *alumno;
    alumno=(Datos *)eraseFirstOne(lista);
    while (alumno)
    {
        free(alumno);
        alumno=(Datos *)eraseFirstOne(lista);
    }
}

char *readChain(char *str, int n)
{
    char *fin, *c;
    fin=fgets(str,n,stdin);
    if(c=strchr(str, '\n'))
        *c='\0';
    else if(!feof(stdin))
        while(getchar() != '\n');
    if (str[0] == '\0')
        return str;
    else
        return fin;
}

int main(void)
{
    List lista;
    initializeList(&lista);
    Datos *alumno=(Datos *)malloc(sizeof(Datos));

    char name[50];
    double mark;

    int correct=-1;

    printf("Inserts students and marks:\n\n");
    while (!feof(stdin))
    {
        printf("Input the student name (or press Enter to finish): ");
        if (readChain(name, sizeof(name)) != NULL && name[0] == '\0')
            break;  

        do
        {
            printf("Mark:  ");
            correct=scanf("%lf",&mark);
        } while (!correct || mark <0 || mark >10);
        while(getchar() != '\n');

        strcpy(alumno->name, name);
        alumno->mark=mark;
        
        if(addToEnd(alumno, &lista)<=0)
        {
            printf("Error al añadir\n");
        }

        alumno=(Datos *)malloc(sizeof(Datos));
        
    }

    //Añadir un objeto al principio 
    printf("Añadir un objeto al principio \n");
    alumno=(Datos *)malloc(sizeof(Datos));
    alumno->mark=10;
    strcpy(alumno->name, "Begin");


    if(addToBeginning(alumno, &lista)<=0)
    {
        printf("Error al añadir\n");
    }
    mostrarLista(lista);


    //Añadir un objeto en la posicion pos
    printf("Añadir un objeto en la posicion pos \n");
    alumno=(Datos *)malloc(sizeof(Datos));
    alumno->mark=10;
    strcpy(alumno->name, "3");


    if(insert(3, alumno, &lista)<=0)
    {
        printf("Error al añadir\n");
    }
    mostrarLista(lista);

    //Mostrar el primero
    printf("Mostrar el primero \n");
    alumno=(Datos *)get(0, lista);
    printf("Nombre %s, Nota: %g\n",alumno->name,alumno->mark);
    mostrarLista(lista);

    //Mostrar el ultimo
    printf("Mostrar el ultimo \n");
    alumno=(Datos *)get(lista.nElements-1, lista);
    printf("Nombre %s, Nota: %g\n",alumno->name,alumno->mark);
    mostrarLista(lista);


    //Mostrar todos
    printf("Mostrar todos \n");
    mostrarLista(lista);
    mostrarLista(lista);


    //Borrar elemento del indice 2
    printf("Borrar elemento del indice 2 \n");
    alumno=(Datos *)erase(2, &lista);
    free(alumno);
    mostrarLista(lista);


    //Modificar el elemento del indice 1
    printf("Modificar el elemento del indice 1 \n");
    alumno=(Datos *)get(1,lista);
    alumno->mark=25;

    //Mostrar todos
    mostrarLista(lista);

    //Borra lista
    liberarMemoria(&lista);
}