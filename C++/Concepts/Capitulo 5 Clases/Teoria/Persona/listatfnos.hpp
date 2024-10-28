#if !defined (__LISTATFNOS_HPP__)
#define __LISTATFNOS_HPP__
#include <vector>
#include "persona.hpp"

class CListaTfnos
{
    private:
        std::vector<CPersona> listaTelefonos;
    
    public:
        CListaTfnos();
        CPersona registro(unsigned int i);
        void anyadir(CPersona obj);
        bool eliminar(long tel);
        int buscar(std::string str, int pos);
        size_t longitud();
};

#endif