#include <iostream>

using namespace std;

struct complejo
{
    double real, imag;
};

complejo operator+(complejo x, complejo y)
{
    complejo temp;
    temp.real = x.real + y.real; //parte real
    temp.imag = x.imag + y.imag;
    return temp;
}

void visualizar(const complejo& z)
{
    cout << z.real << " " << z.imag << endl;
}

int main()
{
    complejo a = {1.0, 2.0},b = {1.5, -1.5}, c;
    c = a + b;
    visualizar(c);

}