/*
<funcion busquedaBin(matriz a, valor que queremos buscar)>
    DO WHILE (no encontrado y exista un intervalo donde buscar)
    x=elemento mitad del intervalo de busqueda
        IF (valor > x )THEN
            buscar "valor" en la segunda mitad del intervalo de busqueda
        ELSE 
            buscar "valor" en la primera mitad del intervalo de busqueda
        ENDIF
    ENDDO
    IF (se encontro valor)THEN
        retornar indice
    ELSE 
        retornar -1
    ENDIF
END <busqueda_S>
*/

int busquedaBin(int a[], int n_elementos, int v)
{
    int mitad, inf=0, sup=n_elementos-1;

    if(n_elementos == 0) return -1;   

    do
    {
        mitad=(inf +sup)/2;
        if(v > a[mitad])
            inf =mitad +1;
        else
            sup=mitad -1;
    } while (a[mitad] != v && inf<=sup);
    
    if(a[mitad] == v)
        return mitad;
    else 
        return -1;
}

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int lista[] = {0,1,2,3,4,5,6,7,8,9,10};
    int n_elementos = sizeof(lista) / sizeof(lista[0]);
    int valor_buscado = 9;
    int resultado = busquedaBin(lista, n_elementos, valor_buscado);

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
