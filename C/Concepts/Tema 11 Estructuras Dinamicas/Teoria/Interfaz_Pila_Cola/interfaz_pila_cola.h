#pragma once

#include "list.h"
#include "pc.h"


typedef List tpila;
typedef List tcola;


void iniciarPila(tpila *lista);


void iniciarCola(tcola *lista);


int meterEnPila(void *e, tpila *lista);


void *sacarDePila(tpila *lista);


int meterEnCola(void *e, tcola *lista);


void *sacarDeCola(tcola *lista);
