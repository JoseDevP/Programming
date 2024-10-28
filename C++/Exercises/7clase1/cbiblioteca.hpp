#if !defined (_CBIBLIOTECA_HPP_)
#define _CBIBLIOTECA_HPP_
#include <vector>
#include "cficha.hpp"

class CBiblioteca
{
    private:
        std::vector<CFicha*> fichas;
    public:
        CBiblioteca() { fichas.reserve(100); }
        ~CBiblioteca();
        CBiblioteca(const CBiblioteca& b);

        CBiblioteca& operator=(const CBiblioteca& b);
        CFicha* operator[](size_t i) const;

        void anyadirFicha(CFicha* f);
        int buscarFicha(std::string referencia, int i);
        bool eliminarFicha(std::string referencia);
        size_t longitud() const;
};

#endif