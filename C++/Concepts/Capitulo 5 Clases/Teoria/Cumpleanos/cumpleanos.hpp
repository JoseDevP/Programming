#if !defined (__CCUMPLEAÑOS_HPP__)
#define __CCUMPLEAÑOS_HPP__

#include "../Fecha/fecha.hpp"


class CCumpleaños
{
    private:
        char* nombre;
        fjc::CFecha fecha_nacimiento; 
        long telefono;
    protected:
        char* asignarCadena(const char*) const;
    public:
        CCumpleaños( const char* = 0, int = 1, int= 1, int = 2001, long = 598632145);
        ~CCumpleaños() { delete[] nombre; };
        void asignarNombre(const char*);
        const char* obtenerNombre() const { return nombre; }
        fjc::CFecha& fechaNacimiento() { return fecha_nacimiento; }
        fjc::CFecha fechaNacimiento() const { return fecha_nacimiento; }
        void asignarTelefono(long);
        long obtenerTelefono() const { return telefono; }
};

#endif