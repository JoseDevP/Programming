#if !defined (_FORMATO_HPP_)
#define _FORMATO_HPP_

#include <sstream>
#include <string>

class CNumEntero
{
    friend std::ostream&  operator<<(std::ostream& os, const CNumEntero& ob);

    private:
        long valor;
        static char punto;
    
    public:
    CNumEntero(long lo = 0) { valor = lo; }
    operator long() { return valor; }
};

char CNumEntero::punto = '.';

std::ostream& operator<<(std::ostream& os, const CNumEntero& ob)
{
    std::stringstream ss1;

    ss1.setf(os.flags() & std::ios::basefield, std::ios::basefield);
    ss1.setf(os.flags() & std::ios::showpos, std::ios::showpos);
    ss1.setf(os.flags() & std::ios::showbase, std::ios::showbase);

    ss1 << ob.valor <<std::ends;
    
    std::stringstream ss2;

    char car = ss1.get(); //primer caracter de ss1
    if(car == '+' || car == 'X')
    {
        ss2 << car;
        car = ss1.get();
    }
    if(car == '0')
    {
        ss2 << car;
        car = ss1.get();
    }
    if(car == 'x' || car == 'X')
    {
        ss2 << car;
        car = ss1.get();
    }

    ss2 << car;
    car = ss1.get();

    int distancia = (os.flags() & std::ios::oct) ? 4 : 3;

    int pos_act = ss1.tellg();
    ss1.seekg(0, std::ios::end);
    int ult_pos = ss1.tellg();

    int quedan = ult_pos - pos_act;

    ss1.seekg(pos_act, std::ios::beg);
    do
    {
        if(car && !(quedan-- % distancia))
            ss2 << CNumEntero::punto;
        ss2 << car;
        car = ss1.get();
    } while (!ss1.eof());
    
    os << ss2.str();

    return os;
}

#endif