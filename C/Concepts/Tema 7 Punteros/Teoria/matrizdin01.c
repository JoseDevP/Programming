/* Matriz dinámica de una dimensión*/
//VOLVER A HACER PERO YO SOLO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void *insertarElemento(int *m, int *pnElementos, int pos);
void asignarValoresAleatorios(int *m, int n);
void mostrarMatriz(int *m, int n);

int main(void)
{
    int *m = NULL, *q = NULL;
    int correcto = 0, nElementos = 0;

    do
    {
        printf("Número de elementos de la matriz: ");
        correcto = scanf("%d", &nElementos);
        while(getchar() != '\n');
    } while (!correcto || nElementos < 1);

    if((m = (int *)malloc(nElementos * sizeof(int))) ==NULL)
    {
        printf("Insuficiente espacio de memoria\n");
        return -1;
    }    

    memset(m,0,nElementos*sizeof(int));

    asignarValoresAleatorios(m, nElementos);
    mostrarMatriz(m, nElementos);

    //insertar elemento en la pos 5
    int pos=2;
    if((q=(int *)insertarElemento(m,&nElementos,pos))==NULL)
        printf("No es posible realizar la inserción\n");
    else
        m=q;
    
    //insertar en la ultima posicion
    pos=nElementos;
    if((q=(int *)insertarElemento(m,&nElementos,pos))==NULL)
        printf("No es posible realizar la inserción\n");
    else
        m=q;
    
    mostrarMatriz(m,nElementos);

    free(m);
    exit(0);
}



void *insertarElemento(int *m, int *pnElementos, int pos)
{
    int n=*pnElementos;

    if(pos < 0 || pos > n) return NULL;

    m=(int *) realloc(m, (n+1)*sizeof(int));

    if(m != 0)
    {
        for (int i = n; i > pos; i--)  //9--  >5     I=9 
            m[i] = m[i-1];
        m[pos] = 0;
        //Actualizar el numero de elementos de la matriz
        *pnElementos=n+1;
    }
    return m;
}

void asignarValoresAleatorios(int *m, int n)
{
    srand((unsigned)time(NULL));
    for (int i = 0; i < n; i++)
    {
        m[i]=rand() % 101;
    }
    
}

void mostrarMatriz(int *m, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ",m[i]);
    }
    printf("\n");
}








