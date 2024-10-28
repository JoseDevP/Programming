/*
    Realizar un programa que lea una cadena de caracteres e imprima el resultado que se obtiene
    cada vez que se realize una rotación de carácter a la derecha sobre dicha cadena.
    El proceso finalizará cuando se haya obtenido nuevamente la cadenad de caracteres original.
    ej:
        HOLA AHOL LAHO OLAH HOLA
*/

#include <stdio.h>
#include <string.h>

char* readString(char *str, int n);
void rotarCadena(char* str);

int main(void)
{
    char Cadena[50];
    readString(Cadena,sizeof(Cadena));
    rotarCadena(Cadena);
}

char* readString(char *str, int n)
{
    char *fin, *c;

    fin=fgets(str,n,stdin);
    if(c=strchr(str,'\n'))
        *c='\0';
    else
        while(getchar() != '\n');
    return fin;
}

void rotarCadena(char* str)
{
    char temp;
    int tamaño=strlen(str);

    for (int z = 0; z < tamaño-1; z++)
    {
        for (int i = 0; i < tamaño-1; i++)
        {
            for (int j = tamaño-1-i; j > 0; j--)
            {
                temp=str[j];
                str[j]=str[j-1];
                str[j-1]=temp;
            }
        }
        printf("%s ",str);
    }
    
    
}


