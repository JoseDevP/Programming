#pragma once

#include "pila.h"

void error();

Element *newElement();

//initialize  Inicializa una pila vacía.
void initialize(Stack *stack);

//isEmpty Verifica si la pila está vacía.
int isEmpty(Stack *stack);

//size Devuelve el número de elementos en la pila.
int size(Stack *stack);

//push Agrega un elemento al tope de la pila.
int add(void *e, Stack *stack);

//pop Elimina y devuelve el elemento del tope de la pila.
void *delete(Stack *stack);

//peek Devuelve el elemento en el tope de la pila sin eliminarlo.
void *peek(Stack *stack);
