/* puts.c */

#include <stdio.h>
#include <string.h>

int main(void)
{
    char *c=NULL;
    char texto[80];
    
    printf("Introducir una linea de texto:\n");
    //while (1)
    //{
    //    fgets(texto,sizeof(texto),stdin);
    //    if(feof(stdin) || ferror(stdin)) break;
    //    if((c=strchr(texto,'\n'))!=NULL) *c='\0';
    //}
    c=fgets(texto,sizeof(texto),stdin);
    
    printf("\n El texto introducido es:\n");
    puts(texto);
    puts("\n Se escribe por segunda vez:");
    puts(c);


}