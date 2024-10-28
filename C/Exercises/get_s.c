#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[10];
    printf("Introduce una cadena (fgets): ");
    fgets(str,sizeof(str),stdin);
    puts(str);
    printf("longitud = %d\n",strlen(str));

    printf("Introduce una cadena (gets_s): ");
    gets_s(str,sizeof(str));
    puts(str);
    printf("longitud = %d\n",strlen(str));
}