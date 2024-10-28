/* Escribir datos en un archivo registro a registro*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct 
{
    char nombre[40];
    char direccion[40];
    long telefono;
}registro;

bool existe(char *nombreArchivo);
void crearArchivo(char *nombreArchivo);
void fflushstdin(void);
char *readString(char *,int);

int main(void)
{
    char nombreArchivo[40];
    char resp='s';

    printf("Nombre del archivo: ");
    readString(nombreArchivo,sizeof(nombreArchivo));

    if(existe(nombreArchivo))
    {
        printf("El archivo existe ¿desea sobreescribirlo? (s/n)");
        resp=getchar();
        fflushstdin();
    }
    if(resp == 's')
    {
        crearArchivo(nombreArchivo);
    }
}

bool existe(char *nombreArchivo)
{
    FILE *pf=NULL;
    bool exis=false;
    if((pf=fopen(nombreArchivo,"r")) != NULL)
    {
        exis=true;
        fclose(pf);
    }
    return exis;
}

void crearArchivo(char *nombreArchivo)
{
    FILE *pf=NULL;
    registro reg;
    char resp;

    if((pf=fopen(nombreArchivo,"wb"))==NULL)
    {
        printf("El archivo no puede abrirse.");
        exit(1);
    }

    do
    {
        printf("nombre:   ");
        readString(reg.nombre, sizeof(reg.nombre));
        printf("dirección:   ");
        readString(reg.direccion, sizeof(reg.direccion));
        printf("teléfono:   ");
        scanf("%ld",&reg.telefono);
        fflushstdin();

        fwrite(&reg, sizeof(reg),1,pf);
        if(ferror(pf))
        {
            perror("Error durante la escritura");
            exit(2);
        }

        printf("¿Desea escribir otro registro? (s/n)  ");
        resp=getchar();
        fflushstdin();
    } while (resp =='s');
    
}

void fflushstdin(void)
{
    while(getchar() != '\n');
}

char *readString(char *str ,int n)
{
    char *fin, *c;
    fin=fgets(str, n, stdin);
    if(c=strchr(str,'\n'))  *c='\0';
    else if(!feof(stdin))
        fflushstdin();
    return fin;
}
