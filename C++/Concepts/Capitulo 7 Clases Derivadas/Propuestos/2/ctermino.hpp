#if !defined (_CTERMINO_HPP_)
#define _CTERMINO_HPP_

class CTermino
{
    private:
        double coeficiente;
    public:
        CTermino(double k = 1) : coeficiente(k) {asignarCoeficiente(k);}
        virtual ~CTermino() {};
        float obtenerCoeficiente() const {return coeficiente;}
        void asignarCoeficiente(double coef);
        virtual CTermino* clonar() = 0;
        virtual void mostrar() = 0;
};

#endif