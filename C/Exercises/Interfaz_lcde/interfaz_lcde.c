//Interfaz para manipular un lcde
#include <stdio.h>
#include <stdlib.h>
 
#include "lcde.h"

void error()
{
    printf("Error while memory assigment\n");
    exit(1);
}

Element *newElement()
{
    Element *q=(Element *)malloc(sizeof(Element));
    return q;
}

void initializeLcde(tlcse *lcde)
{
    lcde->current=lcde->lastOne=NULL;
    lcde->nElements=0;
    lcde->position=-1;
}

int insert(void *e, tlcse *lcde)
{
    /*
             +---+    +---+    +---+    +---+
        | A |<--> | B |<--> | C |<--> | D |
        +---+    +---+    +---+    +---+
         ^                                |
         |                                v
         +--------------------------------+

         B -> current

               (C)
         current->next->previous=Q
                       (C)
         Q->next=current->next;
                       (B)
         Q->previous=current;
            (B)
         current->next=Q;

         current=Q

         si hubiera insertado detras de D, lastOne=Q

    */
    if(lcde==NULL)
        return 0;

    Element *lastOne=lcde->lastOne;
    Element *current=lcde->current;
    int nElements=lcde->nElements;
    int pos=lcde->position;

    Element *q=newElement();
    if(!q)  error();
    q->data=e;
    q->next=NULL;
    q->previous=NULL;

    if(lastOne==NULL) //lista vacia
    {
        q->previous=q->next=lastOne=current=q;
        pos=0;
    }
    else
    {
        q->next=current->next;
        q->previous=current;
        current->next->previous=q;
        current->next=q;

        pos++;

        if(current==lastOne)
            lastOne=q;
            
        current=q;
    }

    nElements++;

    lcde->current=current;
    lcde->lastOne=lastOne;
    lcde->nElements=nElements;
    lcde->position=pos;

    return 1;
}

void *delete(tlcse *lcde)
{
    
    /*
             +---+    +---+    +---+    +---+
        | A |<--> | B |<--> | C |<--> | D |
        +---+    +---+    +---+    +---+
         ^                                |
         |                                v
         +--------------------------------+
    current->D
        D
    current = C
         A                      C
    lastOne->next->previous=current
        C               A
    current->next=lasOne->next
                C
    lastOne=current 
    */
    if(lcde==NULL)
        return 0;

    Element *lastOne=lcde->lastOne;
    Element *current=lcde->current;
    Element *q=NULL;
    void *data;

    int nElements=lcde->nElements;
    int pos=lcde->position;

    if(lastOne==NULL) return NULL;

    if(lastOne==current)
    {
        if(nElements==1)
        {
            current=NULL;
            lastOne=NULL;
            nElements=0;
            pos=-1;
        }
        else
        {
            lastOne->previous->next=lastOne->next;
            lastOne->next->previous=lastOne->previous;
            current=lastOne->previous;
            data=lastOne->data;
            free(lastOne);
            lastOne=current;
            pos--;
            nElements--;
        }
    }
    else
    {
        q=current->next;
        current->previous->next=current->next;
        current->next->previous=current->previous;
        data=current->data;
        free(current);
        current=q;
        nElements--;
    }

    lcde->current=current;
    lcde->lastOne=lastOne;
    lcde->nElements=nElements;
    lcde->position=pos;  

    return data;     
}

void goToNextOne(tlcse *lcse)
{
    if(lcse==NULL || lcse->lastOne==NULL)
        return;
    if(lcse->position < lcse->nElements-1)
    {
        lcse->current=lcse->current->next;
        lcse->position++;
    }
}

void goToPreviousOne(tlcse *lcse)
{
    if(lcse==NULL || lcse->lastOne==NULL)
        return;
    if(lcse->position > 0)
    {
        lcse->current=lcse->current->previous;
        lcse->position--;
    }
}

void goToBeginning(tlcse *lcse)
{
    if(lcse==NULL || lcse->lastOne==NULL)
        return;
    lcse->position=0;
    lcse->current=lcse->lastOne->next;
}

void goToEnd(tlcse *lcse)
{
    if(lcse==NULL || lcse->lastOne==NULL)
        return;
    lcse->position=lcse->nElements-1;
    lcse->current=lcse->lastOne;  
}

int goToPosition(int i,tlcse *lcse)
{
    if(lcse==NULL || lcse->lastOne==NULL)
        return 0;
    if(i >= lcse->nElements || i<0) return 0;

    goToBeginning(lcse);
    for (int n = 0; n < i; n++)
        goToNextOne(lcse);
    
    return 1;
    
}

void *obtainCurrent(tlcse *lcse)
{
    if(lcse==NULL || lcse->lastOne==NULL)
        return NULL;
    if(lcse->current == NULL)   return NULL;
    return lcse->current->data;
}

void *obtain(int i, tlcse *lcse)
{
    if(!goToPosition(i,lcse))   return NULL;
    return obtainCurrent(lcse);
}

void modify(void *e, tlcse *lcse)
{
    if(lcse==NULL || lcse->lastOne==NULL)
        return ;
    lcse->current->data=e;
}