#include <iostream>

using namespace std;

struct punto
{
    int x;
    int y;

    int& cx()
    {
        return x;
    }
    int& cy()
    {
        return y;
    }
};


int main(void)
{
    punto origen;
    origen.cx() = 60;
    origen.cy() = 60;
    cout << "x = " << origen.cx() << endl;
    cout << "y = " << origen.cy() << endl;

}