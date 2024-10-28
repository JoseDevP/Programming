#pragma once

struct matriz2d
{
    double** p;
    int filas;
    int cols;
};

void DestruirMatriz(matriz2d& m);
bool ConstruirMatriz(matriz2d& m);
void LeerMatriz(matriz2d& m);
void MostrarMatriz(matriz2d& m);
int CrearMenu(const char * opMenu[], int num_opciones);