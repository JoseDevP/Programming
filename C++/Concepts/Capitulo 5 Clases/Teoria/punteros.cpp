#include <iostream>
#include <iomanip>

class CNotas
{
    private:
        float nota;

    public:
        CNotas( float n = 0) : nota(n) {};
        void AsignarNota(float n);
        float ObtenerNota() const;
};

void CNotas::AsignarNota(float n) { nota = n; }

float CNotas::ObtenerNota() const
{
    float CNotas::*pdmNota = &CNotas::nota;
    return this->*pdmNota;
}

void Visualizar(CNotas*);

typedef void (CNotas::*pfnm) (float); // puntero a metodo

int main()
{
    CNotas alumno;
    CNotas* palumno = new CNotas;
    float nota;

    pfnm pfnAsignarNota = &CNotas::AsignarNota;

    std::cout << "Nota del alumno:";
    std::cin >> nota;
    (alumno.*pfnAsignarNota)(nota);

    std::cout << "Nota del alumno:";
    std::cin >> nota;
    (palumno->*pfnAsignarNota)(nota);

    std::cout << std::endl;
    std::cout << "alumno 1, nota: ";
    Visualizar(&alumno);
    std::cout << "alumno 2, nota: ";
    Visualizar(palumno);

    delete palumno;
}

void Visualizar(CNotas* palumno)
{
    std::cout << std::fixed << std::setprecision(2);
    std::cout << std::setw(12) << palumno->ObtenerNota() << std::endl;
}

