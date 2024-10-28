#pragma once
#include <stdio.h>

typedef struct
{
    char nombre[60];
    unsigned long dni;
}alumno;

typedef struct elem
{
    alumno datos;
    struct elem *izdo;
    struct elem *dcho;
}nodo;
