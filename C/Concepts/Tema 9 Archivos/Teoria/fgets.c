/*fgets.c*/
#include <stdio.h>
#include <stdlib.h>
#define N 81

int main(void)
{
    FILE *pf=NULL;
    char buffer[N], nomfi[13];

    printf("Nombre del fichero: ");
    scanf("%s",nomfi);

    if((pf=fopen(nomfi,"w+"))==NULL)
    {
        printf("El fichero %s no puede abrirse",nomfi);
        exit(1);
    }

    printf("Fichero %s abierto",nomfi);
    printf("Introducir datos. Finalizar cada linea con <Entrar>\n");
    printf("Para terminar introduzca la marca eof\n\n");

    while ((fgets((buffer),sizeof(buffer),stdin)) !=NULL)
    {
        fputs(buffer,pf);
    }

    if(ferror(pf))
    {
        perror("Error al escribir");
        exit(2);
    }

    rewind(pf);

    while ((fgets(buffer,N,pf))!=NULL)
        printf("%s",buffer);
    
    if(ferror(pf))
    perror("Error durante la lectura");

    fclose(pf);
    
    
}