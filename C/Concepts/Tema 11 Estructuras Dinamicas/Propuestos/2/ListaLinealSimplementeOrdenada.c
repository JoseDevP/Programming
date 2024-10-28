#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "llseo.h"

typedef struct 
{
    char name[50];
    double mark;
}Data;


int compare(void *data1, void *data2)
{
    char *nom1 = ((Data *)data1)->name;
    char *nom2 = ((Data *)data2)->name;

    return strcmp(nom1,nom2);
}

void showList(tllseo *list)
{
    Data *student = (Data *)obtainFirst(list);
    while (student)
    {
        printf("%s %g\n",student->name, student->mark);
        student = (Data *)obtainNext(list);
    }
    
}

void memoryFree(tllseo *list)
{
    Data *student = (Data *)deleteFirst(list);
    while (student)
    {
        student = (Data *)deleteFirst(list);
    }
}

Data *readData()
{
  Data *alumno = NULL;
  char nombre[50];
  double nota;

  printf("\nNombre: ");
  scanf("%[^\n]", nombre);
  printf("Nota:   ");
  scanf("%lf", &nota); while (getchar() != '\n');
  // Crear un objeto de tipo Datos
  alumno = (Data *)malloc(sizeof(Data));
  if (!alumno) return 0;
  strcpy(alumno->name, nombre);
  alumno->mark = nota;
  return alumno;
}


void error1(tllseo *list)
{
    memoryFree(list);
    error();
}

void error2(Data *student, tllseo *list)
{
    free(student);
    memoryFree(list);
    error();
}

int main(void)
{
    char resp='y';
    Data *student = NULL;

    tllseo llseo;
    initializeList(&llseo);

    while (resp == 'y')
    {
        student=readData();
        if(!student)    error1(&llseo);
        if(!add(student,&llseo)) error2(student, &llseo);

        printf("¿Do you want to insert another student? (y/n) ");
        resp = getchar(); while(getchar() != '\n');
    }
    showList(&llseo);
    
    printf("\nDelete student:");
    student=readData();
    if(student)
    {
        free(deleteElement(student,&llseo));
        free(student);
    }
    else
        printf("Not memory available\n");

    student=(Data *)obtainNext(&llseo);
    if(student)
        printf("Next %s %g\n", student->name, student->mark);

    printf("\nList\n");
    showList(&llseo);

    memoryFree(&llseo);
}
