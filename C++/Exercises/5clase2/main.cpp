/*
    Suponiendo un texto escrito en minusculas y sin signos de puntauacion ( una palabra estará separada de otra
    por un espacio en blanco) realizar un programa que lea texto de la entrada estandar (del teclado) y de como
    resultado la frecuencia con que aparece cada palabra leida del texto.

    El resultado se almacenará en una matriz en la que cada elemento será un objeto con dos atributos: uno de 
    tipo string para almacenar la palabra y otro de tipo int para almacenar la fecuencia de la misma ( se 
    acosneja usar la plantilla map)

    A su vez la matriz, que ira creciendo a medida que se vayan añadiendo palabrasa, sera un atributo
    de la clase CPalabras. La interfaz de esta clase incluirá al menos los metodos:

        InsertarPalabra
            insertará en la matriz la palabra pasada como argumetno e incrementará su contador de frecuencias en
            una unidad.

        BuscarPalabra
            buscar en la matriz la palabra pasada  como argumento y devolverá el valor de su contador de frecuencias,
            o 0 si la palabra no existe.

        VisualizarTablaFrecuencias
            mostrara una tabla palabra-contador que inclya las palabras diferentes que aparecen en el texto 
            y la frecuencia con la que aparecen

*/

#include <iostream>
#include <string>
#include "palabras.hpp"

int main(void)
{
    std::string palabra;
    CPalabra palabras;

    while (std::cin >> palabra)
    {
        palabras.insertarPalabra(palabra);
    }

    palabras.visualizarTablaFrecuencias();
    
    
}