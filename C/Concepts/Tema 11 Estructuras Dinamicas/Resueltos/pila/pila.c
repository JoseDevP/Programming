/*
    Aplicacion para que utilizando una pila, simule una calculador capza de realizar las 
    operaciomnes de +,-,*,/
    Tiene notacion postfija.
    a)leera un dato, operando u operador, y lo almacenara en la variable oper.
    b)Analizara oper si se trata de un operando, lo metera en la pila y si se trata de un
    operador, sacara los dos ultimos operandos de la pila, realizara la operacion idndicada 
    por dicho perador y metera el resultado en la pila para poder utilizarlo como operando en 
    una posible siguiente operacion.
*/
#include <stdio.h>
#include <stdlib.h>
#include "interface_pila.h"


void memoryFree(Stack *stack)
{
  double *pdouble = NULL;
  pdouble = delete(stack);
  while (pdouble)
  {
    free(pdouble); 
    pdouble = delete(stack); 
  }
}

void *newDouble(double d)
{
    double *p = (double *)malloc(sizeof(double));
    if(!p)  return NULL;

    *p=d;
    return p;
}

int obtainOperands(double operand[], Stack *stack)
{
    double *pdouble=NULL;
    if(stack->nElements < 2)
    {
        printf("Error: Input %d operands or more\n",2 - stack->nElements);
        return 0;
    }
    pdouble=(double *)delete(stack);
    if(!pdouble) return 0;
    operand[0] = *pdouble;
    free(pdouble);
    pdouble=(double *)delete(stack);
    operand[1] = *pdouble;
    free(pdouble);
    return 1;
}

void error1(Stack *Stack)
{
    memoryFree(Stack);
    error();
}

int main(void)
{
    int m=0; //controlar errores
    double *p=NULL;
    char oper[20];
    double operand[2];

    Stack stack;
    initialize(&stack);

    printf("Operations: + - * /\n");
    printf("Way to introduce data:\n");
    printf("Operand 0 [Enter]\n");
    printf("Operand 0 [Enter]\n");
    printf("Operator [Enter]\n");
    printf("For exit press q\n\n");

    do
    {
        printf("> ");
        scanf("%s",oper);
        switch (oper[0])
        {
        case '+':
            if(!obtainOperands(operand,&stack)) break;
            printf("%g\n",operand[0] + operand[1]);
            if(p = newDouble(operand[0] + operand[1]))
                m=add(p,&stack);
            break;
        case '-':
            if(!obtainOperands(operand,&stack)) break;
            printf("%g\n",operand[0] - operand[1]);
            if(p = newDouble(operand[0] - operand[1]))
                m=add(p,&stack);
            break;
        case '*':
            if(!obtainOperands(operand,&stack)) break;
            printf("%g\n",operand[0] * operand[1]);
            if(p = newDouble(operand[0] * operand[1]))
                m=add(p,&stack);
            break;
        case '/':
            if(!obtainOperands(operand,&stack)) break;
            if(operand[1] == 0)
            {
                printf("\nError: can't divide with 0");
                break;
            }
            printf("%g\n",operand[0] / operand[1]);
            if(p = newDouble(operand[0] / operand[1]))
                m=add(p,&stack);
            break;
        case 'q':
            break;
        default:
            if(p =newDouble(atof(oper)))
            m=add(p,&stack);
        }

        if(oper[0] != 'q' && (m==0 || p==0))
        {
            if(p)   free(p);
            error1(&stack);
        }
    } while (oper[0] != 'q');
    
    memoryFree(&stack);
}