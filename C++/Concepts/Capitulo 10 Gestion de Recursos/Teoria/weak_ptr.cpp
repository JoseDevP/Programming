#include <iostream>
#include <memory>

class B;

class A
{
    public:
        std::shared_ptr<B> b;
        ~A() {std::cout << "~A()" << std::endl;}
};

class B
{
    public:
        std::weak_ptr<A> a;
        ~B() {std::cout << "~B()" << std::endl;}
};      

int main()
{
    //shared_ptr<A> pi(new A);
    auto pi = std::make_shared<A>();
    pi->b = std::make_shared<B>();
    pi->b->a = pi;
    std::cout << pi.use_count() << std::endl;
    std::cout << pi->b.use_count() << std::endl;
}