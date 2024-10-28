#pragma once

typedef struct nodo
{
  void *data;          
  struct nodo *left;  
  struct nodo *right; 
}Node;
