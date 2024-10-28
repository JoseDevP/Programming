//MAL NO HACERLAS CIRCULARES SINO LINEALES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lcse.h"

void error()
{
    printf("Error while memory asigment.\n");
    exit(1);
}

Element *newElement()
{
    Element *q=(Element *)malloc(sizeof(Element));
    return q;
}

void initializeList(List *list)
{
    list->lastElement=NULL;
    list->nElements=0;
}


int addToBeggining(void *e, List *list)
{
    if(list==NULL)
        return 0;

    Element *lastOne=list->lastElement;
    Element *q=newElement();
    if(!q)  error();

    q->data=e;
    q->next=NULL;

    if(lastOne==NULL)
    {
        lastOne=q;
        q->next=q;
    }
    else
    {
        q->next=lastOne->next;
        lastOne->next=q;
    }
    
    list->lastElement=lastOne;
    list->nElements++;
    return 1;
}

int addToEnd(void *e, List *list)
{
    if(list==NULL)
        return 0;

    Element *lastOne=list->lastElement;
    Element *q=newElement();
    if(!q)  error();

    q->data=e;
    q->next=NULL;

    if(lastOne==NULL)
    {
        lastOne=q;
        q->next=q;
    }
    else
    {
        q->next=lastOne->next;
        lastOne->next=q;
        lastOne=q;
    }
    
    list->lastElement=lastOne;
    list->nElements++;
    return 1;
}

void *eraseFirstElement(List *list)
{
    if(list==NULL)
        return NULL;

    void *data;
    Element *lastOne=list->lastElement;
    if(lastOne==NULL)
        return NULL;

    Element *first=lastOne->next;

    if(first==lastOne)
    {
        data=first->data;
        free(first);
        lastOne=NULL;
    }
    else
    {
        
        data=first->data;
        lastOne->next=first->next;
        free(first);
    }
    
    list->lastElement=lastOne;
    list->nElements--;
    return data;
}

void *obtain(int i, List list)  
{

    if(i<0 || i>=list.nElements)
        return NULL;

    Element *f=list.lastElement->next;

    for (int n = 0; n < i; n++)
        f=f->next;

    return f->data;
}


