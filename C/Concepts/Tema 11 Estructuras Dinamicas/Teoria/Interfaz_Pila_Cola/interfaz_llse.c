#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pc.h"

void error()
{
    printf("Error al asignar espacio");
    exit(0);
}

Element *newElement()
{
    Element *q=(Element *)malloc(sizeof(Element));
    if(q==NULL)
    {
        error();
        return NULL;
    }
    return q;
}

void initializeList(List *list)
{
    list->nElements=0;
    list->pElements=NULL;
}

int insert(int i, void *e, List *lista)
{

    if(lista==NULL) return -1;
    
    if(i > lista->nElements || i<0) return 0;

    Element *q=NULL, *p=lista->pElements;
    Element *previous = p, *current = p;
    
    q=newElement();
    if(!q) 
    {return 0; error();}
    
    q->pNext=NULL;
    q->value=e;

    if(lista->nElements==0)
    {
        lista->pElements=q;
        lista->nElements++;
        return 1;
    }

    for (int n = 0; n < i; n++)
    {
        previous=current;
        current=previous->pNext;
    }

    if(previous == current)
    {
        q->pNext=p;
        p=q;
    }
    else
    {
        q->pNext=current;
        previous->pNext=q;
    }
    
    lista->pElements=p;
    lista->nElements++;
    return 1;

}

int addToBeginning(void *e, List *lista)
{
    return (insert(0,e,lista));
}

int addToEnd(void *e, List *lista)
{
    return (insert(lista->nElements,e,lista));
}

void *erase(int i, List *lista)
{
    void *data;
    Element *q=NULL, *p=lista->pElements;
    Element *previous=p, *current=p;

    if(lista->pElements==NULL)
        return NULL;

    if(i>=lista->nElements || i<0)
        return NULL;
    
    for (int n = 0; n < i; n++)
    {
        previous=current;
        current=current->pNext;
    }

    if(previous == current)
        p=p->pNext;
    else
        previous->pNext=current->pNext;

    data=current->value;
    free(current);
    lista->pElements=p;
    lista->nElements--;
    return data;    
}

void *eraseFirstOne(List *lista)
{
    return erase(0,lista);
} 

void *eraseLastOne(List *lista)
{
    return erase(lista->nElements-1,lista);
}

void *get(int i, List lista)
{
    Element *q=lista.pElements;
    if(lista.pElements == NULL)
        return NULL;
    if(i>=lista.nElements || i<0)
        return NULL;
    
    for (int n = 0; n < i; n++)
        q=q->pNext;

    return q->value;
    
}

void *getFirstOne(List lista)
{
    return (get(0,lista));
}

void *getLastOne(List lista)
{
    return (get(lista.nElements-1,lista));

}

