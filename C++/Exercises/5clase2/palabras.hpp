#if !defined (_PALABRAS_HPP_)
#define _PALABRAS_HPP_
#include <map>
#include <string>
#include <iterator>
#include <cstring>

class CPalabra
{   
    private:
        std::map<std::string, int> palabras;
    public: 
        void insertarPalabra(const std::string&); 
        int buscarPalabra(const std::string&) const;
        void visualizarTablaFrecuencias() const;
};

#endif