#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "llseo.h"

void error()
{
    printf("Error while data assigment");
    exit(1);
}

Element *newElement()
{
    Element *q=(Element *)malloc(sizeof(Element));
    return q;
}

void initializeList(tllseo *list)
{
    list->p=list->elemCurrent=list->elemPrevious=NULL;
}

int emptyList(tllseo *list)
{
    return list->p == NULL; 
}

int search(void *e, tllseo *list) // busca hasta el final o hasta que haya un <
{
    int r = 0;

    if(emptyList(list)) return 0;

    list->elemPrevious=list->p;
    list->elemCurrent=list->p;

                // > como esta ordenada busca solo hasta que haya uno que de menos
    while (list->elemCurrent != NULL && (r=compare(e,list->elemCurrent->data)) > 0) 
    {
        list->elemPrevious = list->elemCurrent;
        list->elemCurrent = list->elemCurrent->next;
    }
    
    return !r;
}


int add(void *e, tllseo *list)
{
    Element *q = newElement();
    if(!q) return 0;
    q->data=e;
    q->next=NULL;

    if(emptyList(list))
    {
        list->p = list->elemPrevious = list->elemCurrent = q;
        return 1;
    }

    search(e, list); 

    if(list->elemCurrent == list->elemPrevious)
    {
        q->next = list->p;
        list->p = q;
        list->elemPrevious=list->elemCurrent=list->p;
    }
    else
    {
        q->next = list->elemCurrent;
        list->elemPrevious->next=q;
        list->elemCurrent=q;
    }
    return 1;
}

void *deleteElement(void *e, tllseo *list)
{
    void *data;

    if(emptyList(list))
        return NULL;
    
    if(search(e,list)==0)    return NULL;

    if(list->elemCurrent == list->p)
        list->elemPrevious = list->p = list->p->next;
    else
        list->elemPrevious->next=list->elemCurrent->next;

    data=list->elemCurrent->data;
    free(list->elemCurrent);

    if(list->p == NULL)
        initializeList(list);
    else
        list->elemCurrent=list->elemPrevious->next;

    return data;
    
}

void *deleteFirst(tllseo *list)
{
    void *data;

    if(emptyList(list))
        return NULL;

    list->elemCurrent=list->p;
    list->p=list->p->next;

    data=list->elemCurrent->data;
    free(list->elemCurrent);

    list->elemPrevious = list->elemCurrent =list->p;

    return data;
}

void *obtainFirst(tllseo *list)
{
    if(emptyList(list))
        return NULL;

    list->elemPrevious = list->elemCurrent =list->p;

    return list->p->data;
}

void *obtainNext(tllseo *list)
{
    if(emptyList(list))
        return NULL;

    list->elemPrevious = list->elemCurrent;
    list->elemCurrent = list->elemCurrent->next;
    if(list->elemCurrent != NULL)
        return list->elemCurrent->data;
    else
        return NULL;
}



