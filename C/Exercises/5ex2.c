/* Evaluaci�n de una serie
 *
 * Cap5 - ejercicio3.c
 *b ∑ a=0  1/(x+ay)
 */

#include <stdio.h>        
#include <stdbool.h> 



int main(void)
{
    float b,x,y;
    while ((printf("Introduce b: "), scanf("%f",&b)!=1)){while (getchar()!='\n');}
    while ((printf("Introduce x: "), scanf("%f",&x)!=1)){while (getchar()!='\n');}
    while ((printf("Introduce y: "), scanf("%f",&y)!=1)){while (getchar()!='\n');}

    float resultado_suma=0;
    for (int a = 0; a < b+1; a++)
    {
        resultado_suma+=1/(x+a*y);
    }
    printf("El resultado es: %f",resultado_suma);
    
}