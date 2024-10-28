#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lcde.h"

typedef struct 
{
    char name[50];
    double mark;
}Data;

void showList(tlcse *list)
{
    int i=0, len=list->nElements;
    Data *student=NULL;

    while (i < len)
    {
        student=(Data *)obtain(i,list);
        printf("%s %g\n", student->name, student->mark);
        i++;
    }
    if(len==0)  printf("Empty List");
}

void freeMemory(tlcse *list)
{
    Data *student=NULL;
    goToBeginning(list);
    student=(Data *)delete(list);
    
    while (student)
    {
        free(student);
        student=(Data *)delete(list);
    }   
}

Data *readDataStudent()
{
    Data *student=NULL;
    char name[50];
    double mark;

    printf("\nName: ");
    scanf("%[^\n]",&name);
    printf("Mark: ");
    scanf("%lf",&mark); while (getchar() != '\n');
    
    student=(Data *)malloc(sizeof(Data));
    if(!student) return 0;

    strcpy(student->name,name);
    student->mark=mark;

    return student;
}

void error1(tlcse *list)
{
    freeMemory(list);
    error();
}

void error2(Data *student, tlcse *list)
{
    free(student);
    freeMemory(list);
    error();
}

int main(void)
{
    char answ='y';
    Data *student=NULL; 
    tlcse lcde;
    initializeLcde(&lcde);

    while (answ == 'y')
    {
        if(!(student=readDataStudent())) error1(&lcde);
        if(!insert(student,&lcde))  error2(student,&lcde);

        printf("Do you want to insert another student? (y/n) ");
        answ=getchar(); while(getchar() != '\n');
    }
    printf("\nThe element of the 2 position will be the current:\n");
    if(!goToPosition(2,&lcde))  printf("Index out of bounds\n");

    printf("Delete current element.\n");
    if(student = (Data *)delete(&lcde)) free(student);
    else
        printf("Is not posible to find the element\n");
    
    printf("\nGo to element 1 and insert another one.\n");
    if(!goToPosition(1,&lcde))  printf("Index out of bounds\n");
    printf("Actual position: %d\n",lcde.position);
    if(!(student=readDataStudent()))    error1(&lcde);
    if(!insert(student,&lcde))  error2(student,&lcde);

    printf("Go to the end and insert new student:\n");
    goToEnd(&lcde);
    if(!(student=readDataStudent()))    error1(&lcde);
    if(!insert(student,&lcde))  error2(student,&lcde);

    printf("Go to the previous and insert new student:\n");
    goToPreviousOne(&lcde);
    if(!(student=readDataStudent()))    error1(&lcde);
    if(!insert(student,&lcde))  error2(student,&lcde);

    printf("\nList:\n");
    showList(&lcde);

    freeMemory(&lcde);
}
