/*Punteros como parametros*/

#include <stdio.h>
#include <stdlib.h>

struct fecha
{
    unsigned int dd;
    unsigned int mm;
    unsigned int aa;
    
};

void escribir(struct fecha *f);
void asig_mem(struct fecha **p);

int main(void)
{
    struct fecha *hoy=NULL;
    asig_mem(&hoy);
    if(hoy==NULL) return -1;

    printf("Introducir fecha (dd-mm-aa): ");
    scanf("%u-%u-%u",&hoy->dd, &hoy->mm, &hoy->aa);

    escribir(hoy);

    free(hoy);
    return 0;
}

void escribir(struct fecha *f)
{
    printf("Día %u del mes %u del año %u\n",f->dd,f->mm,f->aa);
}

void asig_mem(struct fecha **p)
{
    //*p es decir el puntero al que apunta
    *p=(struct fecha *)malloc(sizeof(struct fecha));
}