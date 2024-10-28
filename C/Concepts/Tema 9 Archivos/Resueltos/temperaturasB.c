#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct cabecera {
    struct posicion {
        int grados, minutos;
        float segundos;
    } latitud, longitud;

    int total_muestras;
};

void escribir_archivo(char *nombrefich, int total_muestras) {
    FILE *pf = NULL;
    struct cabecera cab;
    
    cab.latitud.grados = 40;
    cab.latitud.minutos = 23;
    cab.latitud.segundos = 15.5;

    cab.longitud.grados = -3;
    cab.longitud.minutos = 42;
    cab.longitud.segundos = 10.7;

    cab.total_muestras = total_muestras;

    float *temperaturas = (float *)malloc(total_muestras * sizeof(float));
    if (temperaturas == NULL) {
        printf("Error: Memoria insuficiente\n");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));
    for (int i = 0; i < total_muestras; i++) {
        temperaturas[i] = (rand() % 4000) / 100.0f - 10.0f; // Temperaturas entre -10.0 y 30.0
    }

    pf = fopen(nombrefich, "wb");
    if (pf == NULL) {
        perror("Error al abrir el archivo para escribir");
        free(temperaturas);
        exit(EXIT_FAILURE);
    }

    fwrite(&cab, sizeof(struct cabecera), 1, pf);
    fwrite(temperaturas, sizeof(float), total_muestras, pf);

    fclose(pf);
    free(temperaturas);

    printf("Archivo '%s' creado con %d temperaturas.\n", nombrefich, total_muestras);
}

int main() {
    char nombrefich[20];
    int total_muestras;

    printf("Nombre del archivo a crear: ");
    scanf("%s", nombrefich);

    printf("Número total de muestras de temperatura: ");
    scanf("%d", &total_muestras);

    escribir_archivo(nombrefich, total_muestras);

    return 0;
}
