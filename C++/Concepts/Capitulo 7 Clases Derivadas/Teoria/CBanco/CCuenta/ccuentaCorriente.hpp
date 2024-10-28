#if !defined (_CCUENTACORRIENTE_HPP_)   
#define _CCUENTACORRIENTE_HPP_
#include "ccuenta.hpp"

class CCuentaCorriente : public CCuenta
{
    private:
        int transacciones;
        double importePorTrans;
        int transExcentas;
    public:
        CCuentaCorriente(std::string nom = "sin nombre", std::string cuen = "0000", double sal = 0.0,
        double tipo = 0.0, double imp = 0.0, int transEx = 0);

        
        void decrementarTransacciones();
        bool asignarImportePorTrans(double imp);
        double obtenerImportePorTrans() const;
        bool asignarTransExentas(int transEx);
        int obtenerTransExentas() const;
        void ingreso(double cantidad);
        void reintegro(double cantidad);
        void comisiones() override;
        double intereses() override;
};

#endif