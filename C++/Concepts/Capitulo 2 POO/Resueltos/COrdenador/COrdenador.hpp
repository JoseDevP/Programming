#pragma once

#include <iostream>

using namespace std;

class COrdenador
{
    private:
        string marca;
        string procesador;
        float peso;
        bool encendido;
        bool pantalla;

    public:
        COrdenador();
        COrdenador(string mar, string pro, float pes, bool enc, bool pan);

        string obtenerMarca();
        string obtenerProcesador();
        float obtenerPeso();
        bool obtenerEncendido();
        bool obtenerPantalla();

        void ponerMarca(string mar);
        void ponerPeso(float pes);
        void ponerProcesador(string pro);
        void ponerEnMarcha();
        void apagar();
        void desactivarPresentacionPantalla();
        void activarPresentacionPantalla();
        void Estado();
};