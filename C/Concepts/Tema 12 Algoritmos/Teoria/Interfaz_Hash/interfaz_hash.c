#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "interfaz_hash.h"


void error()
{
    printf("Insuficiente memoria\n");
    exit(1);
}

int numeroPrimo(int n) //no menores que 2
{
    if(n <2)
    {
        printf("El numero debe de ser mayor que 2\n");
        return 0;
    }
    int primo = 0;
    int i, r=(int)sqrt((double)n);

    if(n % 2 == 0) n++;
    while (!primo)
    {
        primo=1;
        for (i = 3; i <= r; i += 2)
            if(n % i == 0) primo=0;
        if(!primo) n += 2;
    }
    return n;
}

void IniciarMatrizHash(tMatrizHash *mh, int n_elementos)
{
    if(n_elementos < 1)
        mh->n_elementos=101;
    else
        mh->n_elementos=numeroPrimo(n_elementos);
    mh->matrizHash=(void **)malloc(mh->n_elementos * sizeof(void *));
    if(mh->matrizHash == NULL)  error();
    memset(mh->matrizHash, 0 , mh->n_elementos * sizeof(void *));
}

int hashIn(void *x, tMatrizHash mh)
{
    int i;
    int conta=0;
    int insertado=0;

    i=fa(x, mh);

    while (conta < mh.n_elementos)
    {
        if(mh.matrizHash[i] == NULL)//libre
        {
            mh.matrizHash[i]=x;
            insertado=1;
            break;
        }
        else //duplicada?
        {
            if(comparar(x, mh.matrizHash[i]) == 0)
            {
                printf("Error: Clave duplicada\n");
                insertado=0;
                break;
            }
            else // colision
            {
                i++; conta++;
                if(i == mh.n_elementos) i =0;
            }
        }
    }
    if(conta == mh.n_elementos)
    {
        printf("Error: Matriz llena\n");
        insertado=0;
    }
    return insertado;
}

void *hashOut(void *x, tMatrizHash mh)
{
    int i;
    int conta=0;
    int encontrado=0;

    i=fa(x,mh);

    while (!encontrado && conta < mh.n_elementos)
    {
        if(mh.matrizHash[i] == NULL) return NULL;
        if(comparar(x, mh.matrizHash[i]) == 0)
        {
            x=mh.matrizHash[i];
            encontrado = 1;
        }
        else
        {
            i++; conta++;
            if(i == mh.n_elementos) i=0;
        }
    }
    if(conta == mh.n_elementos)
        return NULL;
    else
        return x;
    
}

void borrarMatrizHash(tMatrizHash mh)
{
    for (int i = 0; i < mh.n_elementos; i++)
        if(mh.matrizHash[i]) liberarMemoria(mh.matrizHash[i]);
    free(mh.matrizHash);
}