#if !defined (_PRODUCTO_HPP_)
#define _PRODUCTO_HPP_

#include <cstring> // Para usar strncpy y strlen

class Producto
{
private:
    char referencia[30]; 
    char nombre[30];
    long cantidad;
    double precio;

public:
    Producto(const char ref[] = "", const char nom[] = "", long can = -1, double pre = -1);

    void SetReferencia(const char ref[]);
    const char* GetReferencia() const;

    void SetNombre(const char nom[]);
    const char* GetNombre() const;

    void SetCantidad(long can);
    long GetCantidad() const;

    void SetPrecio(double pre);
    double GetPrecio() const;
};

// Implementación de métodos

Producto::Producto(const char ref[], const char nom[], long can, double pre) 
{
    SetReferencia(ref);
    SetNombre(nom);
    SetCantidad(can);
    SetPrecio(pre);
}

void Producto::SetReferencia(const char ref[])
{
    strncpy(referencia, ref, sizeof(referencia) - 1);
    referencia[sizeof(referencia) - 1] = '\0'; // Asegurar terminación nula
}

const char* Producto::GetReferencia() const
{
    return referencia;
}

void Producto::SetNombre(const char nom[])
{
    strncpy(nombre, nom, sizeof(nombre) - 1);
    nombre[sizeof(nombre) - 1] = '\0'; // Asegurar terminación nula
}

const char* Producto::GetNombre() const
{
    return nombre;
}

void Producto::SetCantidad(long can)
{
    cantidad = can;
}

long Producto::GetCantidad() const
{
    return cantidad;
}

void Producto::SetPrecio(double pre)
{
    precio = pre;
}

double Producto::GetPrecio() const
{
    return precio;
}

#endif // _PRODUCTO_HPP_
