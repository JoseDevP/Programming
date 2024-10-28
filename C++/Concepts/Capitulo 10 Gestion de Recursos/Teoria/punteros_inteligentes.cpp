#include <iostream>
#include <memory>

struct fecha
{
    private:
        int dd, mm, aaaa;
    public:
        fecha(int d, int m, int a) : dd(d), mm(m), aaaa(a) {} 
        int GetDay() const { return dd; }
        int GetMonth() const { return mm; }
        int GetYear() const { return aaaa; }
};

void f1(fecha f)
{
    //Puntero puro
    fecha* p = new fecha(f);

    std::cout << (*p).GetDay() << std::endl;
    std::cout << p->GetYear() << std::endl;

    delete p;
}

void f2(fecha f)
{
    std::unique_ptr<fecha> p(new fecha(f));

    std::cout << (*p).GetDay() << std::endl;
    std::cout << p->GetYear() << std::endl;
}

int main()
{
    fecha cumple(1, 2, 2018);

    f1(cumple);
    f2(cumple);
}
