/*Miembros que son punteros*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <ctype.h>

typedef struct persona
{
    unsigned long dni;
    char *nombre;
}tpersona;

tpersona *asigmem(void);
int asignarDni(tpersona *,long);
char *asignarNombre(tpersona *,char *);
void mayusculas(tpersona);

int main(void)
{
    tpersona per1 ={0,0};
    unsigned long DNI;
    char nombre[80];

    do
    {
        printf("DNI: "); scanf("%lu",&DNI); while(getchar() != '\n');
    } while (!asignarDni(&per1,DNI));

    printf("Nombre: "); fgets(nombre,sizeof(nombre),stdin);
    if(!asignarNombre(&per1,nombre)) return -1;
    mayusculas(per1);
    printf("%lu %s",per1.dni,per1.nombre);

    //cambair nombre
    printf("Nombre: "); fgets(nombre,sizeof(nombre),stdin);
    if(!asignarNombre(&per1,nombre)) return -1;
    mayusculas(per1);
    printf("%lu %s",per1.dni,per1.nombre);

    free(per1.nombre);
    return 0;


}

tpersona *asigmem(void)
{
    tpersona *p=(tpersona *)malloc(sizeof(tpersona));
    memset(p,0,sizeof(tpersona));
    return p;
}

int asignarDni(tpersona *p,long n)
{
    if(n > 0 ) p->dni=n;
    return n >0;
}

char *asignarNombre(tpersona *p,char *nom)
{
    if(p->nombre != NULL) free(p->nombre);
    if((p->nombre = (char*)malloc(strlen(nom)+1))==NULL)
        return 0;
    return strcpy(p->nombre,nom);
}

void mayusculas(tpersona per)
{
                    //hasta que sea NULL, caracter fin de linea \0
    for (int i = 0;per.nombre[i]; i++)
        per.nombre[i]=toupper(per.nombre[i]);
    
}
