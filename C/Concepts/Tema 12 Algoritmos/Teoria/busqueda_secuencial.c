/*
<funcion busqueda_S(matriz a, valor que queremos buscar)>
    i=0
    DO WHILE (no encontrado)
        IF (valor = a[i])
            encontrado
        ENDIF
        i=i+1;
    ENDDO
END <busqueda_S>
*/

#include <stdio.h>
#include <stdlib.h>

int busqueda(int a[], int n, int v)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == v)
        {
            return i; 
        }
    }
    return -1; 
}

int main(void)
{
    int lista[] = {0,1,2,3,4,5,6,7,8,9,10};
    int n_elementos = sizeof(lista) / sizeof(lista[0]);
    int valor_buscado = 5;
    int resultado = busqueda(lista, n_elementos, valor_buscado);

    if (resultado != -1)
    {
        printf("Valor %d encontrado en el índice %d\n", valor_buscado, resultado);
    }
    else
    {
        printf("Valor %d no encontrado\n", valor_buscado);
    }

    return 0;
}
