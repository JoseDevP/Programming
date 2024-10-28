#if !defined (_CFICHALIBROVOLUMEN_HPP_)
#define _CFICHALIBROVOLUMEN_HPP_

#include <string>
#include "cficha.hpp"
#include "cficha_libro.hpp"

class CFichaLibroVolumen : public CFichaLibro
{
    private:
        int numeroVolumen;

    public:
        CFichaLibroVolumen(std::string ref = "", std::string tit = "", std::string au = "", std::string ed = "", int nVol = 0);
        ~CFichaLibroVolumen() override {}; 

        void asignarVolumen(int nVol);
        int obtenerVolumen() const;

        CFichaLibroVolumen* clonar() override { return new CFichaLibroVolumen(*this); }
};

#endif