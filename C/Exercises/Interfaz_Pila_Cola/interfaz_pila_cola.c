#include "pc.h"
#include "interfaz_pila_cola.h"

// Pila:
void iniciarPila(tpila *lista)
{
  initializeList(lista);
}

int meterEnPila(void *e, tpila *lista)
{
  return addToBeginning(e, lista);
}

void *sacarDePila(tpila *lista)
{
  return eraseLastOne(lista);
}

// Cola:
void iniciarCola(tcola *lista)
{
  initializeList(lista);
}

int meterEnCola(void *e, tcola *lista)
{
  return addToEnd(e, lista);
}

void *sacarDeCola(tcola *lista)
{
  return eraseFirstOne(lista);
}
