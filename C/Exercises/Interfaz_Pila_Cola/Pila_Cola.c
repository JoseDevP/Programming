#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "interfaz_pila_cola.h"  
#include "pc.h"  

typedef struct 
{
    char name[50];
    double mark;
}Data;

void showList(void *list,int type)
{
    Data *student=NULL;
    do
    {
        if(type ==0) //stack
            student=(Data *)sacarDePila(list);
        else //queue
            student=(Data *)sacarDeCola(list);
        if(student)
        {
            printf("%s %g\n",student->name,student->mark);
            free(student);
        }
    } while (student != NULL);
    if(student==NULL && type ==0)
        printf("stack empty\n");
    if(student==NULL && type ==1)
        printf("queue empty\n");
}

void memoryFree(void *list)
{
    Data *student=NULL;
    student=(Data *)eraseFirstOne(list);
    while (student)
    {
        free(student);
        student=(Data *)eraseFirstOne(list);
    }
    
}

void error1(void *pila, void *cola)
{
    memoryFree(pila);
    memoryFree(cola);
    error();
}

void error2(Data *student, void *pila, void *cola)
{
    free(student);
    memoryFree(pila);
    memoryFree(cola);
    error();
}



int main(void)
{
  char nombre[50];
  double nota;
  Data *alumno = NULL;

  tpila pila;
  tcola cola;
  iniciarPila(&pila);
  iniciarCola(&cola);


  printf("Introducir datos. Finalizar con eof.\n");
  printf("Nombre: ");
  while (scanf("%[^\n]", nombre) != EOF)
  {
    printf("Nota:   ");
    scanf("%lf", &nota); while (getchar() != '\n');

    alumno = (Data *)malloc(sizeof(Data));
    if (!alumno) error1(&pila, &cola);
    strcpy(alumno->name, nombre);
    alumno->mark = nota;
    if (!meterEnPila(alumno, &pila)) error2(alumno, &pila, &cola);

    alumno = (Data *)malloc(sizeof(Data));
    if (!alumno) error1(&pila, &cola);
    strcpy(alumno->name, nombre);
    alumno->mark = nota;
    if (!meterEnCola(alumno, &cola)) error2(alumno, &pila, &cola);
    printf("\nNombre: ");
  }

  printf("\n");
  // Mostrar la pila
  printf("\nPila:\n");
  showList(&pila, 0);
  // Mostrar la pila por segunda vez
  printf("\nPila:\n");
  showList(&pila, 0);

  printf("\n");
  // Mostrar la cola
  printf("\nCola:\n");
  showList(&cola, 1);
  // Mostrar la cola por segunda vez
  printf("\nCola:\n");
  showList(&cola, 1);

  // Borrar la pila y la cola
  memoryFree(&pila);
  memoryFree(&cola);
}

