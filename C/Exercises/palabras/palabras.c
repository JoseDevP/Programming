#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "interfaz_abb.h" 

typedef struct 
{
  char *word;
  int nAppear;
}Data;

int totalWords  = 0;
int totalDifferentWords  = 0;

int compare(void *data1, void *data2)
{
  return strcmp(((Data *)data1)->word,((Data *)data2)->word);
}

void memoryFree(void *data)
{
  free(((Data *)data)->word);
  free((Data *)data);
}

void plusAppear(void *data)
{
  Data *dat=(Data*)data;
  dat->nAppear++;
}

void copy(void *data1, void *data2)
{
  *((Data *)data1)=*((Data *)data2);
}

void process(void *data)
{
  Data *dat=(Data *)data;
  if(!dat)  return;
  printf("%s %d\n",dat->word,dat->nAppear);
}

void showTree(Node *root)
{
  inorder(root);
}

int isAlfa(int c) // c es una letra entre la A - Z o a - z
{
  return (tolower(c) >= 'a' && tolower(c) <= 'z');
}

int isVocalAc(int c)
{
  return (c == 160 || c == 130 || c==161 || c==162 || c==163);
}

char *readWord(FILE *pf)
{
  int c;
  char *word=NULL, *begin=NULL;

  while ((c=fgetc(pf)) != EOF && !isAlfa(c) && !isVocalAc(c));

  if(c==EOF)  return NULL;

  word=(char *)malloc(256);
  if(!word) return 0;
  begin=word;
  *word++=c;

  while ((c=fgetc(pf)) != EOF && isAlfa(c) || isVocalAc(c))
    *word++=c;
  *word = '\0';

  word=realloc(begin,word-begin+1); //inclure el \0

  totalWords++;
  return word;
  
}

void error1(Node **root)
{
  deleteTree(root);
  error();
}

int main(int argc, char *argv[])
{
  Node *root = NULL;
  Data *ocurrence = NULL, *found=NULL;
  char *word = NULL;
  FILE *pf =NULL;

  if(argc < 2)
    pf=stdin;
  else if((pf=fopen(argv[1], "r")) ==NULL)
  {
    perror(argv[1]);
    return -1;
  }

  while (word = readWord(pf))
  {
    ocurrence=(Data *)malloc(sizeof(Data));
    if(!ocurrence)  error1(&root);
    ocurrence->word=word;
    found=(Data *)search(ocurrence,root);
    ocurrence->nAppear=1;
    if(!found)
    {
      if(!insert(ocurrence,&root))
      {
        free(ocurrence->word);
        free(ocurrence);
        error1(&root);
      }
      totalDifferentWords++;
    }
    else
    {
      plusAppear(found);
      free(ocurrence->word);
      free(ocurrence);
    }

  }
  
  //Show Tree
  printf("\nTree\n");
  showTree(root);
  printf("\n Total words: %d\n",totalWords);
  printf("\n Total diffent words: %d\n",totalDifferentWords);

  deleteTree(&root);
  fclose(pf);
  return 1;
}


