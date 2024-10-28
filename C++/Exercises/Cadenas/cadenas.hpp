#if !defined (_CADENAS_HPP_)
#define _CADENAS_HPP_
#include <istream>
#include <ostream>
#include <cstring>
#include <algorithm>

class CCadena
{
    private:
        char* pmCad;
        size_t nLong;
    protected:
        static void error(const char* mensaje);
    public:
        CCadena(const char* cad = 0);
        CCadena(const CCadena& cad);
        CCadena(char, int);
        ~CCadena();

        //Concatenar cadenas de caracteres
        friend CCadena operator+(const CCadena& cad1, const CCadena& cad2);

        //Comparacion de cadenas
        friend bool operator==(const CCadena& cad1, const CCadena& cad2);
        friend bool operator!=(const CCadena& cad1, const CCadena& cad2);
        friend bool operator<(const CCadena& cad1, const CCadena& cad2);
        friend bool operator>(const CCadena& cad1, const CCadena& cad2);
        
        //Operaciones de entrada / salida
        friend std::istream& operator>>( std::istream&, CCadena& cad);
        friend std::ostream& operator<<( std::ostream&, const CCadena& cad);

        //Asignacion
        CCadena& operator=(const CCadena& cad);
        CCadena& operator=(const char*);
        CCadena& operator+=(const CCadena& cad);
        char& operator[](unsigned int);
        size_t ObtenerLong() const { return nLong; } 
};

#endif