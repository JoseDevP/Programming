#if !defined (_CBANCO_HPP_)
#define _CBANCO_HPP_

#include <vector>
#include <string>
#include "CCuenta/ccuenta.hpp"
#include "CCuenta/ccuentaAhorro.hpp"
#include "CCuenta/ccuentaCorriente.hpp"
#include "CCuenta/ccuentaCorrientePlus.hpp"

class CBanco
{
    private:
        std::vector<CCuenta*> cuentas;
    
    public:
        CBanco();
        CBanco(const CBanco& x);
        CBanco& operator=(const CBanco& x);
        ~CBanco();
        CCuenta* operator[](size_t i) const;
        void anyadir(CCuenta* obj);
        bool eliminar(std::string cuenta);
        int buscar(std::string str, int pos = 0) const;
        size_t longitud() const;
        static std::string tipoCuenta(CCuenta* cuenta);
};

#endif