#if !defined (_CMOTO_HPP_)
#define _CMOTO_HPP_
#include "cvehiculo.hpp"
#include <string>

class CMoto : public CVehiculo
{
    private:
        std::string tipoMotor;
    public: 
        CMoto(std::string mar = "ninguna", std::string mod = "ninguno", long a = 1998, std::string tmot = "gasolina") 
        : CVehiculo(mar,mod,a), tipoMotor(tmot) { asignarTipoMotor(tmot); }
        void asignarTipoMotor(std::string tmot);
        std::string obtenerTipoMotor() const;
        void describirVehiculo() const override;
        CMoto* clonar() override {return new CMoto(*this); }
        bool esVehiculoGrande() const override;

};

#endif