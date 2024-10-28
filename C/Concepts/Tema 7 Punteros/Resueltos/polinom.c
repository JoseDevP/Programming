/*
    Se quiere escribir un programa para manipular polinomips.
    typedef struct
    {
        int grado;
        float *coef;
    }tpolinomio;
    grado es u valor mayor que 0 
    coef puntero que referencia una matriz cuyos elemtentos contienen los coeficientes del 
    polinomio.
    numero de elementos de esta matriz es numero de coeficientes del polinomio y depende del 
    grado de este

    Ej:
    x**5 +5x**3-7x**2+4;

    como el grado del polinomio es 5, la mtriz de los coeficientes tendrá seis elementos 
    cuyos valortes serna 1,0,5,-7,0 y 4.
    
    a)  funcion leerPol que lea a través del teclado un polinomio y lo almacene en una 
        estructura del tipo tpolinomio. 
        Esta funcion devolverá el polinomio leido.
        ej:
        Coeficientes de mayor a menor grado: 1 0 5 -7 0 4
        prototipo de la funcion:
        tpolinomio leerPol(int grado);

    b) funcion Visualizar Polinomio que visualice en pantalla un polinomio.
        Ej:
        +1x^5+5x^3-7x^2+4
        void visualizarPol(tpolinomio pol);
    
    c)Escribir una función SumarPols devuelva suma de dos polinomios
        Ej:
        tpolinomio sumarPols(tpolinomio polA, tpolinomio polB);
    
*/

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct
    {
        int grado;
        float *coef;
    }tpolinomio;

tpolinomio leerPol(int grado);
void visualizarPol(tpolinomio pol);
tpolinomio sumarPols(tpolinomio polA, tpolinomio polB);

int main(void)
{
    tpolinomio polA,polB,polC;
    int grado=0,correcto=0;

    do
    {
        printf("Dime el grado del Polinomio A: ");
        correcto=scanf("%d",&grado);
        while(getchar() != '\n');
    } while (!correcto || grado<0);
    
    polA=leerPol(grado);
    if(polA.coef==NULL)
        return 0;
    visualizarPol(polA);

    do
    {
        printf("Dime el grado del Polinomio A: ");
        correcto=scanf("%d",&grado);
        while(getchar() != '\n');
    } while (!correcto || grado<0);

    polB=leerPol(grado);
    if(polB.coef==NULL)
        return 0;
    visualizarPol(polB);

    printf("La suma de polinomios es: \n");
    polC=sumarPols(polA,polB);
    visualizarPol(polC);


    free(polA.coef);
    free(polB.coef);
    free(polC.coef);
}

tpolinomio leerPol(int grado)
{
    tpolinomio pol={grado,NULL};
    if((pol.coef=(float *)malloc((pol.grado+1)*sizeof(float))) != NULL)
    {
        printf("Coeficientes de mayor a menor grado: ");
        for (int i = pol.grado; i >=0; i--)
        {
            scanf("%f",&pol.coef[i]);
        }
        while(getchar() != '\n');
        return pol;
        
    }
}

void visualizarPol(tpolinomio pol)
{
    int i=0;
    for (i = pol.grado; i >=1; i--)
    {
        if(pol.coef[i]!=0)
        {
            printf("+%gx^%d ",pol.coef[i],i);
        }
    }
    printf("+%g ",pol.coef[i]);

    printf("\n\n");
}

tpolinomio sumarPols(tpolinomio polA, tpolinomio polB)
{
    int i=0;
    tpolinomio polresu={0,NULL}, polAux={0,NULL};
    if(polA.grado<polB.grado)
    {
        polAux=polA;
        polA=polB;
        polB=polAux;
    }
    polresu.grado=polA.grado;
    
    polresu.coef=(float *)malloc((polresu.grado+1)*sizeof(float));
    if(polresu.coef!=NULL)
    {
        memset(polresu.coef,0,(polresu.grado+1)*sizeof(float));

        for (i = 0; i < polB.grado ; i++)
        {
            polresu.coef[i]=polB.coef[i]+polA.coef[i];
        }

        for ( ; i <= polA.grado; i++)
        {
            polresu.coef[i]=polA.coef[i];
        }       
    }   
    return polresu;
}