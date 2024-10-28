#include <iostream>
#include "ctermino.hpp"

void CTermino::asignarCoeficiente(double coef)
{
    if(coef < 1 )
    {
        coeficiente = 1;
    }
    coeficiente = coef;
}
