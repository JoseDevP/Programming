#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nombre[60];
    unsigned long dni;
} alumno;

void crearArchivoBinario(const char *nombreArchivo)
{
    FILE *pf = fopen(nombreArchivo, "wb");
    if (pf == NULL)
    {
        printf("Error al abrir el archivo para escritura.\n");
        exit(1);
    }

    alumno alumnos[] = {
        {"Juan Pérez", 12345678},
        {"Ana Gómez", 23456789},
        {"Carlos Martínez", 34567890},
        {"Laura Fernández", 45678901},
        {"Pedro González", 56789012}
    };

    size_t numAlumnos = sizeof(alumnos) / sizeof(alumnos[0]);

    for (size_t i = 0; i < numAlumnos; i++)
    {
        fwrite(&alumnos[i], sizeof(alumno), 1, pf);
    }

    fclose(pf);
    printf("Archivo binario creado exitosamente.\n");
}

int main()
{
    crearArchivoBinario("alumnos.bin");
    return 0;
}
