#if !defined (__PERSONA_HPP__)
#define __PERSONA_HPP__
#include <string>

class CPersona
{
    private:
        std::string nombre;
        std::string direccion;
        long telefono;
    
    public:
        CPersona(std::string nom = "", std::string dir = "", long tel = 0);
        void asignarNombre(const std::string& nom);
        std::string obtenerNombre() const;
        void asignarDireccion(const std::string& dir);
        std::string obtenerDireccion() const;
        void asignarTelefono(long tel);
        long obtenerTelefono() const;
};

#endif