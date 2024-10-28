#if !defined (__VECTORESPEC_HPP__)
#define __VECTORESPEC_HPP__

#include <iostream>
#include <stdexcept>
#include <iomanip>

#include "vector.hpp"

template<> class CVector<void*>
{
    private:
        void** vector;
        size_t nElementos;

    protected:
        void** asignarMem(int);
        void liberarMemoria();

    public:
        CVector(int ne = 10);
        CVector(void**, int);
        CVector(std::initializer_list<void*> lista);

        CVector(const CVector<void*>&); //copia
        CVector<void*>& operator=(const CVector<void*>&); // copiar vector en otro

        void*& operator[](int i) const;

        CVector (CVector&&); //construcotr movimiento
        CVector<void*>& operator=(CVector<void*>&&); //asingacion rvalue

        CVector<void*>& operator=(int valor); 

        void*& elemento(size_t i) const;
        int longitud() const;

        ~CVector();
};

#endif


//Constructores

CVector<void*>::CVector(int ne)
{
    if(ne < 1)
        throw std::invalid_argument("Nº de elementos no valido");

    nElementos = ne;
    vector = asignarMem(nElementos);
    std::fill(vector, vector + nElementos, 0);
}

CVector<void*>::CVector(void** a, int ne)
{
    if(ne < 1)
        throw std::invalid_argument("Nº de elementos no valido");

    nElementos = ne;

    vector = asignarMem(nElementos);
    std::copy(a, a + nElementos, vector);
}

CVector<void*>::CVector(std::initializer_list<void*> lista)
{
    nElementos = lista.size();

    vector = asignarMem(nElementos);
    std::copy(lista.begin(), lista.end(), vector);

    /*
        Alternativa
        int i = 0;
        for ( const auto& x : lista)
            vector[i++] = x;
    */
}

void*& CVector<void*>::operator[](int i) const
{
    return vector[i];
}


CVector<void*>::CVector(const CVector& v)
{
    nElementos = v.nElementos;

    vector = asignarMem(nElementos);
    std::copy(v.vector, v.vector + nElementos, vector);
}

CVector<void*>::CVector (CVector&& v)
{
    //CVector myVector = crearVector();
    //solo hace falta pasarel numero de elementos y el vector ya que estaba vacio
    //ponemos el anterior a nullptr y a 0
    nElementos = v.nElementos;
    vector = v.vector;

    v.nElementos = 0;
    v.vector = nullptr;

}


//Destructor
CVector<void*>::~CVector()
{
    liberarMemoria();
}

//Otras
CVector<void*>& CVector<void*>::operator=(const CVector& v)
{
    if(this == &v) return *this;

    liberarMemoria();
    nElementos = v.nElementos;
    vector = asignarMem(nElementos);
    std::copy(v.vector, v.vector + nElementos, vector);
    return *this;
}

CVector<void*>& CVector<void*>::operator=(CVector&& v)
{
    //si es el mismo se envia el mismo otra vez
    //si no, se elimina el actual con el destructor
    //pasar el numero de elementos y el vector 
    //ponemos el anterior a nullptr y a 0
    if(this == &v) return *this;

    liberarMemoria();
    nElementos = v.nElementos;
    vector = v.vector;

    v.nElementos = 0;
    v.vector = nullptr;
    return *this;
}

void*& CVector<void*>::elemento(size_t i) const
{
    if(i < 0 || i >= nElementos)
        throw std::out_of_range("Indice fuera de rango");
    return vector[i];
}

int CVector<void*>::longitud() const
{
    return nElementos;
}

void** CVector<void*>::asignarMem(int nElems) 
{
    return new void*[nElems]; 
}


void CVector<void*>::liberarMemoria()
{
    if(vector != nullptr)
        delete[] vector;
    vector = nullptr;
}

CVector<void*>& CVector<void*>::operator=(int valor) 
{
    if (valor != 0) {
        throw std::invalid_argument("Solo se puede asignar 0 (nullptr) a punteros void*");
    }

    for (size_t i = 0; i < nElementos; ++i) {
        vector[i] = nullptr; 
    }

    return *this; 
}




