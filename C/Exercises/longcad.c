/*
    Función LongCad
    devuelve la longitud de una cadena
*/
#include <stdio.h>

int longcad(char *);

int main(void)
{
    char *cadena="abcd"; // se añade al final \0
    printf("%d\n",longcad(cadena)); //Escribe 4
}

int longcad(char *cad)
{
    char *temp=cad;
    //while (*temp != '\0')
    //    temp++;
    while (*temp++) //mientras no sea null o sea \0
    return (temp-cad-1);
    
}