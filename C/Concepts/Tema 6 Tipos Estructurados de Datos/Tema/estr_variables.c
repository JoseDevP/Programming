/*Estructuras Variables*/
/*
Numero referencia
Titulo
Autor
Editorial
clase publicacion (libro o revista)
Edicion(libro)
Año publicacion(libro)
Nombre revista(revistas)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#define N 100

enum clase //tipo enumerado
{
    libro,revista
};

typedef struct 
{
    unsigned numref;
    char titulo[30];
    char autor[20];
    char editorial[25];
    enum clase libro_revista;
    union 
    {
        struct //libro
        {
            unsigned edicion;
            unsigned anyo;
        }libros;
        char nomrev[30]; //revista
    }lr;
}tficha;

void escribir(tficha[] , int);
int leer(tficha[] , int);
void fflushstdin(void);
char *readString(char*,int);


int main(void)
{
    setlocale(0,"");
    static tficha biblioteca[N];
    int n=0;
    system("cls");
    printf("Introducir datos\n");
    n=leer(biblioteca,N);
    system("cls");
    printf("Listado de libros y revistas.\n");
    escribir(biblioteca,n);
}
void escribir(tficha bibli[] , int n)
{
    int k=0;
    for (k = 0; k < n; k++)
    {
        printf("%d  %s\n",bibli[k].numref,bibli[k].titulo);
        printf("%s - Ed. %s\n",bibli[k].autor,bibli[k].editorial);

        switch (bibli[k].libro_revista)
        {
        case libro:
            printf("Edición %u - año %u\n",bibli[k].lr.libros.edicion,bibli[k].lr.libros.anyo);
            break;
        case revista:
            /* code */
            break;
        }
        
    }
    
}
int leer(tficha bibli[], int NMAX)
{
    int clase;
    char resp='s';
    int k=0; // numero elementos introducidos

    while (tolower(resp=='s' && k<NMAX))
    {
        system("cls");
        printf("Número de refer.           ");
        scanf("%u",&bibli[k].numref); fflushstdin();

        printf("Título.                    ");
        readString(bibli[k].titulo,sizeof(bibli[k].titulo));

        printf("Autor.                     ");
        readString(bibli[k].autor,sizeof(bibli[k].autor));

        printf("Editorial.                 ");
        readString(bibli[k].editorial,sizeof(bibli[k].editorial));

        do
        {
            printf("Libro o revista (0 = libro, 1 = revista)");
            scanf("%d",&clase); fflushstdin();
        } while (clase != 0 && clase !=1);

        if(clase == libro)
        {
            bibli[k].libro_revista=libro;
            printf("Edición             ");
            scanf("%u",&bibli[k].lr.libros.edicion); fflushstdin();
            printf("Año de publicacción ");
            scanf("%u",&bibli[k].lr.libros.anyo); fflushstdin();

        }
        else
        {
            bibli[k].libro_revista=revista;
            printf("Nombre revista      ");
            readString(bibli[k].lr.nomrev,sizeof(bibli[k].lr.nomrev));
        }
        
        k++;

        do
        {
            printf("\n¿Mas datos a introducir? s/n ");
            resp=getchar();
            fflushstdin();
        } while (tolower(resp) != 's' && tolower(resp) != 'n');
        
    }
    return k;
    
}
void fflushstdin(void)
{
    if(!feof(stdin) || !ferror(stdin))
    {
        while(getchar() != '\n');
    }
}
char *readString(char* str,int n)
{
    char *fin, *c;
    fin=fgets(str,n,stdin);
    if(c=strchr(str,'\n')) 
        *c=0;
    else if(!feof)
        while(getchar() != '\n');
    return fin;
}