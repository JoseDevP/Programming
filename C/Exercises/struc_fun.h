/*misFunciones.h*/
#include <stdio.h>
#pragma once

typedef struct 
{
    double **p;
    int filas;
    int cols;
}tmatriz2D;


tmatriz2D *AsignarMem2D(int,int);
void LiberarMem2D(tmatriz2D *);
void Visualizar(tmatriz2D *);
void AsignarDatos(tmatriz2D *);

void visualizar(double **,int,int);
void **asignarMemoriaMatriz2D(int filas, int cols, size_t size);
void liberarMemoriaMatriz2D(void **,int);

