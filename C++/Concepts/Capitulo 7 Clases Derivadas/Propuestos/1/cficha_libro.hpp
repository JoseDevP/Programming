#if !defined (_CFICHALIBRO_HPP_)
#define _CFICHALIBRO_HPP_

#include <string>
#include "cficha.hpp"

class CFichaLibro : public CFicha
{
    private:
        std::string autor;
        std::string editorial;

    public:
        CFichaLibro(std::string ref = "", std::string tit = "", std::string au = "", std::string ed = "");
        ~CFichaLibro() override {}; 

        void asignarAutor(std::string au);
        std::string obtenerAutor() const;
        void asignarEditorial(std::string ed);
        std::string obtenerEditorial() const;

        CFichaLibro* clonar() override  { return new CFichaLibro(*this); }
};

#endif