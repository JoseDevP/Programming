#if !defined (__FECHA_HPP_)
#define __FECHA_HPP_

namespace fjc
{
class CFecha
{
    private:
        int dia, mes, anyo;
        const static CFecha fechaPredeterminada;
    protected:
        bool anyoBisiesto(int aaaa) const;
        bool fechaValida(int dd = fechaPredeterminada.dia,
                         int mm = fechaPredeterminada.mes,
                         int aaaa = fechaPredeterminada.anyo) const;
    public:
        static void asignarFechaPredeterminada(int = 0, int = 0, int =0);
        CFecha(int dd = 1, int mm = 1, int aaaa = 2001);

        bool asignarFecha();
        bool asignarFecha(int dd);
        bool asignarFecha(int dd, int mm);
        bool asignarFecha(int dd, int mm, int aaaa);
        void obtenerFecha(int& dd, int&mm, int&aaaa);
        const int& obtenerDia() const;
        const int& obtenerMes() const;
        const int& obtenerAnyo() const;

        ~CFecha();
}; 

void obtenerFechaActual(int& dd, int& mm, int& aaaa);
}
#endif