#include <iostream>
#include <stdexcept>
#include <iomanip>
#include "cvector.hpp"

//Constructores

CVector::CVector(int ne)
{
    if(ne < 1)
        throw std::invalid_argument("Nº de elementos no valido");

    nElementos = ne;
    vector = asignarMem(nElementos);
    std::fill(vector, vector + nElementos, 0);
}

CVector::CVector(double* a, int ne)
{
    if(ne < 1)
        throw std::invalid_argument("Nº de elementos no valido");

    nElementos = ne;

    vector = asignarMem(nElementos);
    std::copy(a, a + nElementos, vector);
}

CVector::CVector(std::initializer_list<double> lista)
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



CVector::CVector(const CVector& v)
{
    nElementos = v.nElementos;

    vector = asignarMem(nElementos);
    std::copy(v.vector, v.vector + nElementos, vector);
}

CVector::CVector (CVector&& v)
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
CVector::~CVector()
{
    liberarMemoria();
}

//Otras
CVector& CVector::operator=(const CVector& v)
{
    if(this == &v) return *this;

    liberarMemoria();
    nElementos = v.nElementos;
    vector = asignarMem(nElementos);
    std::copy(v.vector, v.vector + nElementos, vector);
    return *this;
}

CVector& CVector::operator=(CVector&& v)
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

double& CVector::elemento(size_t i) const
{
    if(i < 0 || i >= nElementos)
        throw std::out_of_range("Indice fuera de rango");
    return vector[i];
}

int CVector::longitud() const
{
    return nElementos;
}

void* CVector::operator new(size_t tam)
{
    return asignarMem(tam, '\0');
}

void* CVector::operator new[](size_t tam)
{
    return asignarMem(tam, '\0');
}

void* CVector::asignarMem(const size_t& tam, const char& car)
{
    void *p = ::operator new(tam);
    std::fill_n(static_cast<char*>(p), tam, car);
    return p; 
} 

void operator delete(void* p, size_t tam)
{
    liberarMem(p, tam);
}

void operator delete[](void* p, size_t tam)
{
    liberarMem(p, tam);
}

void liberarMem(void* p, const size_t& tam)
{
    if(p) std::fill_n(static_cast<char*>(p), tam, '\0');
    ::operator delete(p);
}


double* CVector::asignarMem(int nElems)
{
    double* p = new double[nElems];
    return p;
}

void CVector::liberarMemoria()
{
    if(vector != nullptr)
        delete[] vector;
    vector = nullptr;
}

void fnVisualizar(const CVector& v)
{
    for (size_t i = 0; i < v.longitud(); i++)
        std::cout << std::setw(7) << v.elemento(i);
    std::cout << "\n\n";
}



