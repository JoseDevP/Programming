/*
    Ackermann:
    A(m,n) para m = 0 -> n+1
    A(m,n) para m > 0 y n = 0 -> A(m-1,1)
    A(m,n) para m > 0 y n > 0 -> A(m-1,A(m,n-1))
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct St
{
  int m;
  int n;
  struct St *next;
}Stack;


void meter_en_pila(Stack **stack, int m, int n);
void sacar_de_pila(Stack **stack, int *m, int *n);

int Ackermann(int m, int n)
{
  Stack *pila = NULL;  
  int Ackerman_m_n = 0;

  meter_en_pila(&pila, m, n);
  
  while (1)
  {
    sacar_de_pila(&pila, &m, &n);
    if (m == 0) 
    {
      Ackerman_m_n = n+1;
      if (pila)
      {
        sacar_de_pila(&pila, &m, &n);
        meter_en_pila(&pila, m, Ackerman_m_n);
      }
      else
        return (Ackerman_m_n);
    }
    else if (n == 0)
      meter_en_pila(&pila, m-1, 1);
    else
    {
      meter_en_pila(&pila,m-1,Ackerman_m_n); 
      meter_en_pila(&pila, m, n-1);
    }
  }
}


void meter_en_pila(Stack **stack, int m, int n)
{
  Stack *q=(Stack *)malloc(sizeof(Stack));
  if(!q)  
  {
    printf("Error al asignar memoria\n");
    return;
  }

  q->m=m, q->n=n;
  q->next=NULL;

  q->next=*stack;
  *stack=q;

}

void sacar_de_pila(Stack **stack, int *m, int *n)
{
  if(*stack == NULL)
  {
    printf("Pila vacia\n");
    return;
  }
  Stack *current=*stack;

  *m=current->m;
  *n=current->n;

  *stack=current->next;

  free(current);
}

int main(void)
{
    int n=0;
    int m=0;

    printf("Input value for n:  ");
    scanf("%d",&n); while(getchar() != '\n');

    printf("Input value for m:  ");
    scanf("%d",&m); while(getchar() != '\n');

    if (m < 0 || n < 0)
    {
        printf("Values for m and n must be negatives\n");
        return 1; 
    }

    int res=Ackermann(m,n);
    printf("Result: %d",res);
    return 0;
}