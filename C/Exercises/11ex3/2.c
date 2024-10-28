#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "llseo.h"

typedef struct
{
    double coeficiente;
    int exponenteDeX;
    int exponenteDeY;
} Termino;

void memoryFree(tllseo *list)
{
    Termino *current = (Termino *)deleteFirst(list);
    while (current != NULL)
    {
        free(current);
        current = (Termino *)deleteFirst(list);
    }
    
}

void error1(tllseo *list1, tllseo *list2)
{
    printf("Error al asignar espacio\n");
    memoryFree(list1);
    memoryFree(list2);
    exit(1);
}

void error2(Termino *t, tllseo *list1, tllseo *list2)
{
    printf("Error al añadir\n");
    free(t);
    memoryFree(list1);
    memoryFree(list2);
    exit(1);
}

int compare(void *data1, void *data2)
{

    int peso1 = calcularPesoXTotal(((Termino *)data1)->exponenteDeX) + ((Termino *)data1)->exponenteDeY;
    int peso2 = calcularPesoXTotal(((Termino *)data2)->exponenteDeX) + ((Termino *)data2)->exponenteDeY;

    if(peso1 > peso2)
        return -1;
    else if (peso1 < peso2)
        return 1;
    else
        return 0;
}

int calcularPesoXTotal(int e)
{
    return (int)pow(10,e);
}

void fflushstdin()
{
    while(getchar() != '\n');
}

Termino *leerTermino()
{
    double coeficiente;
    int exponenteDeX;
    int exponenteDeY;

    printf("Inserta el coeficiente: ");
    scanf("%lf", &coeficiente); fflushstdin();
    printf("Inserta el exponente de X: ");
    scanf("%d", &exponenteDeX); fflushstdin();
    printf("Inserta el exponente de Y: ");
    scanf("%d", &exponenteDeY); fflushstdin();

    Termino *t=(Termino *)malloc(sizeof(Termino));
    if(!t)  return NULL;

    t->coeficiente=coeficiente;
    t->exponenteDeX=exponenteDeX;
    t->exponenteDeY=exponenteDeY;

    return t;
}

void mostrarTermino(Termino t)
{
    printf("%gx^%dy^%d\n", t.coeficiente, t.exponenteDeX, t.exponenteDeY);
}

void mostrarPolinomio(tllseo *poli)
{
    Termino *t=(Termino *)obtainFirst(poli);
    while (t != NULL)
    {
        printf("%c", t->coeficiente > 0 ? '+' : ' ');
        printf("%gx^%dy^%d ", t->coeficiente, t->exponenteDeX, t->exponenteDeY);
        t=(Termino *)obtainNext(poli);
    }
}

tllseo sumar(tllseo pA, tllseo pB)
{
  // pR = sumar(pA, pB).
  int k = 0;
  Termino *tA = NULL, *tB = NULL, *tR = NULL;
  tllseo pR; // polinomio resultante
  initializeList(&pR);

  tA = (Termino *)obtainFirst(&pA);
  tB = (Termino *)obtainFirst(&pB);
  // Sumar pA con pB
  while ( tA != NULL && tB != NULL )
  {
    k = compare(tA, tB);
    tR = (Termino *)malloc(sizeof(Termino));
    if (!tR)
    {
        memoryFree(&pR);
        error1(&pA, &pB);
    }

    if ( k == 0 )
    {
      tR->coeficiente = tA->coeficiente + tB->coeficiente;
      tR->exponenteDeX = tA->exponenteDeX;
      tR->exponenteDeY = tA->exponenteDeY;
      tA = (Termino *)obtainNext(&pA);
      tB = (Termino *)obtainNext(&pB);
    }
    else if ( k < 0 )
    {
      tR->coeficiente = tA->coeficiente;
      tR->exponenteDeX = tA->exponenteDeX;
      tR->exponenteDeY = tA->exponenteDeY;
      tA = (Termino *)obtainNext(&pA);
    }
    else
    {
      tR->coeficiente = tB->coeficiente;
      tR->exponenteDeX = tB->exponenteDeX;
      tR->exponenteDeY = tB->exponenteDeY;
      tB = (Termino *)obtainNext(&pB);
    }
    if (tR->coeficiente)
    {
      if (!add(tR, &pR))
      {
        free(tR);
        memoryFree(&pR);
        error1(&pA, &pB);
      }
    }
    else
      free(tR);
  }
  // T�rminos restantes en el pA
  while ( tA != NULL )
  {
    tR = (Termino *)malloc(sizeof(Termino));
    if (!tR)
    {
        memoryFree(&pR);
        error1(&pA, &pB);
    }

    tR->coeficiente = tA->coeficiente;
    tR->exponenteDeX = tA->exponenteDeX;
    tR->exponenteDeY = tA->exponenteDeY;
    if (!add(tR, &pR))
    {
      free(tR);
      memoryFree(&pR);

      error1(&pA, &pB);
    }
    tA = (Termino *)obtainNext(&pA);
  }
  // T�rminos restantes en el pB
  while ( tB != NULL )
  {
    tR = (Termino *)malloc(sizeof(Termino));
    if (!tR)
    {
      memoryFree(&pR);

      error1(&pA, &pB);
    }

    tR->coeficiente = tB->coeficiente;
    tR->exponenteDeX = tB->exponenteDeX;
    tR->exponenteDeY = tB->exponenteDeY;
    if (!add(tR, &pR))
    {
      free(tR);
      memoryFree(&pR);

      error1(&pA, &pB);
    }
    tB = (Termino *)obtainNext(&pB);
  }

  return pR;
}



int main(void)
{
    char respuesta='s';
    int nTermino=0;

    Termino *t=NULL;
    tllseo polinomio1;
    initializeList(&polinomio1);
    tllseo polinomio2;
    initializeList(&polinomio2);
    
    tllseo sumaPolinomios;

    printf("------------------Suma de Polinomios--------------------\n");

    printf("\n\nPolinomio 1:\n\n");
    while (respuesta == 's')
    {
        printf("Termino %d:\n",nTermino);
        nTermino++;

        t=leerTermino();
        if(!t)
            error1(&polinomio1,&polinomio2);

        if(!add(t, &polinomio1)) error2(t,&polinomio1,&polinomio2);

        printf("¿Quieres introducir un nuevo termino en el polinomio? (s/n)  ");
        scanf("%c",&respuesta); fflushstdin();
    }

    printf("Polinomio 1:\n\n");
    mostrarPolinomio(&polinomio1);
    printf("\nPulsa Enter para continuar.");
    while((respuesta=getchar()) != '\n') fflushstdin();

    respuesta='s';
    nTermino=0;

    printf("\n\nPolinomio 2:\n\n");
    while (respuesta == 's')
    {
        printf("Termino %d:\n",nTermino);
        nTermino++;

        t=leerTermino();
        if(!t)
            error1(&polinomio1,&polinomio2);

        if(!add(t,&polinomio2)) error2(t,&polinomio1,&polinomio2);

        printf("¿Quieres introducir un nuevo termino en el polinomio? (s/n)  ");
        scanf("%c",&respuesta); fflushstdin();
    }

    printf("\n\nPolinomio 2:\n\n");
    mostrarPolinomio(&polinomio2);
    printf("\nPulsa Enter para continuar.");
    while((respuesta=getchar()) != '\n') fflushstdin();

    sumaPolinomios=sumar(polinomio1,polinomio2);
    printf("\n\nSuma:\n\n");
    mostrarPolinomio(&sumaPolinomios);
    printf("\nPulsa Enter para continuar.");
    while((respuesta=getchar()) != '\n') fflushstdin();
    
    return 0;
}


