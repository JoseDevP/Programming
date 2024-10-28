/*Puntero a estructura y a union*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct fecha
{
    unsigned int dd;
    unsigned int mm;
    unsigned int aa;
    int felicidad;
    union  
    {
        char describe_felicidad[40];
        int cantidad_tristeza;
    }estado;
    
};

void escribir(struct fecha *f);

int main(void)
{
    struct fecha *hoy;

    hoy=(struct fecha *)malloc(sizeof(struct fecha));
    if(hoy==NULL) return -1;

    printf("Introducir fecha (dd-mm-aa): ");
    scanf("%u-%u-%u",&hoy->dd, &hoy->mm, &hoy->aa);

    printf("¿Ha sido un día feliz? (0-1)");
    scanf("%d",&hoy->felicidad);

    while(getchar() != '\n');

    if(hoy->felicidad==1)
    {
        printf("Describe como te sientes: ");
        fgets(hoy->estado.describe_felicidad,sizeof(hoy->estado.describe_felicidad),stdin);
    }
    else
    {
        printf("Del uno al 10 que tan mal te sientes: ");
        scanf("%d",&hoy->estado.cantidad_tristeza);
    }
    escribir(hoy);

    free(hoy);
    return 0;
}

void escribir(struct fecha *f)
{
    printf("Día %u del mes %u del año %u\n",f->dd,f->mm,f->aa);
    if(f->felicidad==1)
        printf("%s\n",f->estado.describe_felicidad);
    else
        printf("La cantidad de tristeza es: %d\n",f->estado.cantidad_tristeza);
}