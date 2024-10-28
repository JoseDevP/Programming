#if !defined (_CTERMINOENXY_HPP_)
#define _CTERMINOENXY_HPP_

#include "cterminoenx.hpp"
#include "cterminoeny.hpp"

class CTerminoEnXY : public CTerminoEnX, public CTerminoEnY
{
    public:
        CTerminoEnXY(double coef = 1, int expX = 0, int expY = 0) :
        CTermino(coef), CTerminoEnX(coef, expX), CTerminoEnY(coef, expY) {}
        ~CTerminoEnXY() override {};
        CTerminoEnXY* clonar() override { return new CTerminoEnXY(*this); };
        void mostrar() override { std::cout << obtenerCoeficiente() << "x" << obtenerExponenteEnX() << "y" << obtenerExponenteEnY();};
        CTerminoEnXY operator+(const CTerminoEnXY& t);
};

#endif