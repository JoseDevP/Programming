// vectorT.h - Especialización parcial de la plantilla Vector
#if !defined( _VECTORT_H_ )
#define _VECTORT_H_
#include "vectorEspec.h" // especialización explícita

template<typename T> class Vector<T*> : private Vector<void*>
{
  public:
    Vector(int ne = 10) : Vector<void*>(ne) {}

    Vector(const Vector& v) : Vector<void*>(v)
    {
      for (int i = 0; i < v.longitud(); i++)
        (*this)[i] = new T(*v[i]);
    }

    Vector<T*>& operator=(const Vector& v)
    {
      if (this == &v) return *this;
      Vector<void*>::operator=(v);
      for (int i = 0; i < v.longitud(); i++)
        (*this)[i] = new T(*v[i]);
      return *this; // permitir asignaciones encadenadas
    }

    T*& operator[](int i) const
    {
      return reinterpret_cast<T*&>(Vector<void*>::operator[](i));
    }

    int longitud() const
    {
      return Vector<void*>::longitud();
    }

    T* operator=(T* x) // iniciar un vector
    {
      Vector<void*>::operator=(reinterpret_cast<void*>(x));
      return x;
    }
};

#endif // _VECTORT_H_
