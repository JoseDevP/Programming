#include <iostream>
#include <ostream>

class CTermino
{
    private:
        double coeficiente;
    public:
        CTermino(double k = 1) : coeficiente(k) {}
        double coef() {return coeficiente;}
        virtual void mostrar() = 0;
};

class CTerminoEnX : public virtual CTermino
{
    private:
        int exponenteX;
    public:
        CTerminoEnX(double k = 1, int e = 0) :
        CTermino(k), exponenteX(e) {}
        int expX() {return exponenteX;}
        void mostrar() override { std::cout << coef() << "x" << exponenteX; }
};

class CTerminoEnY : public virtual CTermino
{
    private:
        int exponenteDeY;
    public:
        CTerminoEnY(double k = 1, int e = 0) :
        CTermino(k), exponenteDeY(e) {}
        int expY() {return exponenteDeY;}
};

class CTerminoEnXY : public CTerminoEnX, public CTerminoEnY
{
    public:
        CTerminoEnXY(double k = 1, int ex = 0, int ey = 0) : 
        CTermino(k), CTerminoEnX(k, ex), CTerminoEnY(k, ey) {} 
        void mostrar() override {std::cout << coef() << "x^" << expX() << "y^" << expY(); }
};

std::ostream& operator<<(std::ostream& os, CTermino* t)
{
    t->mostrar();
    return os;
}

int main()
{
    CTerminoEnX* pcTerminoEnX = new CTerminoEnX(3, 2);
    std::cout << pcTerminoEnX << std::endl;

    CTerminoEnXY* pcTerminoEnXY = new CTerminoEnXY(2, 5, 3);
    std::cout << pcTerminoEnXY << std::endl;

    delete pcTerminoEnX;
    delete pcTerminoEnXY;
    std::cout << std::endl;
}


