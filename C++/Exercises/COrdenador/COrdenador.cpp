#include <iostream>
#include "COrdenador.hpp"

using namespace std;


COrdenador::COrdenador()
{
    marca="Ninguna";
    procesador="Ninguno";
    peso=0;
    encendido=false;
    pantalla=false;
}

COrdenador::COrdenador(string mar, string pro, float pes, bool enc, bool pan)
{
    ponerMarca(mar);
    ponerProcesador(pro);
    ponerPeso(pes);
    (enc == true) ? ponerEnMarcha() : apagar();
    (pan == true) ? activarPresentacionPantalla() : desactivarPresentacionPantalla();
}

string COrdenador::obtenerMarca()
{
    return marca;
}

string COrdenador::obtenerProcesador()
{
    return procesador;
}

float COrdenador::obtenerPeso()
{
    return peso;
}

void COrdenador::ponerPeso(float p)
{
    if(p < 0)
    {
        peso=0;
        cout << "Error: Peso no valido" << endl;
        return;
    }
    peso = p;
}

void COrdenador::ponerMarca(string mar)
{
    if(mar.length() < 1)
    {
        cout << "Error: Marca no valida" << endl;
        return;
    }
    marca = mar;
}

void COrdenador::ponerProcesador(string pro)
{
    if(pro.length() < 1)
    {
        cout << "Error: Marca no valida" << endl;
        return;
    }
    procesador = pro;
}

void COrdenador::ponerEnMarcha()
{
    encendido=true;
}

void COrdenador::apagar()
{
    encendido=false;
}

bool COrdenador::obtenerEncendido()
{
    return encendido;
}

void COrdenador::desactivarPresentacionPantalla()
{
    pantalla=false;
}

void COrdenador::activarPresentacionPantalla()
{
    pantalla=true;
}

bool COrdenador::obtenerPantalla()
{
    return pantalla;
}

void COrdenador::Estado()
{
    cout << "Ordenador:" << endl;
    cout << "Marca: " << obtenerMarca() << endl;
    cout << "Peso: " << obtenerPeso() << endl;
    cout << "Procesador: " << obtenerProcesador() << endl;
    cout << "Encendido: " << obtenerEncendido() << endl;
    cout << "Pantalla: " << obtenerPantalla() << endl;
    cout << endl;
}