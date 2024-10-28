/*
    Frequencia con la que aparecen las letras en un texto
    (solo minusculas alfabeto ingles)
*/
#include <stdio.h>
#define N_ELEMENTOS ('z'-'a'+1) //26

int main(void)
{
    int c[N_ELEMENTOS]={0};
    char car;

    printf("Introducir texto\n");
    printf("Para finalizar introducir la marca EOF\n\n");
    while ((car = getchar()) != EOF)
    {
        if(car >= 'a' && car <= 'z')
            c[car-'a']++;

        for (car = 'a'; car <= 'z'; car++)
            printf("  %c",car);
        printf("\n--------------------------------------"
               "------------------------------------\n");

        for (car = 'a'; car <= 'z'; car++)
            printf("%3d",c[car-'a']);
        putchar('\n');
        
    }
    
}