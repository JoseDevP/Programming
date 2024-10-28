#include <iostream>

class CB
{
    int b;
    public: 
        CB(int x = 10) { b = x; }
        virtual void f() {std::cout << "CB\n"; }
        int obtener() { return b; }
};

class CD : public CB
{
    int d;
    public:
        CD(int x = 20) { d = x; }
        void f() override { std::cout << "CD\n"; }
        int obtener() { return d; }
};

void fx(CB& r)
{
    CD& r1 = dynamic_cast<CD&>(r);
    //...
}

int main()
{
    //dynamic cast a punteros
    CB* pb1 = new CB;
    CB* pb2 = new CD;

    CD* pd1 = dynamic_cast<CD*>(pb1); // pb1 = 0 (no conversion)
    if(pd1)
    {
        pd1->f();
        std::cout << pd1->obtener() << std::endl;
    }

    CD* pd2 = dynamic_cast<CD*>(pb2);
    if(pd2)
    {
        pd2->f();
        std::cout << pd2->obtener() << std::endl;
    }

    delete pb1;
    delete pb2;

    //dynamic cast a referencias
    CB* pb3 = new CB;

    try
    {
        fx(*pb3);
    }
    catch(std::bad_cast)
    {
        std::cout << "conversión entre referencias no permitida\n";
    }
    delete pb3;
}