/* Campos de Bits */
/* int no negativa*/
#include <stdio.h>

struct palabra                //total 32 bits:0 a 31
{
    unsigned car_ascii :7;    //  bits 0 a 6
    unsigned bit_paridad :1;  // bits 7
    unsigned operacion :5;    // bits 8 a 12
    unsigned           :18;   // bits 13 a 30 de relleno
    unsigned bit_sigmo :1;    // bits 31
};

int main(void) {
    struct palabra cb = { 'C', 1, 0x1E, 0 };

    printf("Tamaño total de la estructura en bytes: %zu\n\n", sizeof(cb));

    printf("Tamaño del campo car_ascii en bits: %d\n", 7);
    printf("Tamaño del campo bit_paridad en bits: %d\n", 1);
    printf("Tamaño del campo operacion en bits: %d\n", 5);
    printf("Tamaño del campo bit_sigmo en bits: %d\n", 1);

    printf("\nContenido de los campos:\n");
    printf("bit_sigmo: %d\n", cb.bit_sigmo);
    printf("operacion: %x\n", cb.operacion);
    printf("bit_paridad: %d\n", cb.bit_paridad);
    printf("carácter %c: %x\n", cb.car_ascii, cb.car_ascii);

    return 0;
}