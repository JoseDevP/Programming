#pragma once
#include <iostream>
using namespace std;

class CCuenta
{
    //Atributos
    private: 
        string nombre;
        string cuenta;
        double saldo;
        double tipoDeInteres;

    //Metodos
    public:       
        CCuenta();

        CCuenta(string nom, string cue, double sal, double tipo);
        
        void asignarNombre(string nom);

        string obtenerNombre();

        void asignarCuenta(string cue);

        string obtenerCuenta();

        double obtenerSaldo();

        void ingreso(double cantidad);

        void reintegro(double cantidad);

        void asignarTipoDeInteres(double tipo);

        double obtenerTipoDeInteres();
};
