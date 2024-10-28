#if !defined (_CCAMION_HPP_)
#define _CCAMION_HPP_
#include "cvehiculo.hpp"
#include <string>

class CCamion : public CVehiculo
{
    private:
        double capacidadCarga;
    public:
        CCamion(std::string mar = "ninguna", std::string mod = "ninguno", long a = 1998, double cCarga = 0) 
        : CVehiculo(mar,mod,a), capacidadCarga(cCarga) { asignarCapacidadCarga(cCarga); }
        void asignarCapacidadCarga(double cCarga);
        double obtenerCapacidadCarga() const;
        void describirVehiculo() const override;
        bool esVehiculoGrande() const override;
        CCamion* clonar() override {return new CCamion(*this); }
};

#endif