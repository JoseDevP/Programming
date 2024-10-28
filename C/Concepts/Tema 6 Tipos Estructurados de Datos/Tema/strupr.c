/*strupr.c convierte minusculas a maysuculas*/

#include <stdio.h>
#include <string.h>
#define LONG_MAX 81

void minusculasMayusculas(char str[])
{
    int desp='a'-'A';
    for (int i = 0; str[i] != '\0'; i++)
    {
        if(str[i]>='a' && str[i]<='z')
        {
            str[i]-=desp;
        }
    }
    
    
}

void mayusculasMinusculas(char str[])
{
    int desp='a'-'A';
    for (int i = 0; str[i] != '\0'; i++)
    {
        if(str[i]>='A' && str[i]<='Z')
        {
            str[i]+=desp;
        }
    }
    
}

int main(void)
{
    char cadena[LONG_MAX];
    
    puts("Introduce una frase para que se convierta en mayusculas");
    fgets(cadena,sizeof(cadena),stdin);
    minusculasMayusculas(cadena);
    puts(cadena);

    puts("Introduce una frase para que se convierta en minusculas");
    fgets(cadena,sizeof(cadena),stdin);
    mayusculasMinusculas(cadena);
    puts(cadena);
}