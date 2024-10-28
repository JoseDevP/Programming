#if !defined (__PTRVECTOR_HPP__)
#define __PTRVECTOR_HPP__

#include "cvector.hpp"

class CVector2D
{
    private:
        CVector* pCvector;
        int filas;
        int cols;
    protected:
        CVector* asignarMem(int n);
        void liberarMemoria();
    public:
        CVector2D(int f = 1, int c = 1);
        CVector2D(const CVector2D&);
        CVector2D(CVector2D&&);
        ~CVector2D();

        CVector2D& operator=(const CVector2D&);
        CVector2D& operator=(CVector2D&&);
        CVector& operator[](int i) const { return pCvector[i]; }; //operador [i] -> devolver elemtno
        int numFilas() { return filas; };
        int numCols() { return cols; };
};

#endif