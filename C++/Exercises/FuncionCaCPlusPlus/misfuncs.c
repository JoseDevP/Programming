#include <stdio.h>

void cuadrados(int n[], int max)
{
    int i;
    printf("\nnumero     cuadrado\n");
    for (i = 0; i < max; i++)
        printf("  %d      %d\n", n[i], n[i]*n[i]);
}



