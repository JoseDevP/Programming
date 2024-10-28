#include "cvector.hpp"

class CIniciar
{
    private:
        double val;
    public:
        CIniciar(double x = 0);
        void operator()(CVector& v);
        void valor(double x = 0);
};