#if !defined (__VECTOR_HPP__)
#define __VECTOR_HPP__
#include <iostream>

class CVector
{
    private:
        double* vector;
        size_t nElementos;

    protected:
        double *asignarMem(int);
        void liberarMemoria();

    public:
        CVector(int ne = 10);
        CVector(double*, int);
        CVector(std::initializer_list<double> lista);

        CVector(const CVector&); //copia
        CVector& operator=(const CVector&); // copiar vector en otro

        double& operator[](int i) const { return vector[i]; }; 

        CVector (CVector&&); //construcotr movimiento
        CVector& operator=(CVector&&); //asingacion rvalue

        double& elemento(size_t i) const;
        int longitud() const;

        ~CVector();
};

#endif