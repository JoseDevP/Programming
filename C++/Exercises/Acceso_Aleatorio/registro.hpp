#if !defined(_REGISTRO_HPP_)
#define _REGISTRO_HPP_

#include <iostream>
#include <cstring>
#include <iomanip>

class CRegistro
{
    friend std::ostream& operator<<(std::ostream&, const CRegistro&);
    
    private:
        char referencia[30];
        float precio;
     
    public:
        CRegistro();
        void AsignarRegistro(char *, float);
        char* ObtenerReferencia(char *) const;
        float ObtenerPrecio() const;
};

CRegistro::CRegistro()
{
    std::fill(referencia, referencia + 30, 0);
    precio = 0.0F;
}

void CRegistro::AsignarRegistro(char * ref, float pre)
{
    strcpy(referencia, ref);
    precio = pre;
}

char* CRegistro::ObtenerReferencia(char * ref) const
{
    return strcpy(ref, referencia);
}

float CRegistro::ObtenerPrecio() const
{
    return precio;
}

std::ostream& operator<<(std::ostream& os, const CRegistro& reg)
{
    os << std::setw(32) << std::left
       << std::setfill( '.' )
       << reg.referencia
       << std::setw(10) << std::right
       << std::fixed << std::setprecision(2)
       << reg.precio << std::endl;
    return os;
}

#endif 