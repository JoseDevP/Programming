#include <stdio.h>
#include <stdlib.h>
#include "interface_pila.h"

void error()
{
    printf("Error while data assigment.\n");
    exit(1);
}

Element *newElement()
{
    Element *q=(Element *)malloc(sizeof(Element));
    if(!q) return NULL;
    return q;
}

void initialize(Stack *stack)
{
    if(stack == NULL)   return;
    stack->nElements=0;
    stack->pElements=NULL;
}

int isEmpty(Stack *stack)
{
    if(stack == NULL)   return 0;
    return stack->pElements == NULL;
}

int add(void *e, Stack *stack)
{
    if(stack == NULL)   return 0;
    
    Element *new=newElement();
    if(!new) error();
    new->data=e;
    new->pNext=NULL;

    new->pNext=stack->pElements;
    stack->pElements=new;
    stack->nElements++;
    return 1;
}

void *delete(Stack *stack)
{
    if(stack == NULL || stack->pElements == NULL) return NULL;

    void *data;

    Element *q=stack->pElements;
    data=q->data;

    stack->pElements=stack->pElements->pNext;
    free(q);
    
    return data;
}

void *peek(Stack *stack)
{
    if(stack == NULL || stack->pElements == NULL) return NULL;

    return stack->pElements->data;
}


