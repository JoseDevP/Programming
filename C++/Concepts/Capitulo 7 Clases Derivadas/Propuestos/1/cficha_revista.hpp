#if !defined (_CFICHAREVISTA_HPP_)
#define _CFICHAREVISTA_HPP_

#include <string>
#include "cficha.hpp"

class CFichaRevista : public CFicha
{
    private:
        int numeroRevista;
        long añoPublicacion;
    
    public:
        CFichaRevista(std::string ref = "", std::string tit = "", int nRev = 0, long aPub = 1990);
        ~CFichaRevista() override {}; 

        void asignarNumero(int nRev);
        int obtenerNumero() const;
        void asignarAño(long aPub);
        long obtenerAño() const;

        CFichaRevista* clonar() override { return new CFichaRevista(*this); }
};  

#endif