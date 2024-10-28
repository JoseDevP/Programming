#include <iostream>
using namespace std;

struct Complejo
{
    double real;
    double imaginario;
    Complejo sumar(Complejo c);                                                                                                                                                                                                                                         
};

Complejo Complejo::sumar(Complejo c)
{
    Complejo r = {this->real + c.real, this->imaginario + c.imaginario};
    return r;
}

int main()
{
    Complejo a ={1,2}, b{0.5, -2.8}, r;
    r=a.sumar(b);
     cout << "Resultado de la suma: " << r.real <<r.imaginario << "j" << endl;
}       