#include "cvector.hpp"
#include <algorithm>

class Ptr_CVector
{
    private:
        struct matriz_d
        {
            CVector** pVector;
            int nElementos;
        } p;
    public:
        Ptr_CVector(int n = 1);
        ~Ptr_CVector();
        matriz_d* operator->() {return &p;}
        CVector*& operator[](int i) const {return p.pVector[i];}
};