#include <iostream>
#include <string>
#include <memory>

class Persona
{
    private:
        std::string nombre;
    public:
        Persona( std::string n = "" ) : nombre(n) {}

        std::unique_ptr<Persona> crearPersona(std::string nom) 
        {
            std::unique_ptr<Persona> p(new Persona(nom));
            return p;
        }

        std::string GetNombre() { return nombre; }

        void SetNombre(std::string s) { nombre = s; }
};


void leerNombrePersona(std::unique_ptr<Persona>& p)
{
    std::cout << p->GetNombre() << std::endl;
}

int main()
{
    Persona p;
    std::unique_ptr<Persona> nuevaPersona = p.crearPersona("Jose");
    leerNombrePersona(nuevaPersona);
}