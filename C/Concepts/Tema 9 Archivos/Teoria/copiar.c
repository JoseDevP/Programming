/*Copiar el contenido de un archivo en otro*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *org=NULL, *dest=NULL;
    int c, contar=0;

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
        
        while (!ferror(org) || !ferror(dest))
        {
            c=fgetc(org);
            if(feof(org)) break;
            contar++;
            fputc(c,dest);
        }
        
        if(ferror(org) || ferror(dest))
            perror("Error al copiar los datos");
        else
            printf("Se han copiado %d caracteres",contar);

        fclose(org);
        fclose(dest);
    }
}