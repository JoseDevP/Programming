#if !defined (_CCOCHE_HPP_)
#define _CCOCHE_HPP_
#include "cvehiculo.hpp"
#include <string>

class CCoche : public CVehiculo
{
    private:
        int numPuertas;
    public:
        CCoche(std::string mar = "ninguna", std::string mod = "ninguno", long a = 1998, int nPuer = 4) 
        : CVehiculo(mar,mod,a), numPuertas(nPuer) { asignarNumeroPuertas(nPuer); }
        void asignarNumeroPuertas(int n);
        int obtenerNumeroPuertas() const;
        void describirVehiculo() const override;
        CCoche* clonar() override {return new CCoche(*this); }
        bool esVehiculoGrande() const override;

};

#endif