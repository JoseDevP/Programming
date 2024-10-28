#if !defined (_CCUENTACORRIENTEPLUS_HPP_)
#define _CCUENTACORRIENTEPLUS_HPP_
#include "ccuentaCorriente.hpp"

class CCuentaCorrientePlus : public CCuentaCorriente
{
    public:
        CCuentaCorrientePlus(std::string nom = "sin nombre", std::string cuen = "0000", double sal = 0.0,
        double tipo = 0.0, double imp = 0.0, int transEx = 0);
        CCuentaCorrientePlus* clonar() override;
        double intereses() override;
};

#endif