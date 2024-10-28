#pragma once

typedef struct s
{
    void *data;
    struct s *pNext;
}Element;

typedef struct 
{
    Element *pElements;
    int nElements;
}Stack;
