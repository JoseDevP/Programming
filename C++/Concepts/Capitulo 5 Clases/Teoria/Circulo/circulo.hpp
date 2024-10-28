#if !defined (_CIRCULO_HPP_)
#define _CIRCULO_HPP_


class Circulo
{
    private:
        class Punto
        {
            private:
                double x, y;
            public:
                Punto(double cx = 0, double cy = 0) {x = cx; y = cy;}
                double X() const {return x;}
                double Y() const {return y;}
        };
        Punto centro;
        double radio;
    protected:
        void msgEsNegativo();

    public:
        Circulo();
        Circulo(double cx, double cy, double r);
        double longCircunferencia();
        double areaCirculo();
        void asignarRadio(double r);
        void coordenadaCentro(double& x, double &y) const; 
};

#endif 
 