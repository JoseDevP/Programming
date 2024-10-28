#if !defined (_CFICHA_HPP_)
#define _CFICHA_HPP_

#include <string>

class CFicha
{
    protected:
        std::string referencia; 
        std::string titulo; 

    public:
        CFicha(std::string ref = "", std::string tit = "");
        virtual ~CFicha() {}; 

        void asignarReferencia(std::string ref);
        std::string obtenerReferencia() const;
        void asignarTitulo(std::string tit);
        std::string obtenerTitulo() const;

        virtual CFicha* clonar() = 0;
};

#endif