#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lcse.h"

typedef struct 
{
    char name[50];
    double mark;
}Data;

void showStack(List list)
{
    printf("\n\n");
    Data *student;

    for (int i = 0; i < list.nElements; i++)
    {
        student=(Data *)obtain(i,list);
        printf("Student %d:\n",i);
        printf("Name: %s\n",student->name);
        printf("Mark: %.2g\n",student->mark);
        printf("\n");
    }
    
}

void memoryFree(List *list)
{
    if (list == NULL)
        return;

    Data *e=(Data *)eraseFirstElement(list);
    while (e)
    {
        free(e);
        e=(Data *)eraseFirstElement(list);
    }
    
}

void error1(List *list)
{
    memoryFree(list);
    error();
}

void error2(Data *student, List *list)
{
    printf("Error while adding or deleting student\n");
    free(student);
    memoryFree(list);
}

int main(void)
{
    //Añadir un objeto al principio
    //Mostrar todos
    //Borrar Primero
    //Mostrar todos
    char name[50];
    double mark;

    Data *student=NULL;
    List list;
    initializeStack(&list);

    printf("Introducir datos. Finalizar con eof.\n");
    printf("Nombre: ");
    while (scanf("%[^\n]",name))
    {
        printf("Nota: ");
        scanf("%lf",&mark);while(getchar() != '\n');

        student=(Data *)malloc(sizeof(Data));
        if(!student) error1(&list);

        student->mark=mark;
        strcpy(student->name,name);

        if(!addToEnd(student, &list))  error2(student,&list);

        printf("Nombre: ");
    }
    
    showStack(list);

    //Añadir un objeto al principio
    printf("\n\n");
    student=(Data *)malloc(sizeof(Data));
    if(!student) error1(&list);

    student->mark=0;
    strcpy(student->name,"First");

    if(!addToEnd(student, &list))  error2(student,&list);

    //Mostrar todos
    showStack(list);

    //Borrar Primero
    student=(Data *)pop(&list);

    //Mostrar todos
    showStack(list);

    return 0;
}