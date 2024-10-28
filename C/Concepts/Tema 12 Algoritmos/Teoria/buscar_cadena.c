#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*algoritmo Boyer y Moore para buscar una cadena en un texto*/

int buscarCadena(char *texto, char *cadena)
{
    int j, longTex=strlen(texto);

    //Construir tabla delta
    int delta[256];
    int i, longCad=strlen(cadena);

    //Iniciar tabla delta
    for (int i = 0; i < 256; i++)
        delta[i] = longCad;

    //Asignar valores a la tabla
    for (int i = 0; i < longCad; i++)
        delta[cadena[i]] = longCad - i -1;
    
    //Algoritmo Boyer y Moore
    i = longCad -1; //i es el indice dentro del texto
    while (i < longTex)
    {
      j = longCad - 1; // índice dentro de la cadena a buscar
      // Mientras haya coincidencia de caracteres
      while (cadena[j] == texto[i])
      {
        if ( j > 0 )
        {
          // Siguiente posición a la izquierda
          j--; i--;
        }
        else
        {
          // Se llegó al principio de la cadena, luego se encontró.
          return i;
        }
      }
      // Los caracteres no coinciden. Mover i lo que indique el
      // valor "delta" del carácter del texto que no coincide
      i += delta[texto[i]];
    }
    return -1;
}

int main()
{
    char texto[] = "Este es un ejemplo de texto donde buscaremos una cadena.";
    char cadena[] = "buscaremos";

    int posicion = buscarCadena(texto, cadena);

    if (posicion >= 0)
    {
        printf("La cadena '%s' se encontró en la posición %d del texto.\n", cadena, posicion);
    }
    else
    {
        printf("La cadena '%s' no se encontró en el texto.\n", cadena);
    }

    return 0;
}