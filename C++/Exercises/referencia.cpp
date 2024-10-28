#include <iostream>
using namespace std;

void permutar(int&, int&);

int main()
{
    int a=10, b=20;
    permutar(a,b);
    cout << "a = " << a <<" b = " << b <<endl;
}

void permutar(int& rx, int& ry)
{
    int z=rx;
    rx=ry;
    ry=z;
}