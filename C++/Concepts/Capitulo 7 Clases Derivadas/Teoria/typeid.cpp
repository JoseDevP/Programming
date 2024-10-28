#include <iostream>
#include <typeinfo>

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
        int patata() {return 1;}
};

int main()
{
    CB* p_CB = new CB;
    CB* p_CD = new CD;

    const std::type_info& inf = typeid(p_CB);
    std::cout << inf.name() << std::endl;

    const std::type_info& inf2 = typeid(*p_CB);
    std::cout << inf2.name() << std::endl;

    const std::type_info& inf3 = typeid(p_CD);
    std::cout << inf3.name() << std::endl;

    const std::type_info& inf4 = typeid(*p_CD);
    std::cout << inf4.name() << std::endl;

    delete p_CB;
    delete p_CD;

}