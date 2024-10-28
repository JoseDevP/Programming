#include <iostream>
#include "pcvector.hpp"

CVector2D::CVector2D(int f, int c)
{
    filas = f;
    cols = c;
    pCvector = asignarMem(filas);
    for (int i = 0; i < filas; i++)
        pCvector[i] = CVector(cols);
     
}

CVector2D::CVector2D(const CVector2D& v)
{
    filas = v.filas;
    cols = v.cols;
    pCvector = asignarMem(filas);
    for (int i = 0; i < filas; i++)
        pCvector[i] = v.pCvector[i];
}

CVector2D::~CVector2D()
{
    liberarMemoria();
}

CVector2D& CVector2D::operator=(const CVector2D& v)
{
    if(this == &v) return *this;

    filas = v.filas;
    cols = v.cols;
    liberarMemoria();
    pCvector = asignarMem(filas);
    for (int i = 0; i < filas; i++)
        pCvector[i] = v.pCvector[i];
    return *this;
}


CVector* CVector2D::asignarMem(int nElem)
{
    CVector *p = new CVector[nElem];
    return p;
}

void CVector2D::liberarMemoria()
{
    delete[] pCvector;
}

CVector2D::CVector2D(CVector2D&& v)
{
    filas = v.filas;
    cols = v.cols;
    pCvector = v.pCvector;

    v.filas = 0;
    v.cols = 0;
    v.pCvector = nullptr;
}

CVector2D& CVector2D::operator=(CVector2D&& v)
{
    if(this == &v)  return *this;
    liberarMemoria();
    filas = v.filas;
    cols = v.cols;
    pCvector = v.pCvector;

    v.filas = 0;
    v.cols = 0;
    v.pCvector = nullptr;
    return *this;
}


