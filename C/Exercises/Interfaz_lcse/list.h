#ifndef LIST_H
#define LIST_H

    typedef struct s
    {
        void *data;
        struct s *next;
    }Element;
    
    typedef struct 
    {
        Element *lastElement;
        int nElements;
    }Cola;

#endif
