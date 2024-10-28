#if !defined (__VECTOR_HPP__)
#define __VECTOR_HPP__

#include <iostream>
#include <stdexcept>
#include <iomanip>

template<typename T> class CVector
{
    private:
        T* vector;
        size_t nElementos;

    protected:
        T *asignarMem(int);
        void liberarMemoria();

    public:
        CVector(int ne = 10);
        CVector(T*, int);
        CVector(std::initializer_list<T> lista);

        CVector(const CVector<T>&); //copia
        CVector<T>& operator=(const CVector<T>&); // copiar vector en otro

        T& operator[](int i) const { return vector[i]; }; 

        CVector (CVector&&); //construcotr movimiento
        CVector<T>& operator=(CVector<T>&&); //asingacion rvalue

        CVector<T>& operator=(int valor); 

        T& elemento(size_t i) const;
        int longitud() const;

        ~CVector();
};

#endif


//Constructores

template<typename T> CVector<T>::CVector(int ne)
{
    if(ne < 1)
        throw std::invalid_argument("Nº de elementos no valido");

    nElementos = ne;
    vector = asignarMem(nElementos);
    std::fill(vector, vector + nElementos, 0);
}

template<typename T> CVector<T>::CVector(T* a, int ne)
{
    if(ne < 1)
        throw std::invalid_argument("Nº de elementos no valido");

    nElementos = ne;

    vector = asignarMem(nElementos);
    std::copy(a, a + nElementos, vector);
}

template<typename T> CVector<T>::CVector(std::initializer_list<T> lista)
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



template<typename T> CVector<T>::CVector(const CVector& v)
{
    nElementos = v.nElementos;

    vector = asignarMem(nElementos);
    std::copy(v.vector, v.vector + nElementos, vector);
}

template<typename T> CVector<T>::CVector (CVector&& v)
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
template<typename T> CVector<T>::~CVector()
{
    liberarMemoria();
}

//Otras
template<typename T> CVector<T>& CVector<T>::operator=(const CVector& v)
{
    if(this == &v) return *this;

    liberarMemoria();
    nElementos = v.nElementos;
    vector = asignarMem(nElementos);
    std::copy(v.vector, v.vector + nElementos, vector);
    return *this;
}

template<typename T> CVector<T>& CVector<T>::operator=(CVector&& v)
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

template<typename T> T& CVector<T>::elemento(size_t i) const
{
    if(i < 0 || i >= nElementos)
        throw std::out_of_range("Indice fuera de rango");
    return vector[i];
}

template<typename T> int CVector<T>::longitud() const
{
    return nElementos;
}

template<typename T> T* CVector<T>::asignarMem(int nElems)
{
    double* p = new T[nElems];
    return p;
}

template<typename T> void CVector<T>::liberarMemoria()
{
    if(vector != nullptr)
        delete[] vector;
    vector = nullptr;
}

template<typename T> CVector<T>& CVector<T>::operator=(int valor) {
    for (size_t i = 0; i < nElementos; ++i) {
        vector[i] = valor; // Asigna el valor a cada elemento
    }
    return *this; // Retorna la referencia al objeto actual
}



