#if !defined (_COMPLEJO_HPP_)
#define _COMPLEJO_HPP_

class CComplejo
{
    private:
        double real, imag;
    public:
        CComplejo(double r = 0,double i = 0) : real(r), imag(i) {}
        CComplejo operator-(); 
        CComplejo operator-(CComplejo x);
        void AsignarComplejo(double x, double i);
        void ObtenerComplejo(double& real, double& imag) const; 
};

#endif