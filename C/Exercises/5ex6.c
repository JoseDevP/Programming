/*
    Realizar un programa que solicite texto letras, 
    espacios,comas y punto final
    Despues lo escriba modificado de forma que a la A le corresponda la K
    a la B la L... a la O la Y, a l P la Z, a la Q la A y igual para las minusculas.

    A 65 es K 75
    B 66 es L 76

*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    char frase[50];
    printf("Introduce una frase:\n");
    while(scanf("%s",&frase)!=1){while(getchar()!='\n');}
    
    for (int i = 0; i < strlen(frase); i++) {
        char c = frase[i];
        
        if(c >= 'A' && c <= 'Z')
        {
            c=( (c-'A'+ 10) % 26 + 'A');
        }
        else if(c >= 'a' && c <= 'z')
        {
            c=( (c-'a'+ 10) % 26 + 'a');
        }
        
        frase[i] = c;
    }

    // Imprimir la frase modificada
    printf("Frase cambiada: %s", frase);
    printf("Frase cambiada: %s",frase);
    
}