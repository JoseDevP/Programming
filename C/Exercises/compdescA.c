/*
    Escribir una aplicaion para comprimir y descomprimir archivos binarios con informacion grafica.
    Cada archivo grafico se compone de un conjunto de bytes. Cada byte es un valor de 0 a 255 que represejtea
    el nivel dfe gris de un pixel del gráfico.

    El algoritmo de compresion es el siguiente:"cada secuencia de uno o mas bytes del mismo valor que haya en
    el archivo origne se va a representar con dos bytes, de tal forma que el primero representa el nivel de
    gris leido del archivo origen y el segundo, el numero total de bytes en la secuencia."

    Si la secuencia es superior a 255 bytes, utilizar la representacion de dos bytes que sea necesaria.

    a)Escribir una funcion que genere un archivo comprimido a partir de un archivo grafico, en el que 
    cada registro sea de la forma:

        typedef struct
        {
            char pixel;
            char total_bytes;
        } registro;

    El prototipo de esta funcion es:
        void comprimir(FILE *forigen,FILE *fcomprimido);

    donde forigen es el flujo que referencia al archivo gráfico que deseamos comprimir y fcomprimido 
    es el flujo que referencia al archivo donde almacenaremos los datos compridos. 

    b)Escribir una funcion con el prototipo siguiente:
        void descomprimir(FILE *fcomprimido, FILE *fdestino);
    Esta funcion decomprimira los datos que hay en el archivo referenciado por fcomprimido y los depositara
    en el archivo referenciado por fdestino.

    c)Escribir un programa de nombre compdesc que pueda ser utilizado de la forma siguiente:
        compdesc -c forigen fdestino              para comprimir
        compdesc -d forigen fdestino              para descomprimir
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    unsigned char pixel;
    unsigned char total_bytes;
}registro;

void comprimir(FILE *forigen, FILE *fcomprimido);
void descomprimir(FILE *fcomprimido, FILE *fdestino);

int main(int argc, char *argv[])
{
    FILE *forigen=NULL, *fdestino=NULL;
    if(argc != 4)
    {
        printf("Sintaxis: comp {-c | -d} forigen fdestino");
        exit(1);
    }
    if((forigen = fopen(argv[2],"rb"))==NULL)
    {
        printf("El archivo %s no puede abrirse\n", argv[2]);
        exit(1);
    }
    if((fdestino = fopen(argv[3],"wb"))==NULL)
    {
        printf("El archivo %s no puede abrirse\n", argv[3]);
        exit(1);
    }

    if(argv[1][0]=='-' && argv[1][1]=='c')
        comprimir(forigen,fdestino);
    else if(argv[1][0]=='-' && argv[1][1]=='d')
        comprimir(forigen,fdestino);
    else
        printf("Opcion incorrecta\n");
    
    fclose(forigen);
    fclose(fdestino);
    return 0;
}

void comprimir(FILE *forigen, FILE *fcomprimido)
{
    unsigned char byte =0, byteanterior=0, total=0;
    registro reg;
    int bytesreg=sizeof(registro);

    byte = fgetc(forigen);
    while (!ferror(forigen) && !feof(forigen))
    {
        total=0;
        byteanterior=byte;

        do
        {
            total++;
            byte = fgetc(forigen);
        } while (byteanterior==byte && total <255 && !ferror(forigen) && !feof(forigen));
        
        reg.pixel = byteanterior;
        reg.total_bytes = total;
        fwrite(&reg,bytesreg,1,fcomprimido);
    }
    if(ferror(forigen))
        perror("Error durante la lectura");
    
}

void descomprimir(FILE *fcomprimido, FILE *fdestino)
{
    registro reg;
    int bytesreg =sizeof(registro);

    fread(&reg,bytesreg,1,fcomprimido);
    while(!ferror(fcomprimido) && !feof(fcomprimido))
    {
        for (unsigned char i = 0; i < reg.total_bytes; i++)
            fputc(reg.pixel,fdestino);
        fread(&reg,bytesreg,1,fcomprimido);
    }
    if(ferror(fcomprimido))
    {
            perror("Error durante la lectura.");
    }
}