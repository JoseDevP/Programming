#ifndef LCSE_H
#define LCSE_H
    #include "list.h"

    void error(); 
    Element *newElement();
    void initializeList(List *list);
    int addToBeggining(void *e, List *list);
    int addToEnd(void *e, List *list);
    void *eraseFirstElement(List *list);
    void *obtain(int i, List list);  

#endif  