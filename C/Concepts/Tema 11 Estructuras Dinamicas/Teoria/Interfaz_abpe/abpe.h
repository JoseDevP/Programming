#pragma once

#include "node.h"

void error();

Node *newNode();

Node *buildTree(int n);

void *obtainNode(int nodo_i, Node *root);

void *search(void *data, Node *root, int *pos);

void searchNode(void *data, Node *root, void **res, int *pos, int *i);

void inorder(Node *root);

void deleteTree(Node **root);

void *readData();

int compare(void *data1, void *data2);

void process(void *data);

void memoryFree(void *data);

void showTree(Node *root);