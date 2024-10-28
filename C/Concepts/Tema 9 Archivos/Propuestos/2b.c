#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    unsigned int n_matricula;
    char nombre[40];
    char calificacion[3];  
} registro;

int main(void)
{
    FILE *pf = NULL;
    registro registros[] = {
        {1001, "Juan Perez", "SS"},
        {1002, "Maria Garcia", "AP"},
        {1003, "Carlos Lopez", "NT"},
        {1004, "Ana Martinez", "DB"},
        {1005, "Luis Hernandez", "AP"},
        {1006, "Laura Rodriguez", "SS"},
        {1007, "Pedro Sanchez", "NT"},
        {1008, "Sofia Ramirez", "DB"}
    };
    
    int nRegistros = sizeof(registros) / sizeof(registro);

    if ((pf = fopen("students.bi", "wb")) == NULL)
    {
        perror("Error opening file for writing.");
        exit(1);
    }

    for (int i = 0; i < nRegistros; i++)
    {
        fwrite(&registros[i], sizeof(registro), 1, pf);
    }

    fclose(pf);

    printf("Archivo 'students.bi' creado con %d registros.\n", nRegistros);

    return 0;
}