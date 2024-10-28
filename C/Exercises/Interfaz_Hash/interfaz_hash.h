#pragma once

typedef struct 
{
    void **matrizHash;
    int n_elementos;
}tMatrizHash;


void error();

int numeroPrimo(int n);

void IniciarMatrizHash(tMatrizHash *mh, int n_elementos);

int fa(void *arg, tMatrizHash mh);

int comparar(void *arg1, void *arg2);

void liberarMemoria(void *arg);

int hashIn(void *x, tMatrizHash mh);

void *hashOut(void *x, tMatrizHash mh);

void borrarMatrizHash(tMatrizHash mh);