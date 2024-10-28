#include <stdio.h>
#include <stdlib.h>

typedef struct St
{
  int inf;
  int sup;
  struct St *next;
}Stack;

void meter_en_pila(Stack **stack, int inf, int sup)
{
  Stack *q=(Stack *)malloc(sizeof(Stack));
  if(!q)  
  {
    printf("Error al asignar memoria\n");
    return;
  }

  q->inf=inf, q->sup=sup;
  q->next=NULL;

  q->next=*stack;
  *stack=q;

}

void sacar_de_pila(Stack **stack, int *inf, int *sup)
{
  if(*stack == NULL)
  {
    printf("Pila vacia\n");
    return;
  }
  Stack *current=*stack;

  *inf=current->inf;
  *sup=current->sup;

  *stack=current->next;

  free(current);
}

void qs(int lista[], int inf, int sup)
{
  Stack *pila = NULL;    

  meter_en_pila(&pila,inf,sup);
  while (pila)
  {
    sacar_de_pila(&pila,&inf,&sup);

    int izq = 0, der = 0;
    int mitad = 0, x = 0;

    izq = inf; der = sup;
    mitad = lista[(izq+der)/2];
    do
    {
      while (lista[izq] < mitad && izq < sup) izq++;
      while (mitad < lista[der] && der > inf) der--;
      if (izq <= der)
      {
        x = lista[izq], lista[izq] = lista[der], lista[der] = x;
        izq++; der--;
      }
    }
    while (izq <= der);
    if(inf < der)
    {
        meter_en_pila(&pila,inf, der);      
    }
    if(izq < sup)
    {
        meter_en_pila(&pila, izq, sup);        
    }
  }
}

void quicksort(int lista[], int n_elementos)
{
  qs(lista, 0, n_elementos - 1);
}

int main(void)
{
  static int lista[] = { 10, 3, 7, 5, 12, 1, 27, 3, 8, 13 };
  int n_elementos = sizeof(lista)/sizeof(int);

  quicksort(lista, n_elementos);
  
  printf("Lista ordenada:\n");
  for (int i = 0; i < n_elementos; i++)
    printf("%6d", lista[i]);
  printf("\n");
}
