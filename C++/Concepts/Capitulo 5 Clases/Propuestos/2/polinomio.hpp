#if !defined (_POLINOMIO_HPP_)
#define _POLINOMIO_HPP_
#include <string>
#include <vector>

namespace pol
{
    class CTermino
    {
        private:
            double coeficiente;
            int exponente;
        public:
            CTermino(double coef = 0, int exp = 0);
            void asignarCoeficiente(double coef);
            double obtenerCoeficiente() const;
            void asignarExponente(int exp);
            int obtenerExponente() const;
            std::string representacionEnCadena() const; // formato {+/-} 7x^4

    };

    class CPolinomio
    {
        private:
            std::vector<CTermino> polinomio;
        public:
            CPolinomio();
            int numeroDeTerminos() const;
            void asignarTermino(const CTermino& t);
            CPolinomio operator+(const CPolinomio& pol) const;
            std::string representacionEnCadena() const;
    };
}

#endif
