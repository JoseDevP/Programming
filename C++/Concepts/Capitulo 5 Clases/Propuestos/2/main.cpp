/*
    Programa para manupular ecuaciones algebraicas o polinomicas dependientes de una varible.
    Ej:
        2x^3 - x + 8.25 más 5x^5 - 2x^3 + 7x^2 - 3 igual a 5x^5 + 7x ^2 -x + 5.25

    Cada termino del polinomio tendra dos atributos privados:
        coeficiente
        exponenete
    Metodos:
        Construir un termino, inciado q 0 por omision
        Acceder al coeficente de un termino
        Acceder al exponente de un termino
        Obtener la cadena de caracteres equivalente a un termino con el formato siguiente:
            {+/-} 7x^4
        
    La clse CPolinomio tendra un atributo privado ( polinomio ) que sera una matriz que almacenara
    los terminos del polinomio, asi como los metodos necesarios para permitir al menos:

        Construir un polinomio incialmente con 0 ternminos

        Obtener el numero de terminos que tiene actualmente el polinomio

        Assignar un termino a un polinomio colocandolo en orden ascendente del exponente.
        Si el termino existe, se sumaran los coeficientes. Si el coeficiente es nulo, no
        se realizara ninguna operacion. Cada ve que se inserte un nuevo termino, se 
        incrementará automaticamente el tamaño del polinomio en 1. El metodo encargado
        de esta operación tendrá un parámetro de la clase CTermino.

        Sumar dos polinomios. El polinomio resultandte quedara tambien ordenado en orden 
        ascendenete del exponente.

        Obtener la cadena de caracarteres correpsondiente a la represantacion de un polinomio
        con el formato siguietne + 5x^5- 1x^1 + 5.25  
*/
#include <iostream>
#include "polinomio.hpp"

using namespace pol;

int main() {
    CTermino t1(3, 2);  
    CTermino t2(-5, 1); 
    CTermino t3(4, 0);   

    CPolinomio p1;
    p1.asignarTermino(t1);
    p1.asignarTermino(t2);
    p1.asignarTermino(t3);

    std::cout << "Polinomio p1: " << p1.representacionEnCadena() << std::endl;

    CTermino t4(2, 1);  
    CPolinomio p2;
    p2.asignarTermino(t4);

    std::cout << "Polinomio p2: " << p2.representacionEnCadena() << std::endl;

    CPolinomio p3 = p1 + p2;

    std::cout << "Polinomio p1 + p2: " << p3.representacionEnCadena() << std::endl;

    return 0;
}