#if !defined (__CMATRIZ_HPP__)
#define __CMATRIZ_HPP__

class CMatriz
{
    private:
        double* matriz;
        int nDims;
        int* dimsMatriz;

        void construir(int n, int* dim);
    
    public:
        CMatriz(int d1 = 10, int d2 = 0, int d3 = 0);
        ~CMatriz();
        int totalElementos() const;
        int desplazamiento(int* subind) const;
        void asignarDato(int d, int i1, int i2 = 0, int i3 =0);
        double obtenerDato(int i1 = 0, int i2 = 0, int i3 = 0 ) const;
};


#endif