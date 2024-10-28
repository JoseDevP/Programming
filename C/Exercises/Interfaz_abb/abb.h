#pragma once

#include "node.h"

void error();

Node *newNode();

void *search(void *data, Node *root);

int insert(void *data, Node **root);

void *deleteNode(void *data, Node **root);

void inorder(Node *root);

void deleteTree(Node **root);

int compare(void *data1, void *data2);

void copy(void *data1, void *data2);

void process(void *data);

void memoryFree(void *data);