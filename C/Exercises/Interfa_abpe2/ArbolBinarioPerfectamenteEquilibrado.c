#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "abpe.h"

typedef struct  
{
    char name[50];
    double mark;
}Data;


void *readData()
{
  char name[50];
  double mark;

  Data *student=NULL;

  scanf("%[^\n]",name);

  scanf("%lf", &mark); while(getchar() != '\n');

  student=(Data *)malloc(sizeof(Data));
  if(!student)  error();
 
  strcpy(student->name,name);
  student->mark=mark;
  

  return student;
}

int compare(void *data1, void *data2)
{
  char *name1=((Data *)data1)->name;
  char *name2=((Data *)data2)->name;

  return strcmp(name1,name2);
}

void process(void *data)
{
  Data *student=(Data *)data;
  if(!student)  return
  printf("Student: %s, Mark: %g\n",student->name,student->mark);
}

void memoryFree(void *data)
{
  free((Data *)data);
}

void showTree(Node *root)
{
  inorder(root);
}

int main(void)
{
  Node *root=NULL;
  Data *student=NULL, *studentSearched;
  int nNodes = 0, pos=0;

  printf("Number of nodes:\n");
  scanf("%d",&nNodes); while(getchar() != '\n');

  root=buildTree(nNodes);
  if(root == NULL)  return 0;

  printf("\nArbol:\n");
  showTree(root);

  printf("Node 0,1,2...");
  scanf("%d",&pos); while(getchar() != '\n');

  student=obtainNode(pos,root);
  if(student == NULL)
    printf("Searched failed\n");
  else
    printf("Student %s, mark: %g",student->name, student->mark);

  printf("Search for all the appears in the tree.\n");
  student=readData();
  if(student)
  {
    studentSearched = search(student,root,&pos);
    if(studentSearched == NULL) printf("No found\n");
    while (studentSearched != NULL)
    {
      printf("Node %2d, nota es %g\n",pos,studentSearched->mark);
      pos++;
      studentSearched = search(student,root,&pos);
    }
    free(student);
  }  
  else
    printf("No memory available\n");

  deleteTree(&root);
  return 0;
}