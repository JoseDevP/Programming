#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "abpe.h"



void error()
{
    printf("Error while data assigment.\n");
    exit(1);
}

Node *newNode()
{
    Node *q=(Node *)malloc(sizeof(Node));
    return q;
}
 
Node *buildTree(int n)
{
    Node *node=NULL;
    int nl=0, nr=0;
    if(n == 0)  return NULL;

    nl=n/2;
    nr=n - nl - 1;

    node=newNode();
    if(!node)   return NULL;
    node->nNodes=n;
    node->left=buildTree(nl);
    node->data=readData();
    node->right=buildTree(nr);

    return node;
}

void *obtainNode(int nodo_i, Node *root)
{
    int nl=0, n=0;

    
    if(root == NULL || nodo_i < 0 || nodo_i >= root->nNodes)   return NULL;
    if(root)    n=root->nNodes;

    nl=n/2;

    if(nodo_i == nl)
        return root->data;
    else if (nodo_i < nl)
        return obtainNode(nodo_i,root->left);
    else
        return obtainNode(nodo_i -nl -1,root->right);
    return NULL;
    
}

void *search(void *data, Node *root, int *pos)
{
    int i = 0;
    void *res=NULL;
    searchNode(data,root,&res,pos,&i);
    return res;
}

void searchNode(void *data, Node *root, void **res, int *pos, int *i)
{
    Node *current=root;

    if(current != NULL && *res != NULL)
    {
        searchNode(data,root->left,res,pos,i);
        if(*res != NULL && (*pos)-- <= 0)
        {
            if(compare(data,current->data)==0)
            {
                *res=current->data;
                *pos=*i;
            }
        }
        (*i)++;
        searchNode(data,root->right,res,pos,i);
    }
}

void inorder(Node *root)
{
    Node *current=root;

    if(current != NULL)
    {
        inorder(current->left);
        process(current->data);
        inorder(current->right);
    }
}

void deleteTree(Node **root)
{
    Node *current=*root;

    if(current != NULL)
    {
        deleteTree(current->left);
        deleteTree(current->right);
        memoryFree(current->data);
        free(current);
    }
    *root=NULL;
}

