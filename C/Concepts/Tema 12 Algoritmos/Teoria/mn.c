#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256

void mezclaNatural(FILE *f);
int distribuir(FILE *f, FILE *fa, FILE *fb);
int mezclar(FILE *fa, FILE *fb, FILE *f);


int main(int argc, char* argv[])
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
    int n_tramos=0; 

    do
    {
        fa=tmpfile();
        fb=tmpfile();
        rewind(f);

        n_tramos=distribuir(f,fa,fb);

        if(n_tramos <= 1)
        {
            rmtmp();
            return;
        }
        rewind(f), rewind(fa), rewind(fb);

        n_tramos=mezclar(fa,fb,f);
        fclose(fa), fclose(fb);
    } while (n_tramos != 1);
    rmtmp();
}

int distribuir(FILE *f, FILE *fa, FILE *fb)
{
    FILE *faux=fa;
    int n_tramos=1;
    char anterior[MAX];
    char actual[MAX];

    if(fgets(actual,MAX,f))
        fputs(actual,fa);
    else
        return 0;
    
    strcpy(anterior,actual);

    while (fgets(actual,MAX,f))
    {
        if(strcmp(actual,anterior) < 0)
        {
            faux= (faux == fa) ? fb : fa;
            n_tramos++;
        }
        strcpy(anterior,actual);
        fputs(actual,faux);
    }
    
    return n_tramos;
}

int mezclar(FILE *fa, FILE *fb, FILE *f)
{
    int n_tramos=1;
    char a_anterior[MAX], a_actual[MAX], b_actual[MAX], b_anterior[MAX];

    fgets(a_actual,MAX,fa); strcpy(a_anterior, a_actual);
    fgets(b_actual,MAX,fb); strcpy(b_anterior, b_actual);

    while (!feof(fa) && !feof(fb))
    {
        if(strcmp(a_actual,b_actual) < 0)
        {
            if(strcmp(a_actual,a_anterior) < 0)
            {
                do
                {
                    strcpy(b_anterior,b_actual);
                    fputs(b_actual,f);
                } while (fgets(b_actual,MAX,fb) && strcmp(b_actual,b_anterior) > 0);
                n_tramos++;
                strcpy(b_anterior, b_actual);
            }
            else
            {
                strcpy(a_anterior,a_actual);
                fputs(a_actual,f);
                fgets(a_actual,MAX,fa);
            }
        }
        else
        {

        }
    }
    if(feof(fb))
    {
        fputs(a_actual,f);
        while(fgets(a_actual, MAX, fa))
            fputs(a_actual,f);
    }
    else if(feof(fa))
    {
        fputs(b_actual,f);
        while (fgets(b_actual,MAX,fb))
            fputs(b_actual,f);
    }
    
}

