#include <stdio.h>
#include <stdlib.h>

#include "abb.h"
/*
                25
              /    \
           17        32
        /     \
       13      21
             /    \
           18      23 
    
*/
//Interfaz Arbol Binario de Busqueda

void error()
{
    printf("Error al asignar espacio\n");
    exit(1);
}

Node *newNode()
{
    Node *q=(Node *)malloc(sizeof(Node));
    return q;
}

void *search(void *data, Node *root)
{
    Node *current=root;
    int nComp=0;

    if(data == NULL) return NULL;

    while (current != NULL)
    {
        if((nComp = compare(data,current->data))==0)
            return current->data;
        else if(nComp < 0)
            current=current->left;
        else 
            current=current->right;
    }
    return NULL;    
}

int insert(void *data, Node **root)
{
    Node *lastOne=NULL,*current=*root;
    int nComp=0;
    if(data == NULL) return -1;

    while (current != NULL)
    {
        if((nComp = compare(data,current->data))==0)
            break;
        else
        {
            lastOne=current;
            if(nComp < 0)
                current=current->left;
            else 
                current=current->right;
        }
        
    }

    if(current == NULL)
    {
        Node *new=newNode();
        if(!new)    error();
        new->data=data;
        new->left=NULL;
        new->right=NULL;

        if(lastOne==NULL)
        {
            *root=new;

        }
        else if(nComp <0)
        {
            lastOne->left=new;
        }
        else
        {
            lastOne->right=new;
        }
        return 1;
    }
    else
        return 2;
}

void *deleteNode(void *data, Node **root)
{
    Node *lastOne=NULL,*current=*root, *marked=NULL, *succesor=NULL;
    int nComp=0, nCompPrevious=0;
    void *dataDeletedMarked=NULL;

    if(data == NULL) return NULL;

    while (current != NULL)
    {
        nCompPrevious=nComp;
        if((nComp = compare(data,current->data))==0)
            break;
        else
        {
            lastOne=current;
            if(nComp < 0)
                current=current->left;
            else 
                current=current->right;
        }
        
    }
    if(current != NULL)
    {
        marked=current;
        if((marked->left ==NULL) && (marked->right==NULL))
            succesor=NULL;
        else if (marked->right ==NULL)
            succesor=marked->left;
        else if (marked->left ==NULL)
            succesor=marked->right;
        else
        {
            succesor=marked->right;
            while (current->left!=NULL)
            {
                lastOne=current;
                current=current->left;
            }
            copy(marked->data,current->data);
            marked=current;
            if(current->right==NULL) lastOne->left=NULL;
            succesor=current->right;
            dataDeletedMarked=current->data;
            
        }

        if(lastOne!=NULL)
        {
            if(nCompPrevious < 0 )
                lastOne->left=succesor;
            else
                lastOne->right=succesor;
        }   
        else
            *root=succesor;
        


        dataDeletedMarked=marked->data;
        free(marked);
        return dataDeletedMarked;
    }
    else
        return NULL;
    
}

void inorder(Node *root)
{
    Node *current=root;
    if(current !=NULL)
    {
        inorder(current->left);
        process(current->data);
        inorder(current->right);
    }
}

void deleteTree(Node **root)
{
    Node *current=*root;
    if(current !=NULL)
    {
        deleteTree(&current->left);
        deleteTree(&current->right);
        memoryFree(current->data);
        free(current);
    }
    *root=NULL;
}
