#include <iostream>
#include <chrono>
#include <ctime>
#include <thread>

long calcular(unsigned n)
{
    int r = 1;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    return r * n;
}

int main(void)
{
    //steady clock
    std::chrono::time_point<std::chrono::steady_clock> inicio, fin; //no disminuye incuso si cambias tiempo del ordenador

    inicio = std::chrono::steady_clock::now();
    std::cout <<  "calcular..." << calcular(50) << '\n';
    fin = std::chrono::steady_clock::now();

    //Duracion en coma floatnate, no necesita cast
    std::chrono::duration<double, std::milli> ms_transcurridos_d = fin - inicio;
    std::cout << "El calculo duró " << ms_transcurridos_d.count() << "ms\n";

    //Duracion como valor entero: requiere cast
    auto ms_transcurridos_i = std::chrono::duration_cast<std::chrono::milliseconds>(fin - inicio);
    std::cout << "El calculo duró " << ms_transcurridos_i.count() << "ms\n";

    //Duracion como valor entero: conversion de enettero a entero
    std::chrono::duration<long, std::micro> us_transcurridos_i = ms_transcurridos_i;
    std::cout << "El calculo duró " << us_transcurridos_i.count() << "us\n";




    //system clock
    std::chrono::system_clock::time_point epoca, ahora;

    ahora = std::chrono::system_clock::now(); 
    //1 enero 1970
    std::time_t epoca_t = std::chrono::system_clock::to_time_t(epoca);
    std::cout << "Epoca: " << std::ctime(&epoca_t);

    std::cout << "desde epoca han transcurrido " << std::chrono::duration_cast<std::chrono::hours>(ahora.time_since_epoch()).count() << " horas\n";

    std::time_t ahora_c = std::chrono::system_clock::to_time_t(ahora - std::chrono::hours(48));
    std::cout << "hace 48 horas la fecha-hora era: " << std::ctime(&ahora_c) << '\n';



}