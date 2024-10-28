#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LONG 100

typedef struct
{
    unsigned char nombre[LONG];
    float nota;
} alumno;

void addSampleRecords(FILE *file)
{
    alumno students[] = {
        {"Alice", 8.5},
        {"Bob", 6.0},
        {"Charlie", 9.2},
        {"Diana", 5.4},
        {"Eve", 7.8}
    };

    size_t numStudents = sizeof(students) / sizeof(students[0]);

    for (size_t i = 0; i < numStudents; i++)
    {
        fwrite(&students[i], sizeof(alumno), 1, file);
    }
}

int main(void)
{
    FILE *file = fopen("notas.bi", "wb");
    if (file == NULL)
    {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    addSampleRecords(file);

    fclose(file);

    printf("Archivo 'notas.bi' creado y registros añadidos exitosamente.\n");

    return EXIT_SUCCESS;
}
