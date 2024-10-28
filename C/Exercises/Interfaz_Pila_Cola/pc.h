#ifndef LLSE_H
#define LLSE_H

#include "list.h"
void error();

Element *newElement();

void initializeList(List *list);

int insert(int i, void *e, List *lista);

int addToBeginning(void *e, List *lista);

int addToEnd(void *e, List *lista);

void *erase(int i, List *lista);

void *eraseFirstOne(List *lista);

void *eraseLastOne(List *lista);

void *get(int i, List lista);

void *getFirstOne(List lista);

void *getLastOne(List lista);


#endif