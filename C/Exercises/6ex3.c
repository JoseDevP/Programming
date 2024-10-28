/*
    Lee cadena de caracteres y la almacene en una matirz.
    Utilizando una función convertir los caracteres escritos en mayusculas a minusculas.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* readString(char *str, int n);
void convertirCadena(char *str, int n);
int main(void)
{
    char Cadena[50];
    readString(Cadena,sizeof(Cadena));
    convertirCadena(Cadena,sizeof(Cadena));
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

void convertirCadena(char *str,int n)
{
    for (int i = 0; i < n; i++)
    {
        if(str[i] >= 'a' && str[i] <= 'z')
            str[i]=toupper(str[i]);
        else if(str[i] >= 'A' && str[i] <= 'Z')
            str[i]=tolower(str[i]);
    }
    printf("%s",str);
}