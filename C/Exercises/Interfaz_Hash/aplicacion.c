#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "interfaz_hash.h"

typedef struct
{
    int matricula;
    char nombre[50];
}tAlumno;

int fa(void *arg, tMatrizHash mh)
{
    tAlumno *a = (tAlumno *)arg;
    return a->matricula % mh.n_elementos;
}

int comparar(void *arg1, void *arg2)
{
    tAlumno *a1= (tAlumno *)arg1;
    tAlumno *a2= (tAlumno *)arg2;

    if(a1->matricula == a2->matricula)
        return 0;
    else
        return 1;
}

void liberarMemoria(void *arg)
{
    free((tAlumno*)arg);
}

int main(void)
{
  int n_elementos = 101; 

  tAlumno *x = NULL, a = {0, ""};
  tMatrizHash mh = {NULL, 0};

  printf("Numero de elementos:  ");
  scanf("%d", &n_elementos);
  IniciarMatrizHash(&mh, n_elementos);
  printf("Se construye una matriz de %d elementos\n", mh.n_elementos);
  

  printf("Introducir datos. Para finalizar, matricula = 0\n");
  printf("matricula:  "); scanf("%d", &a.matricula);
  while (getchar() != '\n');
  while (a.matricula != 0)
  {
    printf("nombre:     "); scanf("%[^\n]", a.nombre);
    x = (tAlumno *)malloc(sizeof(tAlumno));
    if (x == NULL)
    {
      borrarMatrizHash(mh);
      error();
    }
    x->matricula = a.matricula;
    strcpy(x->nombre, a.nombre);

    if (!hashIn(x, mh)) free(x);
    printf("matricula:  "); scanf("%d", &a.matricula);
    while (getchar() != '\n');
  }
  

  printf("Buscar datos. Para finalizar, matricula = 0\n");
  strcpy(a.nombre, "");
  printf("matricula:  "); scanf("%d", &a.matricula);
  while (a.matricula != 0)
  {
    x = (tAlumno *)hashOut(&a, mh);
    if (x != NULL)
      printf("nombre: %s\n", x->nombre);
    else
      printf("No existe\n");
    printf("matricula:  "); scanf("%d", &a.matricula);
  }
  borrarMatrizHash(mh);
}

