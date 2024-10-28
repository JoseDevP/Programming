#include <stdio.h>
#include <string.h>

int main(void) {
    char texto[40];
    char *c = NULL;

    printf("Introducir líneas de texto.\n");
    printf("Para finalizar introducir la marca EOF (Ctrl+Z en Windows, Ctrl+D en Unix)\n\n");

    do {

        if (fgets(texto, sizeof(texto), stdin) == NULL) {

            if (feof(stdin)) {
                printf("EOF detectado.\n");
                break; 
            }
            if (ferror(stdin)) {
                printf("Error de entrada.\n");
                break;
            }
        }

        //Busca \n y cambia por 0
        if ((c = strchr(texto, '\n')) != NULL) { // para que la cadena acabe en 0 en vez de\n
            *c = '\0';
        }
 
        

    } while (1); 

    puts(texto);
    return 0;
}
