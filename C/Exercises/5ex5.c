/*
    Centro numerico->numero que separa lista de numeros enteros(comenzando en 1)
                    en dos grupos de números, cuyas sumas son iguales.
    El primer centro numerico es 6, searar la lista 1 a 8 en los grupos 
    (1,2,3,4,5) y (7,8) cuyas sumas son iguales a 15

    El segundo centro numerico es 35, searar la lista 1 a 49 en los grupos 
    (1 a 34) y (36 a 49) cuyas sumas son iguales a 595

    Escribe un progrma que calcules los centros numericos entre 1 y n.
*/
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int limit;
    printf("Introduce un numero:\n");
    while (true)
    {
        while (scanf("%d",&limit)!=1)
        {
            while(getchar()!='\n');
            printf("No has introducido un numero válido.\n");
        }
        if (limit>0)
        {
            break;
        }
                
    }
    int cantidadAnterior;
    int cantidadPosterior;


    for (int c = 1; c <= limit; c++) {
        int sum_before_c = (c - 1) * c / 2;
        
        int total_sum = limit * (limit + 1) / 2;
        
        int sum_after_c = total_sum - (c * (c + 1) / 2);

        if (sum_before_c == sum_after_c) {
            printf("Centro numérico: %d\n", c);
        }
    }
    
    
}