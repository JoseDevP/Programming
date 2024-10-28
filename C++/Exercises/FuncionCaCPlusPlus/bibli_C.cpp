#include <iostream>

extern "C" void cuadrados(int n[], int max);

int main()
{
    int nro[20], i = 0, r = 0;

    printf("Para finalizar introduzca el caracter eof \n\n");
    printf("Introduzca numeros\n");
    while (i < 20 && r != EOF)
    {
        r=scanf("%d", &nro[i++]);
        if(r==0)    {--i; fflush(stdin);}
    }
    
    printf("%d\n",i-1);
    cuadrados(nro, i-1);
    printf("\nproceso finalizado\n");
    return 0;
}