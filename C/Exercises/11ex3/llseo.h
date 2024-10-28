#pragma once

#include "Element.h"

typedef struct
{
  Element *p;            
  Element *elemPrevious;
  Element *elemCurrent;   
} tllseo;

void error();

Element *newElement();

void initializeList(tllseo *list);

int emptyList(tllseo *list);

int search(void *e, tllseo *list);

int compare(void *data1, void *data2);

int add(void *e, tllseo *list);

void *deleteElement(void *e, tllseo *list);

void *deleteFirst(tllseo *list);

void *obtainFirst(tllseo *list);

void *obtainNext(tllseo *list);


