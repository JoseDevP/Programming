/* test.c */

#include <stdio.h>
#include <stdbool.h>

int leerDato(const char *formato, void *pdato);

int main(void)
{
    double dato;
    int m[100]={0},i=0,r=0,n=0;

    printf("Dato: "); leerDato("%lf",&dato);
    while (true)
    {
        printf("m[%d]: ",i);r=leerDato("%d",&m[i]);
        if(r==EOF) break;
        i++;
    }
    n=i;
    printf("%g ",dato);
    for(i=0;i<n;++i)
        printf("%d",m[i]);
    printf("\n");
    
}

int leerDato(const char *formato, void *pdato)
{
    int r=0;
    while (r==0)
    {
        r=scanf(formato,pdato);
        if(r=0)
            printf("Dato Incorrecto. Introduzca otro");
        while(getchar() != '\n');
    }
    return r;
}