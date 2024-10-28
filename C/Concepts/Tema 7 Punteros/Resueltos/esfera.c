/*
    Solido irregular S, el cual puede encerrarse en un cubo C. 
    Puede demostrarse que la probabilidad de que un punto al azar dentro de C este tambien
    dentro de S es:

        Volumen_sólido / Volumen_líquido

    Partiendo de un cubo C definidio por x <= 1, y <=1, z <=1
    y de la esfera definida por x^2 + y^2 + z^2 <= 1 se cumple que 1/8 de la esfera asi 
    definida esta dentro del cubo de lado 1.

    Por lo que si generamos un punto al azar dentro del cubo, la probabilidad de que este se
    encuentre también dentro del sector esférico es:

        Volumen_sólido = Volumen_esfera / 8
        Volumen_cubo =1
        p = Volumen_sólido / Volumen_cubo = Volumen_esfera / 8 

    para saber el volumen de la esfera, bastará con calcualr esa probavilidad.
    Para ello, la función main invocará a un función denominada DentroEsfera que generará
    TOTAL puntos (x,y,z) y contará cuantos de esos puntos estand entro del octavo de 
    una esfera.
    Una vez hecho este calculo la probabilidad P y el volumen de la esfera vendran
    dados por las escpresiones:
        p =dentro/TOTAL;
        volumen = 8.0 *P;

    El prototipo de la funcion DentroEsfera:
        int DentroEsfera(const int);
    Esta función tiene un parámetro que se corresponde con el numero total de puntos a generar.
    Para generar los valores x,y,z (valores entre 0 y 1)la funcion DentroEsfera invocará a la 
    funcion rnd.

*/

#include <stdio.h>
#include <time.h>

double rnd(long *);
int DentroEsfera(const int);

int main(void)
{
    const int TOTAL = 1000; //ensayos a realizar
    double Volumen_esfera;
    int dentro; //numero puntos dentro de la esfera

    printf("Ensayos a realizar: %d\n",TOTAL);
    dentro=DentroEsfera(TOTAL);

    Volumen_esfera= 8.0 *dentro /TOTAL;
    printf("\nVolumen estimado = %g\n",Volumen_esfera); 
}

int DentroEsfera(const int total)
{
    long random=time(NULL);
    int i, dentro=0;
    double x,y,z;

    for (i = 1; i <= total; i++)
    {
        printf("Realizando cálculos... %d\r ",i);
        x=rnd(&random); y=rnd(&random); z=rnd(&random);

        if(x*x + y*y +z*z <=1)
        {
            dentro+=1;
        }
        
    }
    return dentro;
}


double rnd(long *prandom)
{
    *prandom=(25173 * *prandom +13849) % 65536;
    return ((double)*prandom / 65535);
}