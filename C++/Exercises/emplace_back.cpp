#include <iostream>
#include <vector>
#include <string>

class Mensaje
{
    private:
        std::string mensaje;
    public:
        Mensaje(std::string s = "") : mensaje(std::move(s)) 
        {
            std::cout << "Construyendo el objeto\n";
        }

        Mensaje(Mensaje&& obj) : mensaje(std::move(obj.mensaje)) 
        {
            std::cout << "Moviendo el objeto\n";
        }

        Mensaje& operator=(const Mensaje& obj) = default;
};

int main()
{
    std::vector<Mensaje> v;
    std::vector<Mensaje> v2;

    std::cout << "push_back:\n";
    v.push_back(Mensaje("Mensaje 1"));
    v.push_back(Mensaje("Mensaje 2"));

    std::cout << "emplace_back:\n";
    v.emplace_back("Mensaje 1");
    v.emplace_back("Mensaje 2");
}

