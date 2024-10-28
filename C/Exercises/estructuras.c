/*Operaciiones con estructuras*/

#include <stdio.h>
#include <string.h>
#include <locale.h>

char* readString(char*,int);

typedef struct 
{
    int dia,mes,anyo;
}tfecha;

typedef struct 
{
    char nombre[40];
    char direccion[40];
    long telefono;
    tfecha fecha_nacimiento;
}tficha;

int main(void)
{
    setlocale(LC_ALL,""); //configuracion regional predeternmianda
    tficha persona,otra_persona;

    printf("Nombre:           ");
    readString(persona.nombre,sizeof(persona.nombre));

    printf("Dirección:           ");
    readString(persona.direccion,sizeof(persona.direccion));

    printf("Teléfono:           ");
    scanf("%ld",&persona.telefono);

    printf("Fecha de nacimiento:\n");
    printf("Día:                 ");
    scanf("%ld",&persona.fecha_nacimiento.dia);

    printf("Mes:                 ");
    scanf("%ld",&persona.fecha_nacimiento.mes);

    printf("Año:                 ");
    scanf("%ld",&persona.fecha_nacimiento.anyo);

    //copiar estructura en otra
    otra_persona=persona;

    printf("\n\n");
    printf("Nombre: %s\n",otra_persona.nombre);
    printf("Dirección: %s\n",otra_persona.direccion);
    printf("Teléfono: %ld\n",otra_persona.telefono);
    printf("Fecha de nacimiento: %ld // %ld // %ld\n",otra_persona.fecha_nacimiento.dia,otra_persona.fecha_nacimiento.mes,otra_persona.fecha_nacimiento.anyo);
    

}

char* readString(char* str,int n)
{
    char* fin, *c=0;
    fin=fgets(str,n,stdin);
    if (c=strchr(str,'\n'))
        *c=0;
    else if(!feof(stdin))
        while (getchar()!='\n');
    return fin;
}
    
