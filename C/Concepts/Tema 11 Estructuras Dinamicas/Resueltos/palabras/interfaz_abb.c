// interfaz_abb.c
#include <stdio.h>
#include <stdlib.h>

#include "interfaz_abb.h" 

void error()
{
  printf("Error while data assigmnet");
  exit(1);
}

Node *newNode()
{
  Node *q=(Node *)malloc(sizeof(Node));
  if(!q) return NULL;
  return q;
}

int insert(void *data, Node **root)
{
  if(data == NULL)  return 0;

  int ncomp=0;
  Node *current=*root, *lastOne=NULL;

  Node *q=newNode();
  if(!q)  return 0;
  q->data=data;
  q->left=q->right=NULL;

  while (current != NULL)
  {
    lastOne=current;

    if((ncomp=compare(data,current->data))==0)
    {
      return 0;
    }
    else
    {
      if (ncomp < 0)
      {
        current=current->left;
      }
      else
      {
        current=current->right;
      }

    }
  }
  if(lastOne == NULL)
  {
    *root=q;
    return 1;
  }
  else
  {
    if(ncomp <0)
      lastOne->left=q;
    else 
      lastOne->right=q;
      
    return 1;  
  }
    
    
}

void *search(void *e, Node *root)
{
  if(root == NULL) return NULL;

  Node *current=root;
  int nComp=0;
  while (current!=NULL)
  {
    if((nComp=compare(e,current->data)) ==0)
    {
      return current->data;
    }
    else if(nComp < 0)
      current=current->left;
    else 
      current=current->right;
  }
  return NULL;
  
}

void *delete(void *e, Node **root)
{
  if(*root == NULL) return NULL;
  void *data;
  Node *current=*root, *lastOne=NULL, *marked=NULL, *succesor=NULL;
  int nComp=0, nPreviousComp=0;

  while (current!=NULL)
  {
    lastOne=current;
    nPreviousComp=nComp;
    
    if((nComp=compare(e,current->data)) ==0)
    {
      break;
    }
    else
    {
      if(nComp < 0)
        current=current->left;
      else 
        current=current->right;
    }
      
  }
  if(current != NULL)
  {
    marked=current;
    if(marked->left==NULL && marked->right==NULL)
      succesor=NULL;
    else if (marked->left==NULL)
      succesor=marked->right;
    else if (marked->right==NULL)
      succesor=marked->left;
    else
    {
      current=marked->right;
      while (current->left!=NULL)
      {
        lastOne=current;
        current=current->left;
      }
      copy(marked->data,current->data);
      marked=current;
      if(current->right != NULL)  succesor=current->right;
      nPreviousComp=-1;
    }

    if(lastOne != NULL)
    {
      if(nPreviousComp<0)
        lastOne->left=succesor;
      else
        lastOne->right=succesor;
    }
    else
      *root=succesor;

    data=marked->data;
    free(marked);
    return data;

  }
  else
    return NULL;
  
}

void inorder(Node *root)
{
  Node *current= root;

  if(current != NULL)
  {
    inorder(current->left);
    process(current->data);
    inorder(current->right);
  }
}

void *findMinimum(Node *root)
{
  if(root == NULL) return NULL;

  Node *current=root;

  while (current->left !=NULL)
  {
    current=current->left;
  }
  return current->data;
}

void *findMaximum(Node *root)
{
  if(root == NULL) return NULL;

  Node *current=root;

  while (current->right !=NULL)
  {
    current=current->right;
  }
  return current->data;
}

int height(Node *root)
{
  if (root == NULL) return -1; 

  int leftHeight = height(root->left);
  int rightHeight = height(root->right);

  return 1 +(leftHeight > rightHeight ? leftHeight :rightHeight);
}

void deleteTree(Node **root)
{
  Node *current=*root;

  if(current != NULL)
  {
    deleteTree(&current->left);
    deleteTree(&current->right);
    memoryFree(current->data);
    free(current);
  }
  free(*root);
  root=NULL;
}

