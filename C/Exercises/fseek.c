/*Acceso aleatorio a un archivo*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct 
{
    char nombre[40];
    char direccion[40];
    long telefono;
} registro;

void mostrarReg(FILE *pf, int nreg);
void modificarReg(FILE *pf, int nreg);
void fflushStdin(void);
char *readString(char *str,int n);

int main(void)
{
    FILE *pf=NULL;
    int totalReg=0;
    int nReg=0;
    char nombreArchivo[30];
    int c=0, respuesta=0;
    printf("Nombre del archivo: ");
    readString(nombreArchivo,sizeof(nombreArchivo));

    if((pf=fopen(nombreArchivo,"r+b"))==NULL)
    {
        perror("No se ha podido abrir el archivo");
        exit(EXIT_FAILURE);
    }

    fseek(pf,0,SEEK_END);
    totalReg=(int)ftell(pf)/sizeof(registro);

    do
    {
        printf("Nº de registro entre 1 y %d (0 para salir): ",totalReg);
        c=scanf("%d",&nReg);
        fflushStdin();

        if(c && (nReg >=1) && (nReg<=totalReg))
        {
            mostrarReg(pf,nReg);
            do
            {
                printf("¿Desea modificar este registro? (s/n)  ");
                respuesta=getchar();
                fflushStdin();
            } while (tolower(respuesta != 's') && tolower(respuesta != 'n'));
            if(respuesta=='s')
                modificarReg(pf,nReg);
        }
    } while (nReg);
    fclose(pf);
    
}

void mostrarReg(FILE *pf, int nreg)
{
    long desp=0;
    registro reg;
    int bytesPorReg=sizeof(registro);

    desp=(long)(nreg-1)*bytesPorReg;
    fseek(pf,desp,SEEK_SET);
    fread(&reg,bytesPorReg,1,pf);
    if(ferror(pf))
    {
        perror("Error al leer los datos");
        return;
    }
    printf("Nombre:     %s\n",reg.nombre);
    printf("Direccion:  %s\n",reg.direccion);
    printf("Telefono:   %d\n",reg.telefono);
}

void modificarReg(FILE *pf, int nreg)
{
    registro reg;
    int bytesPorReg=sizeof(registro);

    printf("Nombre:     ");
    readString(reg.nombre,sizeof(reg.nombre));
    printf("Direccion:  ");
    readString(reg.direccion,sizeof(reg.direccion));
    printf("Telegfono:  ");
    scanf("%d",&reg.telefono);
    fflushStdin();

    fseek(pf,-bytesPorReg,SEEK_CUR);
    fwrite(&reg,bytesPorReg,1,pf);
    if(ferror(pf))
    {
        perror("Error al escribir un registro.");
        return;
    }
}

void fflushStdin(void)
{
    while(getchar() != '\n');
}

char *readString(char *str,int n)
{
    char *fin, *c;
    fin=fgets(str,n,stdin);
    if(c=strchr(str,'\n'))
        *c='\0';
    else if(!feof(stdin))
        fflushStdin();
    return fin;
}
