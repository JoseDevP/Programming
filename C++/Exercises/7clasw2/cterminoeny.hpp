#if !defined (_CTERMINOENY_HPP_)
#define _CTERMINOENY_HPP_

#include "ctermino.hpp"
#include <iostream>

class CTerminoEnY : public virtual CTermino
{
    private:
        int exponenteEnY;
    public:
        CTerminoEnY(double coef = 1, double exp = 0) : CTermino(coef), exponenteEnY(exp) {asignarExponenteEnY(exp);}
        ~CTerminoEnY() override {};
        int obtenerExponenteEnY() const {return exponenteEnY;}
        void asignarExponenteEnY(int exp);
        CTerminoEnY* clonar() override { return new CTerminoEnY(*this); };
        void mostrar() override { std::cout << obtenerCoeficiente() << "y" << exponenteEnY;};
        CTerminoEnY operator+(const CTerminoEnY& t);
};

#endif