#include <iostream>
#include <vector>
#include <string>
#include <memory>

class Mensaje
{
    private:
        std::string mensaje;
    public:
        Mensaje(std::string s = "") : mensaje(s) {}
        std::string obtenerMensaje() const { return mensaje; }
};

class Almacen
{
    private:
        std::vector<std::unique_ptr<Mensaje>> v;
    public:
        void anyadir(std::string mensaje)
        {
            //v.push_back(std::unique_ptr<Mensaje>(new Mensaje(mensaje)));
            v.emplace_back(new Mensaje(mensaje));
        }

        Mensaje operator[](int i)
        {
            return *v.at(i);
        }

        int size() { return v.size(); }
};

int main()
{
    Almacen almacen;

    almacen.anyadir("Un mensaje");
    almacen.anyadir("Otro mensaje");

    Almacen almacen2 = std::move(almacen);

    std::cout << "almacen:\n";
    for (int i = 0; i < almacen.size(); i++)
        std::cout << almacen[i].obtenerMensaje() << std::endl;
    
    std::cout << "almacen2:\n";
    for (int i = 0; i < almacen2.size(); i++)
        std::cout << almacen2[i].obtenerMensaje() << std::endl;
}