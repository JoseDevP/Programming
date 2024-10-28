#if !defined (_CCuenta_Ahorro_HPP_)
#define _CCuenta_Ahorro_HPP_
#include "ccuenta.hpp"

class CCuentaAhorro : public CCuenta
{
    private:
        double cuotaMantenimiento;
    public:
        CCuentaAhorro(std::string nom = "sin nombre", std::string cuen = "0000", 
        double sal = 0.0, double tipo = 0.0, double mant = 0.0);
        CCuentaAhorro(const CCuentaAhorro& ca);
        CCuentaAhorro* clonar() override;
        CCuentaAhorro& operator=(const CCuentaAhorro& ca);
        ~CCuentaAhorro() {}

        bool asignarCuotaMantenimiento(double cuo);
        double obtenerCuotaMantenimiento() const;
        void comisiones();
        double intereses();
};

#endif