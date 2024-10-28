#if !define (_CPOLINOMIO_HPP_)
#define _CPOLINOMIO_HPP_

#include "ctermino.hpp"
#include "cterminoenx.hpp"
#include "cterminoeny.hpp"
#include "cterminoenxy.hpp"

#include <vector>
#include <string>
#include <istream>
#include <ostream>

class CPolinomio
{
    private:
        std::vector<CTermino*> terminos;
    public:
        CPolinomio() {terminos.reserve(100);}
        ~CPolinomio();
        CPolinomio(const CPolinomio& p);
        CPolinomio& operator=(const CPolinomio& p);
        CPolinomio(CPolinomio&& p);
        CPolinomio& operator=(CPolinomio&& p);

        CTermino* operator[](size_t i) const;

        friend CPolinomio operator+(const CPolinomio& p1, const CPolinomio& p2);
        friend CPolinomio operator-(const CPolinomio& p1, const CPolinomio& p2);
        friend CPolinomio operator*(const CPolinomio& p1, const CPolinomio& p2);
        friend CPolinomio operator/(const CPolinomio& p1, const CPolinomio& p2);

        friend std::istream& operator>>( std::istream& is, CPolinomio& p);
        friend std::ostream& operator<<( std::ostream& os, const CPolinomio& p);

        CTermino* CPolinomio::buscarTermino(std::string tipo, int expX, int expY);
        void ordenarPolinomio();

        void mostrarPolinomio() const;
        void liberarMemoria();
        size_t longitud() const; 
};

#endif