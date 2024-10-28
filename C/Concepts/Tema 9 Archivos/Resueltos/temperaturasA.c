/*
    En un archivo disponemos de los resultados obtenidos despues de medir las temperaturas
    en un punto geografico durante un intervalo de tiempo. El archivo consta de una cabecera
    que se define de acuerdo a la siguiente estructura:

    struct cabecera
    {
        struct posicion
        {
            int grados,minutos;
            float segundos;
        }latitud,longitud;

        int total_muestras;
    };

    A continuación de la cabecera vienen especificadas todas las temperaturas.
    Cada una de ellas es un numero float.

    a)Escribir una funcion con la siguietne declaracion:
        struct temperaturas
        {
            int total_temp;
            float *temp;
        };

        struct temperaturas leer_temperatura(char *nombrefich);

    b) Escribri una funcion con la siguiente declaracion:
        float calcular_media(struct temperaturas temp);
    
    Esta funcion calcula la media del conjunto de temperaaturas especificado por el parametro
    temp. Recordamos que la media de un conjunto de muestras se defines:
           n
    nx=1/n*E  xi
          i=1

    c)Escribir una funcion con la siguiente declaracion 
        float calcular_varianza(struct temperaturas temp);
    
    Esta funcion calcula la varianza del conjunbto de temperaturas especificado por el 
    parametro temp. Recordamos que la varianza de un conjunto de muestras se define como:

     2      n
    o=  1/n*E  (xi-nx)^2
     x     i=1

    d)Escribir un programa que pida el nombre de un archivo con el formato anterior y que muestre 
    por pantalla, a partior de los datos almacenados en el, la media y la varianza de las
    temperaturas recogidas.

    Para probar el funcionamiento de este programa habrá que realizar otro que permita construir
    el archivo de acuerdo al formato especificado.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct cabecera
{
    struct posicion
    {
        int grados,minutos;
        float segundos;
    }latitud,longitud;
    
    int total_muestras;
};

struct temperaturas
{
    int total_temp;
    float *temp;
};

struct temperaturas leer_temperatura(char *nombrefich);
float calcular_media(struct temperaturas temp);
float calcular_varianza(struct temperaturas temp);

int main(void)
{
    char nombrefich[20];
    struct temperaturas temp;

    printf("Nombre del archivo: ");
    scanf("%s",nombrefich);

    temp=leer_temperatura(nombrefich);
    printf("Temperatura media = %g grados\n",calcular_media(temp));
    printf("Desviación = %g\n",calcular_varianza(temp));

    free(temp.temp);
}

struct temperaturas leer_temperatura(char *nombrefich)
{
    FILE *pf=NULL;
    struct cabecera cab;
    struct temperaturas temp;
    if((pf=fopen(nombrefich,"r"))==NULL)
    {
        perror("Error al abrir el archivo");
        exit(EXIT_FAILURE);
    }

    fread(&cab, sizeof(struct cabecera), 1, pf);

    temp.total_temp = cab.total_muestras;
    temp.temp = (float *)malloc(temp.total_temp *sizeof(float));
    if(temp.temp==NULL)
    {
        printf("Insuficiente memoria");
        exit(-1);       
    }

    fread(temp.temp, sizeof(float), temp.total_temp,pf);
    fclose(pf);

    return temp;
}

float calcular_media(struct temperaturas temp)
{
    float suma=0;

    for (int i = 0; i < temp.total_temp; i++)
        suma+=temp.temp[i];

    return suma/temp.total_temp;
    
}

float calcular_varianza(struct temperaturas temp)
{
    float suma=0, media=calcular_media(temp), aux;

    for (int i = 0; i < temp.total_temp; i++)
    {
        aux = temp.temp[i] -media;
        suma+=aux*aux;
    }
    return suma /temp.total_temp;
}