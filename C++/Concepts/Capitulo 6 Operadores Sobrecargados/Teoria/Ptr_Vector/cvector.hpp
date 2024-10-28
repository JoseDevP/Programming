#if !defined (__VECTOR_HPP__)
#define __VECTOR_HPP__
#include <iostream>
#include <algorithm>

class CVector
{
    private:
        double* vector;
        size_t nElementos;

    protected: 
        double *asignarMem(int);
        static void* asignarMem(const size_t&, const char&);
        void liberarMemoria();
        void liberarMem(void* p, const size_t& tam);

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

        void* operator new(size_t tam);
        void* operator new[](size_t tam);

        void operator delete(void* p, size_t tam);
        void operator delete[](void* p, size_t tam);

        ~CVector();
};

#endif