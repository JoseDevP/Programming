#if !defined (_ALUMNO_HPP_)
#define _ALUMNO_HPP_

#include <string>
#include <vector>
#include "../Asignatura/asignatura.hpp"

class CAlumno
{
    private:
        long DNI;
        std::string nombre;
        std::string direccion;
        std::vector<CAsignatura*> asignatura;
    
    public:
        CAlumno (long dni = 0, std::string nom = "", std::string dir = "");// constructor
        CAlumno (const CAlumno&); // constructor copia
        ~CAlumno();
        CAlumno operator=(const CAlumno&);

        void asignarDNI(long dni);
        long obtenerDNI() const;
        void asignarNombre(std::string&);
        std::string obtenerNombre() const;
        void asignarDireccion(std::string&);
        std::string obtenerDireccion() const;
        CAsignatura* obtenerAsignatura(unsigned int i);
        bool estaEnActa(int id, int& pos);
        void anyadirAsignatura(CAsignatura*);
        size_t numeroAsignaturas() const;
};

#endif