/* Leer datos de un archivo registro a registro*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct 
{
    char nombre[40];
    char direccion[40];
    long telefono;
}registro;

bool existe(char *nombreArchivo);
void mostrarArchivo(char *nombreArchivo);
void fflushstdin(void);

int main(void)
{
    char nombreArchivo[30];

    printf("Nombre del archivo:  ");
    scanf("%s",nombreArchivo);
    fflushstdin();

    if(existe(nombreArchivo))
        mostrarArchivo(nombreArchivo);
    else
        printf("El archivo no existe");

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

void mostrarArchivo(char *nombreArchivo)
{
    FILE *pfe=NULL;
    FILE *pfs=NULL;

    registro reg;
    char resp=0;

    if((pfe = fopen(nombreArchivo, "rb"))==NULL)
    {
        printf("El archivo no puede abrirse.");
        exit(EXIT_FAILURE);
    }

    printf("¿desea escribir los datos por la impresora? (s/n)  ");
    resp=getchar();
    fflushstdin();

    if(resp=='s')
    {
        if((pfs=fopen("lpt1","w"))==NULL)
        {
            printf("La impresora no está disponible.\n");
            pfs=stdout;

            printf("Pulse <Entrar> para continuar ");
            while(getchar() != '\n');
        }
    }
    else
        pfs=stdout;

    fread(&reg,sizeof(reg),1,pfe);

    while (!ferror(pfe) && !feof(pfe))
    {
        system("cls");
        fprintf(pfs,"Nombre:     %s\n",reg.nombre);
        fprintf(pfs,"Direccion:     %s\n",reg.direccion);
        fprintf(pfs,"Telefono:     %ld\n\n",reg.telefono);

        printf("Pulse <Entrar> para continuar ");
        while(getchar() != '\n');

        fread(&reg,sizeof(reg),1,pfe);
    }
    if(ferror(pfe))
        perror("Ha habido un error durante la lectura");
    fclose(pfe);
    fclose(stdout);
    
}

void fflushstdin(void)
{
    while(getchar() != '\n');
}