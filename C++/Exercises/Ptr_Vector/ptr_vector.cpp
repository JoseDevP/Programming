#include <iostream>
#include "ptr_vector.hpp"

Ptr_CVector::Ptr_CVector(int n)
{
    p.pVector = new CVector*[n];
    p.nElementos = n;
    std::fill(p.pVector, p.pVector + n, static_cast<CVector*>(0));
}

Ptr_CVector::~Ptr_CVector()
{
    delete [] p.pVector;
}