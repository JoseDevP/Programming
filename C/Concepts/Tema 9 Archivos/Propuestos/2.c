/*
    Suponga que disponemos de un archivo en disco llamado alumnos, donde cada registro se corresponde
    con los miembros de una estrutura con lo siguiente.

    typef struct
    {
        unsigned int n_matricula;
        char nombre[40];
        char calificacion[2];
    }registro;

    La calificacion viene dada por 2 caracteres: SS (suspenso), AP (aprobado), NT (notable) y
    DB (sobresaliente). Realizar un programa que permita y visualizar el tanto por ciento de los
    alumnos suspendido, aprobados, notables y sobresalientes.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    unsigned int n_matricula;
    char nombre[40];
    char calificacion[2];
}registro;

int main(void)
{
    int nStudents=0;
    float nSS=0, nAP=0, nNT=0, nDB=0;
    registro reg;
    FILE *pf=NULL;
    
    if((pf=fopen("students.bi","rb"))==NULL)
    {
        perror("Error while opening the file.");
        exit(0);
    }

    fseek(pf,0,SEEK_END);
    nStudents= ftell(pf) / sizeof(registro);
    rewind(pf);

    for (int i = 0; i < nStudents; i++)
    {
        fread(&reg,sizeof(registro),1,pf);

        if (strcmp(reg.calificacion, "SS") == 0)
            nSS++;
        else if (strcmp(reg.calificacion, "AP") == 0)
            nAP++;
        else if (strcmp(reg.calificacion, "NT") == 0)
            nNT++;
        else if (strcmp(reg.calificacion, "DB") == 0)
            nDB++;
    }
    
    if (nStudents > 0)
    {
        printf("There's %.2f%% of failed students\n", (nSS / (float)nStudents) * 100);
        printf("There's %.2f%% of approved students\n", (nAP / (float)nStudents) * 100);
        printf("There's %.2f%% of notable students\n", (nNT / (float)nStudents) * 100);
        printf("There's %.2f%% of outstanding students\n", (nDB / (float)nStudents) * 100);
    }
    else
    {
        printf("No records found in the file.\n");
    }
}