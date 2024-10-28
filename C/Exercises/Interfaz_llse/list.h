#ifndef LIST_H
#define LIST_H

typedef struct s
{
    void *value;
    struct s *pNext;
}Element;


typedef struct 
{
    Element *pElements;
    int nElements;
}Cola;
#endif