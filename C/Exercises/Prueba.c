#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define FILAS 10

int factorizado(int r);

int main(void)
{
    FILE *flujo;
    char numFila='A';
    int r=1;
    char buffer[80];

    if((flujo=fopen("prueba.d","r"))!=NULL)
    {
        for (int i = 0; i < FILAS; i++)
        {
            fscanf(flujo,"\t%s %c: %d",buffer,&numFila,&r);
            printf("\t%s %c: %d\n",buffer,numFila,r);
        }
    }
    else
    {
        if((flujo = fopen("prueba.d","w"))==NULL)
        {
            perror("Error al abrir el archivo");
            exit(EXIT_FAILURE);
        }

        for (int i = 0; i < FILAS; i++)
        {
            fprintf(flujo,"\tFila %c: %d\n",numFila++,factorizado(r++));
        }
            
        if(ferror(flujo))
        {
            perror("Error al escribir los datos");
            exit(EXIT_FAILURE);
        }
        printf("El archivo no existia y lo hemos creado.\n");
        printf("\nEjecute de nuevo el programa.\n");
        
    }
    fclose(flujo);


}

int factorizado(int r)
{
    if (r == 0 || r == 1)
    {
        return 1;
    }
    return r * factorizado(r - 1);
}