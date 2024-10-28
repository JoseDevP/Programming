#if !defined (_RACIONALES_HPP_)
#define _RACIONALES_HPP_
#include "complejo.hpp"
#include <ostream>
#include <istream>
#include <limits>

class CRacional
{
    private:
        long numerador;
        long denominador;
    protected:
        CRacional& Simplificar();
    public:
        //Constructor
        CRacional(long num = 1, long den = 1);
        //Constructor copia
        CRacional(const CRacional& c): numerador(c.numerador), denominador(c.denominador){}


        long Numerador() const { return numerador; }
        long Denominador() const { return denominador; }

        //Operador conversion
        operator double(); //Cracional a double
        operator CComplejo(); //Cracional a CComplejo

        //operadores asignacion
        CRacional& operator=(const CRacional& c);
        CRacional& operator+=(const CRacional& r);
        CRacional& operator-=(const CRacional& r);


        //operadores aritmeticos
        //UNARIOS
        CRacional operator+();

        //BINARIOS
        CRacional operator+(const CRacional& r); //->Dos Cracional
        friend const CRacional operator+(const CRacional& r1, const CRacional& r2);
        friend const CRacional operator+(const double d, const CRacional& r);

        //UNARIOS
        CRacional operator-();

        //BINARIOS
        CRacional operator-(const CRacional& r);
        friend const CRacional operator-(const CRacional& r1, const CRacional& r2);
        friend const CRacional operator-(const double d, const CRacional& r);


        //Relacion
        const bool operator==(const CRacional& r);
        friend const bool operator==(const CRacional& r1, const CRacional& r2);
        friend const bool operator==(const double d, const CRacional& r2);

        //Insercion
        friend std::ostream& operator<<(std::ostream& os, const CRacional& r);

        //Extraccion
        friend std::istream& operator>>(std::istream& is, CRacional& r);

        //Negacion
        bool operator!();

        //Incremento
        CRacional& operator++();
        CRacional operator++(int);

        void Visualizar(const CRacional& r);

};

#endif