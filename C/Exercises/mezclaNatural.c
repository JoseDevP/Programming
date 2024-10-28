/*
    Ordenar un archivo utilizando el metodo de mezcla natural,
    Se tratade un archivo de texto que almacena una lista de nombres
    El nombre del archivo recibe a travae de la linea de ordenes
    La ordenadocion se realiza en orden ascendiente alfabetico ascendente
        Funciones:
            mezclaNatural
            distribuir
            mezclar
            main
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 256

void mezclaNatural(FILE *f);
int distribuir(FILE *f, FILE *fa, FILE *fb);
int mezclar(FILE *fa, FILE *fb, FILE *f);

int main(int argc, char *argv[])
{
    FILE *parchivo = NULL;
    char respuesta=0, str[MAX];

    if(argc != 2)
    {
        fprintf(stderr,"Sintaxis: %s archivo",argv[0]);
        exit(-1);
    }

    if((parchivo=fopen(argv[1],"r+")) == NULL)
    {
        perror(argv[1]);
        exit(-1);
    }

    mezclaNatural(parchivo);
    do
    {
        printf("¿Desea viusalizar el archivo? (s/n)  ");
        respuesta=getchar();
    } while (tolower(respuesta) != 's' && tolower(respuesta) != 'n');

    if(respuesta == 's')
    {
        rewind(parchivo);
        while (fgets(str,MAX,parchivo))
            printf("%s",str);
    }

    if(ferror(parchivo))
        perror("Error durante la lectura");

    fclose(parchivo);
    
}

void mezclaNatural(FILE *f)
{
    FILE *fa=NULL, *fb=NULL;
    int nro_tramos=0;

    do
    {
        fa=tmpfile();
        fb=tmpfile();
        rewind(f);

        nro_tramos = distribuir(f,fa,fb);
        if(nro_tramos <= 1)
        {
            rmtmp(); // borrar todos los archivos temporales creados.
            return;
        }
        rewind(f), rewind(fa), rewind(fb);

        nro_tramos = mezclar(fa,fb,f);
        fclose(fa);
        fclose(fb);
    } while (nro_tramos != 1);
    
}

int distribuir(FILE *f, FILE *fa, FILE *fb)
{
    FILE *faux = fa;
    char str[MAX];
    char str_ant[MAX];
    int nro_tramos= 1;

    if(fgets(str_ant, MAX, f))
        fputs(str_ant,fa);
    else
        return 0;
    
    while (fgets(str,MAX,f))
    {
        if(strcmp(str, str_ant) < 0)
        {
            faux=(faux == fa) ? fb: fa;
            ++nro_tramos;
        }

        strcpy(str_ant, str);
        fputs(str, faux);
    }
    return(nro_tramos);
}

int mezclar(FILE *fa, FILE *fb, FILE *f)
{
    char stra[MAX], strb[MAX], stra_ant[MAX], strb_ant[MAX];
    int nro_tramos = 1;

    fgets(stra, MAX, fa); strcpy(stra_ant,stra);
    fgets(strb, MAX, fb); strcpy(strb_ant,strb);

    while (!feof(fa) && !feof(fb))
    {
        if(strcmp(stra,strb) < 0)
        {
            if(strcmp(stra, stra_ant) < 0)
            {
                strcpy(stra_ant, stra);
                do
                {
                    fputs(strb, f);
                    strcpy(strb_ant, strb);
                } while (fgets(strb, MAX, fb) && strcmp(strb, strb_ant) > 0);
                ++nro_tramos;
                strcpy(strb_ant, strb);
            }
            else
            {
                strcpy(stra_ant, stra);
                fputs(stra, f);
                fgets(stra, MAX, fa);
            }
        }
        else
        {
            if(strcmp(strb, strb_ant) < 0)
            {
                strcpy(strb_ant, strb);
                do
                {
                    fputs(stra, f);
                    strcpy(stra_ant, stra);
                } while (fgets(stra, MAX, fa) && strcmp(stra, stra_ant) > 0);
                ++nro_tramos;
                strcpy(stra_ant, stra);
            }
            else
            {
                strcpy(strb_ant, strb);
                fputs(strb, f);
                fgets(strb, MAX, fb);
            }
        }
    
    }
    if(feof(fb))
    {
        fputs(stra,f);
        while(fgets(stra, MAX, fa))
            fputs(stra,f);
    }
    else if(feof(fa))
    {
        fputs(strb,f);
        while(fgets(strb, MAX, fb))
            fputs(strb,f);
    }
    return(nro_tramos);
    
}



