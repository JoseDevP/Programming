/*Metodo de ordenacion quicksort para archivos*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct 
{
    char nombre[61];
    float nota;
}registro;

void quicksort(FILE *pf, int nreg);
void qs(FILE *pf, int inf, int sup);
void permutarRegistros(FILE *pf, int izq, int der);
void *campo(FILE *pf, int n);

int main(int argc, char *argv[])
{
    char respuesta='d';
    registro reg;
    int t_reg = sizeof(registro);
    FILE *pf;
    int nregs;

    if(argc != 2)
    {
        fprintf(stderr,"Sintaxis: %s archivo",argv[0]);
        exit(-1);
    }

    if((pf=fopen(argv[1],"r+b")) == NULL)
    {
        perror(argv[1]);
        exit(-1);
    }

    fseek(pf, 0L, SEEK_END);
    nregs = (int)ftell(pf)/t_reg;
    rewind(pf);
    quicksort(pf,nregs);
    printf("Archivo ordenado\n");

    do
    {
        printf("¿Desea visualizar el archivo? (s/n)  ");
    } while (tolower(respuesta) != 's' && tolower(respuesta) != 'n');

    if(respuesta == 's')
    {
        rewind(pf);
        fread(&reg,t_reg,1,pf);
        while (!ferror(pf) && !feof(pf))
        {
            printf("Nombre:    %s",reg.nombre);
            printf("Nota:    %f",reg.nota);
            fread(&reg,t_reg,1,pf);
        }
    }
    if(ferror(pf))
        perror("Error durante la lectura");

    fclose(pf);
}


void quicksort(FILE *pf, int nreg)
{
    qs(pf,0,nreg-1);
}

void qs(FILE *pf, int inf, int sup)
{
    register int izq, der;
    char mitad[20];

    izq=inf; der=sup;
    strcpy(mitad,campo(pf,(int)(izq+der)/2)) ;
    do
    {
        while(strcmp(campo(pf,izq),mitad) < 0 && izq < sup) izq++;
        while(strcmp(campo(pf,der),mitad) > 0 && der > inf) der--;
        if(izq <= der)
        {
            permutarRegistros(pf,izq,der);
            izq++; der--;
        }
    } while (izq <= der);
    if(der > inf)   qs(pf, inf, der);
    if(izq < sup)   qs(pf, izq, sup);
    
}

void permutarRegistros(FILE *pf, int izq, int der)
{
    int t_reg=sizeof(registro);
    registro x,y;

    fseek(pf, (long)izq * t_reg, SEEK_SET);
    fread(&x, t_reg,1,pf);
    fseek(pf,(long)der * t_reg, SEEK_SET);
    fread(&y,t_reg,1,pf);

    fseek(pf, (long)izq * t_reg, SEEK_SET);
    fwrite(&y, t_reg, 1, pf);
    fseek(pf,(long)der * t_reg, SEEK_SET);
    fwrite(&x, t_reg, 1, pf);

}

void *campo(FILE *pf, int n)
{
    int t_reg=sizeof(registro);
    static registro reg;

    fseek(pf,(long)n*t_reg,SEEK_SET);
    fread(&reg,t_reg,1,pf);
    if(ferror(pf))
    {
        perror("Error en la lectura del campo\n");
    }
    return reg.nombre;
}
