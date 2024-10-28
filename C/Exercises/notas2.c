/*notas.c*/

#include <stdio.h>

int main(void)
{
    int i=0;
    int nalumnos=0;

    do
    {
        printf("Número de alumnos: ");
        scanf("%d",&nalumnos);
    } while (nalumnos < 1);

    float notas[nalumnos];
    
    for (int i = 0; i < nalumnos; i++)
    {
        printf("Alumno número %3d, nota media: ",i+1);
        scanf("%f",&notas[i]);
    }

    float suma=0;
    
    for (int i = 0; i < nalumnos; i++)
    {
        suma+=notas[i];
        printf("\n\nNota media del curso: %5.2f\n",suma/nalumnos);
    }
    
    

}