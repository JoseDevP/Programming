#if !defined (_CONCESIONARIO_HPP_)
#define _CONCESIONARIO_HPP_
#include <vector>
#include "cvehiculo.hpp"

class CConcesionario
{
    private:
        std::vector<CVehiculo*> vehiculos;
    public:
        CConcesionario() { vehiculos.reserve(100); }
        ~CConcesionario();

        CVehiculo* operator[](int n);

        bool anyadirVehiculo(CVehiculo*);
        bool eliminarVehiculo(std::string marca, std::string modelo);

        size_t cantidadDeVehiculos();

        void descripcion();
};

#endif