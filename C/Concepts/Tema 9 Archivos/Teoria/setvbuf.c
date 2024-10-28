/*Control del buffer asociado a un archivo*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIBUFFER 2048

int cuenta_lineas(FILE *pf, int lecturas);
FILE *abrir(char *);

char buf1[BUFSIZ], buf2[MIBUFFER];

int main(int argc, char *argv[])
{
    time_t t_inicial;
    FILE *pf;
    int c, lecturas;

    if(argc !=2)
    {
        printf("Sintaxis: nombre_programa nombre_archivo\n");
        exit(1);
    }

    printf("¿Cuantas veces consecutivas desea leer el archivo %s?", argv[1]);
    scanf("%d", &lecturas);
    if(lecturas<1) lecturas=1;

    pf=abrir(argv[1]);
    setvbuf(pf,buf1,_IOFBF,BUFSIZ);
    t_inicial = clock();
    c=cuenta_lineas(pf,lecturas);
    printf("Tiempo %5.1f\tTamaño del Buffer: %4d\n",((float)clock()-t_inicial) / CLOCKS_PER_SEC, 0);

    printf("\nSe han procesado %d lineas\n",c);

    return 0;
}

int cuenta_lineas(FILE *pf, int lecturas)
{
    #define N 81
    char linea_buf[N];
    int c=0;

    for (int i = 0; i < lecturas; i++)
    {
        while (!ferror(pf) && !feof(pf))
        {
            fgets(linea_buf,N,pf);
            c++;
            (c%2) ? printf("\\\r"):printf("/\r");
        }   
        rewind(pf);
    }
    if(ferror(pf))
    {
        perror("Error en la lectura");
        fclose(pf);
        exit(3);
    }
    putchar('\n');
    fclose(pf);
    return c;
}

FILE *abrir(char *archivo)
{
    FILE *pf;
    if((pf=fopen(archivo,"r"))==NULL)
    {
        printf("Problema al intentar abrir %s",archivo);
        exit(2);
    }
    return pf;
}
