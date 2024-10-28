#if !defined (_CVEHICULO_HPP_)
#define _CVEHICULO_HPP_
#include <string>

class CVehiculo
{
    private:
        std::string marca;
        std::string modelo;
        long año;
    public:
        CVehiculo(std::string mar = "ninguna", std::string mod = "ninguno", long a = 1998);
        void asignarMarca(std::string mar);
        std::string obtenerMarca() const;
        void asignarModelo(std::string mod);
        std::string obtenerModelo() const;
        void asignarAño(long a);
        long obtenerAño() const;
        virtual void describirVehiculo() const = 0; 
        virtual bool esVehiculoGrande() const = 0;
        virtual CVehiculo* clonar() = 0;
};

#endif