#include <stdio.h>
#include <string.h>

typedef struct ficha
{
    char nombre[40];
    char direccion[40];
    long telefono;
    
} tficha;

struct ubicacion
{
    struct ficha fi;
};

struct ubicacion ubi;



int ficha=1;

int main(void)
{
    tficha var1;
    char nombre[40]="Javier";
    puts("Nombre: ");
    fgets(var1.nombre,sizeof(var1.nombre),stdin);
    printf("\n");
    printf("%s\n",var1.nombre);
    printf("%s\n",nombre);
    printf("%d\n",ficha);

    strcpy(ubi.fi.nombre, "fsadf");
    printf("%s\n",ubi.fi.nombre);

    struct ficha fi={"Jose"};
    struct ficha fi2={.telefono=64513216848};
    



}