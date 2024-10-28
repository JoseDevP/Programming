#pragma once

#include "nodo.h"

Node *newNode();

//Insertar (Insert) Propósito: Añadir un nuevo nodo con un valor dado al árbol.
int insert(void *data, Node **root);

//Buscar (Search) Propósito: Determinar si un valor dado existe en el árbol.
void *search(void *e, Node *root);

//Eliminar (Delete) Propósito: Eliminar un nodo con un valor específico del árbol.
void *delete(void *e, Node **root);

//Recorrido (Traversal) Propósito: Recorrer los nodos del árbol en un orden específico.
void inorder(Node *root);

//Mínimo (Find Minimum) Propósito: Encontrar el nodo con el valor mínimo en el árbol.
void *findMinimum(Node *root);

//Máximo (Find Maximum) Propósito: Encontrar el nodo con el valor máximo en el árbol.
void *findMaximum(Node *root);

//Altura (Height) Propósito: Determinar la altura del árbol, es decir, la longitud del camino más largo desde la raíz hasta una hoja.
int height(Node *root);

//borrar arbol
void deleteTree(Node **root);

//compare
int compare(void *data1, void *data2);
//memory free

//numero de apariciones
void plusAppear(void *data);

//copiar datos de nodo en uno
void copy(void *data1, void *data2);

//procesar datos de un nodo
void process(void *data);

//ver arbol
void showTree(Node *root);

void memoryFree(void *data);