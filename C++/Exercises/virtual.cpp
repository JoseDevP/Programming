#include <iostream>

class CB
{
    public:
        virtual void mVirtual1();
        void mNoVirtual();
};

void CB::mVirtual1()
{
    std::cout << "método virtual 1 en CB\n";
}

void CB::mNoVirtual()
{
    std::cout << "método no virtual en CB\n";
}

class CD1 : public CB
{
    public:
        void mVirtual1() override;
        virtual void mVirtual2();
        void mNoVirtual();
};

void CD1::mVirtual1()
{
    std::cout << "método virtual 1 en CD1\n";
}

void CD1::mVirtual2()
{
    std::cout << "método virtual 2 en CD1\n";
}

void CD1::mNoVirtual()
{
    std::cout << "método no virtual en CD1\n";
}

class CD2 : public CD1
{
    public:
        void mVirtual1() override;
        void mVirtual2() override;
        void mNoVirtual();
};

void CD2::mVirtual1()
{
    std::cout << "método virtual 1 en CD2\n";
}

void CD2::mVirtual2()
{
    std::cout << "método virtual 2 en CD2\n";
}

void CD2::mNoVirtual()
{
    std::cout << "método no virtual en CD2\n";
}

void fx(CB *p)
{
    p->mVirtual1();
    //...
}

int main()
{
    CB* p1CB = new CD1;
    CD1* p1CD1 = new CD2;
    CB* p2CB = new CD2;

    p1CB->mVirtual1();
    p1CB->mNoVirtual();
    p1CB->CB::mVirtual1();

    p1CD1->mVirtual2();
    p1CD1->mNoVirtual();
    p1CD1->CD1::mVirtual2();

    fx(p2CB);
    delete p1CB;
    delete p1CD1;
    delete p2CB;
}