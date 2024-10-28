#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "abpe.h"

typedef struct 
{
    char name[50];
    double mark;
}Data;


void *readData()
{
    char name[50];
    double mark;
    Data *student = NULL;

    printf("Name:  ");
    scanf("%[^\n]",name); 

    printf("Mark:  ");
    scanf("%lf",&mark);while(getchar() !='\n');


    student=(Data *)malloc(sizeof(Data));
    if(!student) return 0;
    strcpy(student->name,name);
    student->mark=mark;

    return (void *)student;
}

int compare(void *data1, void *data2)
{
    char *name1=((Data *)data1)->name;
    char *name2=((Data *)data2)->name;
    return strcmp(name1,name2);
}

void process(void *data)
{
    Data *student=(Data *)data;
    if(!student)    return;
    printf("%s %g\n",student->name,student->mark);
}

void memoryFree(void *data)
{
    if(data) free((Data *)data);
}

void showTree(Node *root)
{
    inorder(root);
}



int main(void)
{
  Node *raiz = NULL; 
  Data *alumno = NULL, *alumBuscado;
  int numeroDeNodos = 0, pos = 0;

  printf("Numero de nodos: ");
  scanf("%d", &numeroDeNodos); while (getchar() != '\n');
  raiz = buildTree(numeroDeNodos);
  if (raiz == NULL) return 0;


  printf("\nArbol:\n");
  showTree(raiz);


  printf("Nodo (0,1,2,...):   ");
  scanf("%d", &pos); while (getchar() != '\n');
  alumno = obtainNode(pos, raiz);
  if ( alumno == NULL )
    printf("La b�squeda fall�\n");
  else
    printf("Alumno %s, nota es %g\n", alumno->name, alumno->mark);


  printf("Buscar todas las ocurrencias de nombre en el arbol.\n");
  alumno = readData();
  if (alumno)
  {
    alumBuscado = search(alumno, raiz, &pos);
    if (alumBuscado == NULL) printf("La b�squeda fallo\n");
    while (alumBuscado != NULL)
    {
      printf("Nodo %2d, nota es %g\n", pos, alumBuscado->mark);
      pos++;
      alumBuscado = search(alumno, raiz, &pos);
    }
    free(alumno);
  }
  else
    printf("Insuficiente memoria\n");


  deleteTree(&raiz);

  return 0;
}
