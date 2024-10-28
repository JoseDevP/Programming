#if !defined (_CCuenta_HPP_)
#define _CCuenta_HPP_
#include <string>

class CCuenta
{
    private:
        std::string nombre;
        std::string cuenta;
        double saldo;
        double tipoDeInteres;
    public:
        CCuenta(std::string nom = "sin nombre", std::string cuen = "0000", double sal = 0.0, double tipo = 0.0);
        CCuenta(const CCuenta& c);
        virtual CCuenta* clonar() = 0;
        CCuenta& operator=(const CCuenta& c);
        ~CCuenta() {}

        bool asignarNombre(std::string nom);
        std::string obtenerNombre() const;
        bool asignarCuenta(std::string cuen);
        std::string obtenerCuenta() const;
        double obtenerSaldo() const;
        virtual void comisiones() = 0;
        virtual double intereses() = 0;
        bool ingreso(double cantidad);
        void reintegro(double cantidad);
        bool asignarTipoDeInteres(double tipo);
        double obtenerTipoDeInteres() const;

};

#endif