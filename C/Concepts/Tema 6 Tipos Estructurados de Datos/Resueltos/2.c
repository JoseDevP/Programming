/*Escribir un programa que dé como resultado la frecuencia con la que aparece cadad una de 
las parejas de letras adyacentes de un texto introducido por el teclado.
No se ha´ra diferencia de las mayúsucla o minusuclas. El resultado se presentará en forma de
tabla:
    a   b   c   d   e   f   .   .   .   z
a   0   4   0   2   1   0   .   .   .   1
b   8   0   0   0   3   1   .   .   .   0
c
d
e
f
.
.
z

*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define NMAXIMO 100

int leerCadena(char *str,int n);
int imprimirCadena(char *texto,int cantidad_de_texto);
void crearTabla(char *texto,int cantidad_de_texto);


int main(void)
{
    char texto[NMAXIMO];

    int cantidad_de_texto=leerCadena(texto,NMAXIMO); 
    
    imprimirCadena(texto,cantidad_de_texto);

    crearTabla(texto,cantidad_de_texto);
    
    

}

int leerCadena(char *str,int n)
{
    char *fin, *c;
    
    fin=(fgets(str,sizeof(str),stdin));
    if(fin!=NULL)
    {
        if(c=strchr(str,'\n'))
            *c='\0';
        else if(!ferror(stdin))
            while(getchar() != '\n');

        for (int i = 0; str[i]; i++)
        {
            str[i] = tolower((unsigned char)str[i]);
        }
    }
    
    return strlen(str);

}

int imprimirCadena(char *texto,int cantidad_de_texto)
{
    printf("%d\n",cantidad_de_texto);

    for (int i = 0; i<cantidad_de_texto; i++)
    {
        printf(" %c ",texto[i]);
    }
    printf("\n\n\n");
}

void crearTabla(char *texto,int cantidad_de_texto)
{
    int table_letters[26][26]={0};

    if(cantidad_de_texto>0)
    {
        for (int i = 0; i < cantidad_de_texto - 1; i++)
        {
            char current = texto[i];
            char next = texto[i + 1];

            if (current >= 'a' && current <= 'z' && next >= 'a' && next <= 'z')
            {
                table_letters[current - 'a'][next - 'a']++;
            }
        }

        printf("   ");
        for (char c = 'a'; c <= 'z'; c++)
        {
            printf(" %c ", c);
        }
        printf("\n");

        for (int i = 0; i < 26; i++)
        {
            printf(" %c ", 'a' + i);
            for (int j = 0; j < 26; j++)
            {
                printf(" %d ", table_letters[i][j]);
            }
            printf("\n");
        }
    }

    
}