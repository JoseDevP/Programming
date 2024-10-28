/*
    Función para copiar una cadena en otra
    strcpy
    copycad.c
*/
#include <stdio.h>
#define LONGCAD 81

void copyCad(char[],char[]);

int main(void)
{
    char cadena1[LONGCAD], cadena2[LONGCAD];

    printf(("Introducir una cadena: "));
    fgets(cadena1,LONGCAD,stdin);
    copyCad(cadena2,cadena1);
    printf("La cadena copiada es: %s\n",cadena2);
    printf("%c",*cadena1);
}

void copyCad(char p[], char q[])
{   
    while(*p++=*q++);//mientras no sea null
    //int i=0;
    //while ((p[i] = q[i]) != '\0')
    //    i++;
    //while ((*p = *q) != '\0')
    //{
    //    p++;
    //    q++;
    //}
}