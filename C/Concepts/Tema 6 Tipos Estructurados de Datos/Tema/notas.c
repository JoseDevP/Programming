/*notas.c*/

#include <stdio.h>
#define N_ALUMNOS 100

int main(void)
{
    float notas[N_ALUMNOS];
    int i=0;
    int nalumnos=0;
    float suma=0;

    do
    {
        printf("Número de alumnos: ");
        scanf("%d",&nalumnos);
    } while (nalumnos < 1 || nalumnos >N_ALUMNOS);
    
    for (int i = 0; i < nalumnos; i++)
    {
        printf("Alumno número %3d, nota media: ",i+1);
        scanf("%f",&notas[i]);
    }

    for (int i = 0; i < nalumnos; i++)
    {
        suma+=notas[i];
        printf("\n\nNota media del curso: %5.2f\n",suma/nalumnos);
    }
    
    

}