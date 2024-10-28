#include <iostream>
#include <cstring>

class CFecha
{
    private:
        int dd, mm ,aaaa;

    protected:
        bool esBisiesto(int anio)
        {
            return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
        }

        bool esFechaValida(int d, int m, int a)
        {
            if (m < 1 || m > 12 || d < 1 || a < 1) return false;

            int diasPorMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

            if (m == 2 && esBisiesto(a))
                diasPorMes[m] = 29;

            return d <= diasPorMes[m];
        }

    public:
        CFecha(int d = 1, int m = 1 , int a = 1998) : dd(d), mm(m), aaaa(a)
        {
            asignarFecha(d, m ,a);
        }

        void asignarFecha(int d, int m, int a)
        {
            if (esFechaValida(d, m, a))
            {
                dd = d;
                mm = m;
                aaaa = a;
            }
            else
            {
                std::cerr << "Fecha invalida. Se asigna la fecha por defecto (1/1/1998)." << std::endl;
                dd = 1;
                mm = 1;
                aaaa = 1998;
            }
        }

        void obtenerFecha(int& d, int& m, int& a)
        {
            d = dd;
            m = mm;
            a = aaaa;
        }

        int obtenerDia() const
        {
            return dd;
        }

        int obtenerMes() const
        {
            return mm;
        }

        int obtenerAño() const
        {
            return aaaa;
        }

        friend bool operator<(const CFecha& f1, const CFecha& f2)
        {
            if (f1.aaaa != f2.aaaa)
            return f1.aaaa < f2.aaaa;
            if (f1.mm != f2.mm)
                return f1.mm < f2.mm;
            return f1.dd < f2.dd;
        }

        friend bool operator>(const CFecha& f1, const CFecha& f2)
        {
            if (f1.aaaa != f2.aaaa)
            return f1.aaaa > f2.aaaa;
            if (f1.mm != f2.mm)
                return f1.mm > f2.mm;
            return f1.dd > f2.dd;
        }
};

//generica
template<typename T> T menor(T x, T y)
{
    return (x < y) ? x : y;
}

//especializacion parcial
template<typename T> T* menor(T* x, T* y)
{
    return (*x < *y) ? x : y;
}

//especializacion explicita
template<> char* menor<char>(char* a, char* b)
{
    return (strcmp(a,b) < 0) ? a : b;
}

template<> char* menor<char*>(char* a, char* b)
{
    return (strcmp(a,b) < 0) ? a : b;
}

int main()
{
    //generica
    int m = 10, n = 27;
    CFecha f1(20), f2(15);

    int r = menor(m ,n);
    CFecha f = menor(f1, f2);

    std::cout << "Generica:" << std::endl;
    std::cout << r << std::endl;
    std::cout << f.obtenerDia() << std::endl;
    std::cout << "\n\n";

    //esp parcial
    CFecha* f3 = new CFecha(35);
    CFecha* f4 = new CFecha(10);

    CFecha* f5 = menor(f3,f4);

    std::cout << "Especializada total:" << std::endl;
    std::cout << f5->obtenerDia() << std::endl;
    std::cout << "\n\n";

    delete f3;
    delete f4;

    //esp explciita
    char* cad1 = "hola", *cad2 = "adios", *cad3;
    cad3 = menor<char*>(cad1, cad2);

    std::cout << "Especializada parcial:" << std::endl;
    std::cout << cad3 << std::endl;
    std::cout << "\n\n";
}