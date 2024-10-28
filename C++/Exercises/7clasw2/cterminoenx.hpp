#if !defined (_CTERMINOENX_HPP_)
#define _CTERMINOENX_HPP_

#include "ctermino.hpp"
#include <iostream>

class CTerminoEnX : public virtual CTermino
{
    private:
        int exponenteEnX;
    public:
        CTerminoEnX(double coef = 1, double exp = 0) : CTermino(coef), exponenteEnX(exp) {asignarExponenteEnX(exp);}
        ~CTerminoEnX() override {};
        int obtenerExponenteEnX() const {return exponenteEnX;}
        void asignarExponenteEnX(int exp);
        CTerminoEnX* clonar() override { return new CTerminoEnX(*this); };
        void mostrar() override { std::cout << obtenerCoeficiente() << "x" << exponenteEnX;};
        CTerminoEnX operator+(const CTerminoEnX& t);
};

#endif