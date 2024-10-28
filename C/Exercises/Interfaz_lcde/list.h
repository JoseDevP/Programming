#ifndef LIST_H
#define LIST_H
    typedef struct l
    {
        void *data;
        struct l *previous;
        struct l *next;
    }Element;

    typedef struct 
    {
        Element *lastOne;
        Element *current;
        int nElements;
        int position;
    }tlcse;

#endif 