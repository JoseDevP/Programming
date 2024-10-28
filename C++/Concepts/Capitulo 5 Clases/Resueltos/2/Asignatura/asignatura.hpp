#if !defined (_ASIGNATURA_HPP_)
#define _ASIGNATURA_HPP_

#include <string>
#include <vector>
#include "../Fecha/fecha.hpp"
#include "../Convocatoria/convocatoria.hpp"

using namespace cfe;

class CAsignatura
{
    private:
        int ID;
        std::string nombre;
        CFecha fecha;
        std::vector<CConvocatoria> convocatorias;

    public:
        CAsignatura(int id = 999999, std::string nom = "");
        void asignarID(int id);
        int obtenerID() const;
        void asignarNombre(std::string nom);
        std::string obtenerNombre() const;
        void asignarFecha(CFecha& f);
        const CFecha& obtenerFecha() const;
        CConvocatoria& obtenerConvocatoria(unsigned int i);
        void anyadirConvocatoria(CConvocatoria& c);
        size_t convocatoriasConsumidas();
};

#endif