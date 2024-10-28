#if !defined (_COMPLEJOS_HPP)
#define _COMPLEJOS_HPP
#include <ostream>
#include <istream>
#include <cmath>
#include <limits>

class CComplejo
{
    private:
        double real;
        double imag;
    protected:
        static void error(const char* mensaje);
    public:
        CComplejo(double re = 0, double im = 0) : real(re), imag(im) {}
        friend CComplejo po_bi(const double mod, double alfa);

        //Operaciones aritmeticas
        friend CComplejo operator+(const CComplejo& c1, const CComplejo& c2); 
        friend CComplejo operator-(const CComplejo& c1, const CComplejo& c2); 
        friend CComplejo operator*(const CComplejo& c1, const CComplejo& c2); 
        friend CComplejo operator/(const CComplejo& c1, const CComplejo& c2); 

        //Comparacion de complejos
        friend bool operator==(const CComplejo& c1, const CComplejo& c2);
        friend bool operator!=(const CComplejo& c1, const CComplejo& c2);
        friend bool operator<(const CComplejo& c1, const CComplejo& c2);
        friend bool operator>(const CComplejo& c1, const CComplejo& c2);
        friend bool operator<=(const CComplejo& c1, const CComplejo& c2);
        friend bool operator>=(const CComplejo& c1, const CComplejo& c2);

        //Operaciones Trigonometricas
        friend CComplejo cos(const CComplejo&);
        friend CComplejo sin(const CComplejo&);
        friend CComplejo tan(const CComplejo&);
        friend CComplejo cosh(const CComplejo&);
        friend CComplejo sinh(const CComplejo&);
        friend CComplejo tanh(const CComplejo&);

        //Operaciones logaritmo, exponencial, potencia y raiz cuadrada
        friend CComplejo exp(const CComplejo&);
        friend CComplejo log(const CComplejo&);
        friend CComplejo pow(const CComplejo& c, const CComplejo& e);
        friend CComplejo sqrt(const CComplejo&);

        //Entrada y Salida
        friend std::istream& operator>>(std::istream& os, CComplejo& c);
        friend std::ostream& operator<<(std::ostream& os, CComplejo& c);

        //Obtencion de valores
        double ParteReal() const { return real; }
        double ParteImag() const { return imag; }
        double mod() const { return sqrt(real *real + imag*imag); }
        double arg() const { return atan2(imag, real); }
        double norm() const { return real*real + imag*imag; }

        //Operaciones varias
        CComplejo conjugado() { return CComplejo(real, -imag);}
        CComplejo negativo() { return CComplejo(-real, imag);}

        //Menos unario. Complejos opuestos
        CComplejo operator-() { return CComplejo(-real, -imag);}

        //Asignacion de complejos
        CComplejo operator+=(CComplejo& c) {return *this = *this + c;}
        CComplejo operator-=(CComplejo& c) {return *this = *this - c;}
        CComplejo operator*=(CComplejo& c) {return *this = *this * c;}
        CComplejo operator/=(CComplejo& c) {return *this = *this / c;}
};

#endif