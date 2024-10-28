/*
    Realizar un programa que permita utiliza el terminal como un diccionario Inglés-Español
    esto es, al introducir una palabra en inglés se escribirá en español.
    El numero de parejas de palabras es variable , pero limitado a un maximo de 100. 
    La longitud máxima de cada palabra sera de 40 caracteres.
    ej: Introducimos la pareja de palabras:
        book   libro
        green  verde
        mouse  ratón
    Una vez introducido pasamos al modo traduccion, de forma que si tecleamos green, la 
    respuesta ha de ser verde. Si la palabra no se encuentra, se emitirá un mensaje que lo
    indique.

    El programa constará al menos de dos funciones.
    a) crearDiccionario 
    b)Traducir
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMITPAREJAS 100

typedef struct 
    {
        char *p_español;
        char *p_ingles;
    }pareja;

int crearDiccionario(pareja **diccionario,int nPar);
char *readString(char *str, int n);
void liberarMemoria(pareja **diccionario, int num_parejas) ;
void Traducir(pareja **diccionario,int numero_parejas);

int main(void)
{
    int nPar=0, correcto=0, numero_parejas=0;
    pareja **diccionario=NULL;

    do
    {
        printf("¿Cuantas parejas quieres que haya en el diccionario?\n");
        printf("Numero de palabras: ");
        correcto=scanf("%d",&nPar);
        while(getchar() != '\n');
    } while (!correcto || nPar<0 || nPar > LIMITPAREJAS);
    
    if((diccionario=(pareja **)malloc(nPar*sizeof(pareja *))) == NULL)
        return -1;

    for (int i = 0; i < nPar; i++)
    {
        if((diccionario[i]=(pareja*)malloc(sizeof(pareja)))==NULL)
            return -1;
    }
    

    numero_parejas=crearDiccionario(diccionario,nPar);

    Traducir(diccionario,numero_parejas);

    liberarMemoria(diccionario, numero_parejas);
}

void liberarMemoria(pareja **diccionario, int num_parejas)
{
    for (int i = 0; i < num_parejas; i++)
    {   
        free(diccionario[i]->p_español);
        free(diccionario[i]->p_ingles);
        free(diccionario[i]);
    }
    free(diccionario);
}

int crearDiccionario(pareja **palabras,int nPar)
{
    char pareja[40];
    int filas=0,col=0;
    printf("Introduce las parejas:\n");
    printf("Para finalizar introducir una palabra nula\n");
    while (filas<nPar)
    {
        printf("Palabra %d en Espanol: ", filas + 1);
        if (readString(pareja, 40) != NULL && (col = strlen(pareja)) > 0)
        {
            if ((palabras[filas]->p_español = (char *)malloc(col + 1)) == NULL)
                return 0;
            strcpy(palabras[filas]->p_español, pareja);
        }
        else
        {
            break;
        }    

        printf("Palabra %d en Ingles: ", filas + 1);
        if (readString(pareja, 40) != NULL && (col = strlen(pareja)) > 0)
        {
            if ((palabras[filas]->p_ingles = (char *)malloc(col + 1)) == NULL)
                return 0;
            strcpy(palabras[filas]->p_ingles, pareja);
        }
        else
        {
            break;
        }

        filas++;
    }
    
    return filas;
    
}

char *readString(char *str, int n)
{
    char *fin,*c;
    fin=fgets(str,n,stdin);
    if((c=strchr(str,'\n')))
        *c='\0';
    else if(!feof(stdin))
        while(getchar() != '\n');
    return fin;
}

void Traducir(pareja **palabras,int numero_parejas)
{
    char palabra_a_traducir[40];
    int num_letras;
    int f=0;
    do
    {
        printf("Introduce una palabra en ingles para traducirla:\n");
    } while (!readString(palabra_a_traducir,40));

    num_letras=strlen(palabra_a_traducir);


    while (f<numero_parejas)
    {
        if(strcmp(palabras[f]->p_ingles,palabra_a_traducir)==0)
        {
            printf("%s",palabras[f]->p_español);
            break;
        }
        f++;
    }
    
    
}