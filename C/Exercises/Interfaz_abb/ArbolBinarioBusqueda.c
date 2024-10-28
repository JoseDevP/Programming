#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "abb.h"

typedef struct 
{
    char name[50];
    double mark;
}Data;

void ver(void *data)
{
    Data *student = (Data *)data;
    if(!student)
    {
        printf("Ha habido un error");
        return;
    }    
    printf("%s %g\n",student->name,student->mark);
}


int compare(void *data1, void *data2)
{
    char *nom1=((Data *)data1)->name;
    char *nom2=((Data *)data2)->name;

    return strcmp(nom1,nom2);
}

void copy(void *data1, void *data2)
{
    *((Data *)data1)=*((Data *)data2);
}

void process(void *data)
{
    Data *student = (Data *)data;
    if(!student)    return;
    printf("%s %g\n",student->name,student->mark);
}

void memoryFree(void *data)
{
    free((Data *)data);
}

void showTree (Node *root)
{
    inorder(root);
}

void error1(Node *root)
{
    deleteTree(&root);
    error();
}

void error2(Data *student, Node *root)
{
    free(student);
    deleteTree(&root);
    error();
}

int main(void)
{
    int cod=0;
    char name[50];
    double mark;

    Node *root=NULL;
    Data *student=NULL ,*aux=NULL;

    printf("Input data, End with eof.\n");
    printf("Name:  ");
    while (scanf("%[^\n]",name) != EOF)
    {
        printf("Mark:  ");
        scanf("%lf",&mark); while(getchar() != '\n');

        student=(Data *)malloc(sizeof(Data));
        if(!student) error1(root);
        
        strcpy(student->name,name);
        student->mark=mark;

        cod=insert(student,&root);

        if(cod==0) error2(student,root);
        if(cod == 2)
        {
            if(mark >= 0)
            {
                aux=(Data *)search(student,root);
                aux->mark=mark;
            }
            else
            {
                aux=deleteNode(student,&root);
                free(aux);
                printf("Deleted node.\n");
            }
            free(student);
        }
        printf("Name: ");
    }
    printf("\n");
    
    printf("\nArbol:\n");
    showTree(root);


    return 0;
}


