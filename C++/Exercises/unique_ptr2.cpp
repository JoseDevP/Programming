#include <iostream>
#include <memory>

class A
{
    std::unique_ptr<int> i;
    public:
        A(int n = 0) : i(new int(n)) {}
        int dato() { return i ? *i : 0; }
};

int main()
{
    A a(3), b;
    //b = a;  error: funcion miembro operator= eliminado
    b = std::move(a);
    std::cout << a.dato() << std::endl;
    std::cout << b.dato() << std::endl;
}