/*Copiar el contenido de un archivo en otro*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *org=NULL, *dest=NULL;
    char buffer[100];

    if(argc != 3)
    {
        printf("Sintaxis: copiar origen destino");
    }
    else
    {
        if( ((org=fopen(argv[1],"rb"))==NULL) || ((dest=fopen(argv[2],"wb"))==NULL) )
        {
            perror("No se han podido abrir los archivos.");
            exit(EXIT_FAILURE);
        }
        
        while (!ferror(org) || !feof(dest))
        {
            fgets(buffer,sizeof(buffer),org);
            fputs(buffer,dest);
            if(feof(org)) break;
        }
        
        if(ferror(org) || ferror(dest))
            perror("Error al copiar los datos");
        else
            printf("Se han copiado %d lineas",strlen(buffer));

        fclose(org);
        fclose(dest);
    }
}