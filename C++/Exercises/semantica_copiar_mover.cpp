#include <iostream>
#include <string>

class C
{
    private:
        std::string s;
    public:
        C() = default;
        C(std::string x) : s(x)
        {
            std::cout << "Constructor para " << x << std::endl;
        }

        ~C()
        {
            std::cout << "Destructor para " << (s.empty() ? "\"\"" : s) << std::endl;
        }

        //contructor copia y sobrecarga operador asignacion para mover
        C(const C& x) : s(x.s)
        {
            std::cout << "Constructor copia para " << x.s << std::endl;
        }

        C& operator=(const C& x)
        {
            s = x.s;
            std::cout << "Operador = copia " << x.s << std::endl;
            return *this;
        }

        //cosntructor mover y sobrecarga operador asignacion para mover

        C(C&& x) : s(std::move(x.s)) // s(static_cast<string&&>(x.s))
        {
            std::cout << "Constructor mover para " << (x.s.empty() ? "\"\"" : x.s) << std::endl;
        }

        C& operator=(C&& x)
        {
            s = std::move(x.s);
            std::cout << "Operador = movimiento " << x.s << std::endl;
            return *this;
        }

        const std::string& GetS() const
        {
            return s;
        }

};

C crearObjC(const std::string& s)
{
    C obj(s);
    return obj;
}

int main()
{
    C obj{"s1"};
    obj = crearObjC("s2");
    obj = C("s3");
}