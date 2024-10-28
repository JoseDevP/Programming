/* complejo.h */
#pragma once

typedef struct 
{
    float r; //parte real de un numero complejo
    float i; //parte imaginaria de un numero complejo
}tcomplejo;

tcomplejo leerComplejo();
void mostrarComplejo(tcomplejo c);
tcomplejo multiplicarComplejos(tcomplejo a, tcomplejo b);
tcomplejo sumarComplejos(tcomplejo a, tcomplejo b);
