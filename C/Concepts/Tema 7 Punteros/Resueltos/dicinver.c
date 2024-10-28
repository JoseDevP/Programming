/*
    Generar un diccionario inverso.
    Estos se caracterizzan por presentar las palabras en orden alfabetico ascendente pero 
    observando las palabras desde su ultimo caracter hasta el primero 
    Ej:
        hola -> aloh

    una aplicacion es buscar palabras que rimen

    a)Escribir la funcion comparar cuyo prototipo es el siguiente
        int comparar(char *cad1, char *cad2);
    Esta función comparará cadena1 y cadena2, pero observando las plabras desde su último 
    caracter hasta el primero. 
    La función devolverá los siguientes resultados:
        >0 Si cadena1 está alfabeticamente después que cadena 2
        0 si cadena1 y cadena2 son iguales
        <0 si cadena1 está alfabeticamente antes que cadena 2

    b)funcion ordenarCadenas con el prototipo que se indica a continuacion para ordenar las
    palabras de la matriz palabra en orden alfabético ascendente.
        void ordenarCadena(char **palabra, int filas);
    filas indica el numero total de palabras que tiene la matriz palabra.
    Para ordenadr las palabras se empleará el método de inserción

    c)Escribir un programa que lea las palabras desde la entrrada estandar y las almacene en 
    una matriz dinámica de cadenas de caracteres, y tras ordenarlas utilizando las funciones
    anteriores, las visualice en la salida estándar. Para ello escirba, además de las 
    funciones anteriores las siguietnes funciones:

    int leerCadenas(char **palabra, int nFilas);
    void visualizarCadenas(char **palabra, unsigned filas);
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comparar(char *cad1, char *cad2);
void ordenarPalabras(char **palabra, int filas);
int leerPalabras(char **palabra, int nFilas);
char *readString(char *cadena,int n);
void visualizarPalabras(char **palabra, unsigned filas);

int main (void)
{
    char **palabras=NULL;
    int correcto=0, nFilas=0, filasFinales=0;
    do
    {
        printf("Introduce el numero de filas: ");
        correcto=scanf("%d",&nFilas);
        while(getchar() != '\n');
    } while (!correcto || nFilas<0);

    if((palabras=(char **)malloc(nFilas*sizeof(char *))) == NULL)
        return -1;

    filasFinales=leerPalabras(palabras,nFilas);
    ordenarPalabras(palabras,filasFinales);
    visualizarPalabras(palabras,filasFinales);

    for (int i = 0; i < filasFinales; i++)
    {
        free(palabras[i]);
    }
    free(palabras);
    return 0;
    
}

int leerPalabras(char **palabra,int nFilas)
{
    char pal[100];
    int f=0, col=0;
    printf("Introduce las palabras.\n");
    printf("Si quieres finalizar introduce una palabra nula\n");
    while (f<nFilas && ((col=strlen(readString(pal,100)))>0))
    {
        if((palabra[f]=(char *)malloc(col+1)) == NULL)
            return 0;
            strcpy(palabra[f],pal);
        f++;
    }
    
}

char *readString(char *cadena,int n)
{
    char *fin, *c;
    fin=fgets(cadena,n,stdin);
    if((c=strchr(cadena,'\n')))
        *c='\0';
    else if(!ferror(stdin))
        while(getchar() != '\n');
    return fin;
}

void visualizarPalabras(char **palabra, unsigned filas)
{
    for (int i = 0; i < filas; i++)
    {
        printf("%s ",palabra[i]);
    }

    printf("\n\n");
    
}

int comparar(char *cad1, char *cad2)
{
    int i,j;
    j=strlen(cad1)-1;
    i=strlen(cad2)-1;
    while (i>0 && j>0)
    {
        if(cad1[i] != cad2[j])
            return (cad1[i]-cad2[j]);
        i--;
        j--;
    }
    return (cad1[i] == cad2[j]) ? i -j :cad1[i] -cad2[j];
}

void ordenarPalabras(char **palabra, int filas)
{
    char *aux;
    int i=0, k=0;
    for (int i = 1; i < filas; i++)
    {
        aux=palabra[i];
        k=i -1;
        while ((k>=0) && (comparar(aux,palabra[k])<0))
        {
           palabra[k+1]=palabra[k];
           k--;
        }
        palabra[k+1]=aux;
    }
    

}