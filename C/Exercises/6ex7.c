/*Escribir un programa que dé como resultado la frecuencia con la que aparece cadad una de 
las parejas de letras adyacentes de un texto introducido por el teclado.
No se ha´ra diferencia de las mayúsucla o minusuclas. El resultado se presentará en forma de
tabla:
    a   b   c   d   e   f   .   .   .   z
a   0   4   0   2   1   0   .   .   .   1
b   8   0   0   0   3   1   .   .   .   0
c
d
e
f
.
.
z

*/
#include <stdio.h>
#include <ctype.h>
#define DIM ('z'-'a'+1) //filas columnas de la tabla

int main (void)
{
    static int tabla[DIM][DIM];
    char car;
    char carant=' '; //Anterior

    printf("Introducir texto. Para finalizar introducir la marca EOF\n");
    while ((car=getchar())!=EOF)
    {
        car=tolower(car);
        if((carant >= 'a' && carant <= 'z') && (car >= 'a' && car <= 'z'))
            tabla[carant-'a'][car-'a']++;
        carant=car;
    }
    
    printf(" ");
    for (char c = 'a'; c <= 'z'; c++)
        printf("  %c",c);
    putchar('\n');
    
    for (char f = 'a'; f <= 'z'; f++)
    {
        putchar(f);
        for (char c = 'a'; c <= 'z'; c++)
            printf("%3d",tabla[f-'a'][c-'a']);
        putchar('\n');
    }
}