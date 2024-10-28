#if !defined (_PERSONA_HPP_)
#define _PERSONA_HPP_

#include <ostream>
#include <cstring>

class CPersona
{
    friend std::ostream& operator<<(std::ostream& os, const CPersona& per);

    private:
        char nombre[30];
        char direccion[40];
        long telefono;
    public:
        CPersona(char* nom = 0, char* dir = 0, long tel = 0);
        void AsignarNombre(char* nom);
        char* ObtenerNombre(char* nom) const;
        void AsignarDireccion(char* dir);
        char* ObtenerDireccion(char* dir) const;
        void AsignarTelefono(long tel);
        long ObtenerTelefono() const;
        int tamanyo();
};

CPersona::CPersona(char* nom , char* dir, long tel)
{
    if(nom) strcpy(nombre,nom);
    if(dir) strcpy(direccion,dir);
    telefono = tel;
}

void CPersona::AsignarNombre(char* nom)
{
    if(nom) strcpy(nombre,nom);
}

char* CPersona::ObtenerNombre(char* nom) const
{
    return strcpy(nom,nombre);
}

void CPersona::AsignarDireccion(char* dir)
{
    if(dir) strcpy(direccion,dir);
}

char* CPersona::ObtenerDireccion(char* dir) const
{
    return strcpy(dir,direccion);
}

void CPersona::AsignarTelefono(long tel)
{
    telefono = tel;
}

long CPersona::ObtenerTelefono() const
{
    return telefono;
}

int CPersona::tamanyo()
{
    return sizeof(CPersona);
}

std::ostream& operator<<(std::ostream& os, const CPersona& reg)
{
    os << reg.nombre << std::endl << reg.direccion << std::endl << reg.telefono << std::endl;
    return os;
}

#endif