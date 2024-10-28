/*
    Queremos escribir un programa denominado grep que permita buscar palabras en uno o más 
    archivos de texto. Como resultado se visualizará, por cada uno de los archivos, su 
    nombre, el numero de linea y el contenido de la misma para cada una de las linias del 
    artchivo que contenga la palabra buscada.

    El programa grep, debera contener al menos las siguientes funciones:
    a)buscarCadena para buscar una cadena de caracteres dentro de otra. El prototipo de esta
    funcion sera:
        int buscarCadena(char *cadena1, char *cadena2);
    La funcion devolvera 1 si cadena2 se encuentra dentro de cadena1; en otro caso, devolverá 
    0;

    b)buscarEnFich para buscar una cadena de caracteres en un archivo de texto e imprimir
    el numero y el contenido de la linea que contiene a la cadena. EL prototipo será:

        void buscarEnFich(char *nombrefich, char *cadena);

    c)main para que utilizando las funciones anteriores permita buscar una palabra en uno o 
    más archivos.

    La forma de invocar a la aplicación sera asi:
        grep palabra archivo_1 archivo_2 ...archivo_n
*/
/*grep.c*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int buscarCadena(char *cadena1, char *cadena2);
void buscarEnFich(char *nombrefich, char *cadena);
char *leercadena(char *str, int n);
void fflushStdin(void);

int main(int argc, char *argv[])
{
    if(argc <2)
    {
        printf("Sintaxis: grep palabra archivo_1 archivo_2...archivo_n");
        exit(0);
    }
    else
    {
        int i=2; 
        while (i != argc)
        {
            buscarEnFich(argv[i],argv[1]);
            i++;
        }   
    }
    printf("No encontrado en ninguno de los archivos\n");
    exit(1);
}

int buscarCadena(char *cadena1, char *cadena2)
{
    if((strstr(cadena1,cadena2))!=NULL)
        return 1;
    else
        return 0;
}

void buscarEnFich(char *nombrefich, char *cadena)
{
    FILE *pf=NULL;
    char cadenaImportada[100];
    int found=0;
    int numLinea = 0;
    
    if((pf=fopen(nombrefich,"r"))==NULL)
    {
        perror("Error al abrir el archivo");
        exit(EXIT_FAILURE);
    }
    while (fgets(cadenaImportada, sizeof(cadenaImportada), pf))
    {
        numLinea++;
        found = buscarCadena(cadenaImportada, cadena); 
        if (found == 1)
        {
            printf("Palabra encontrada en el archivo %s, Línea %d: %s\n", nombrefich, numLinea, cadenaImportada);
            found = 1;
        }
    }

    if (!found)
    {
        printf("La palabra '%s' no fue encontrada en el archivo %s\n", cadena, nombrefich);
    }
    
    
    fclose(pf);
}

char *leercadena(char *str, int n)
{
    char *fin, *c;
    fin=fgets(str,n,stdin);
    if(c=strchr(str,'\n'))
        *c='\0';
    else if (!feof(stdin))
        fflushStdin();
    
    return fin;
}

void fflushStdin(void)
{
    while(getchar() != '\n');
}