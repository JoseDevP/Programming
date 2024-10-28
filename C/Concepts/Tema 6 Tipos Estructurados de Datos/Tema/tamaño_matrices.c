/*tamaño matrices*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    //typedef double matriz_1d[100];
    //typedef double matriz_2d[10][10];

    //matriz_1d matriz1;
    //matriz_2d matriz2;
    //
    ////tamaño filas matriz unidimensional
    //printf("Tamaño matriz unidimensional %d\n",(int)sizeof(matriz1)/sizeof(matriz1[0]));
    //printf("De otra forma %d\n\n",(int)sizeof(matriz1)/sizeof(double));

    ////tamaño filas
    //printf("Filas matriz bidimensional %d\n",(int)sizeof(matriz2)/sizeof(matriz2[0]));
    ////tamaño columnas
    //printf("De otra forma %d\n",(int)sizeof(matriz2[0])/sizeof(matriz2[0][0]));
    //printf("Todo entero %d\n\n",(int)sizeof(matriz2)/sizeof(double));

    char c1[81]="abcdefghijk";
    char *c2="abcdefghijk";
    char c3[]="abcdefghijk";
    char *c4=c3;
                            //z es size, d entero
    printf("c1: %s, tamaño: %zd, longitud: %zd\n",c1,sizeof(c1),strlen(c1));
    printf("c2: %s, tamaño: %zd, longitud: %zd\n",c2,sizeof(c2),strlen(c2));
    printf("c3: %s, tamaño: %zd, longitud: %zd\n",c3,sizeof(c3),strlen(c3));
    printf("c4: %s, tamaño: %zd, longitud: %zd\n",c4,sizeof(c4),strlen(c4));

    //c1: abcdefghijk, tama├▒o: 81, longitud: 11
    //c2: abcdefghijk, tama├▒o: 8, longitud: 11 //8 es el tamaño de un puntero
    //c3: abcdefghijk, tama├▒o: 12, longitud: 11 //12 es por 11bytes + \0
    //c4: abcdefghijk, tama├▒o: 8, longitud: 11
}