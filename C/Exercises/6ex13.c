/*
    Leer una linea de entrada  y de como resultado la lnea leida y su longitud o
    numero de caracteres.
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    char cadena[100];
    char *c;
    fgets(cadena,sizeof(cadena),stdin);
    if(c=strchr(cadena,'\n'))
        *c='\0';
    else
        while(getchar() != '\n');
    
    printf("La linea es: %s y su longitud es de %d",cadena,strlen(cadena));
}