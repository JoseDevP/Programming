#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("prueba.bin", "wb");
    if (file == NULL) {
        perror("No se pudo crear el archivo");
        return 1;
    }

    unsigned char datos[] = {10, 10, 10, 20, 20, 30, 30, 30, 30, 40, 50, 50, 50};
    size_t num_bytes = sizeof(datos) / sizeof(datos[0]);

    fwrite(datos, sizeof(unsigned char), num_bytes, file);

    fclose(file);

    printf("Archivo prueba.bin creado con éxito.\n");
    return 0;
}
