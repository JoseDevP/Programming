#if !defined (__CONVOCATORIA_HPP__)
#define __CONVOCATORIA_HPP__

#include <string>
#include "../Fecha/fecha.hpp"

class CConvocatoria
{
    private:
        int convocatoria; //de 1 a 6
        std::string fecha; //mmaaaa
        float nota; 
    public:
        CConvocatoria(int c = 1, float n = 0);
        void asignarConvocatoria(int conv);
        int obtenerConvocatoria() const;
        void asignarFecha(int mes = 0, int anyo = 0);
        std::string obtenerFecha() const;
        void asignarNota(float n);
        float obtenerNota() const;
};

#endif