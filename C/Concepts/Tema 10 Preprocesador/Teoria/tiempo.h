/**Definición de las macros: T_INICIAL(descripcion) y T_FINAL**/
#define TIEMPO 0
#if !defined(TIEMPO_DEFINIDO)
    #if defined(TIEMPO)
        #define TIEMPO_DEFINIDO

        #include <stdio.h>
        #include <time.h>

        clock_t inicial, final;
        #define T_INICIAL(descripcion) \
        printf("\n\npara    :%s",#descripcion);\
        inicial=clock();

        #define T_FINAL final=clock();\
        printf("\ntiempo : %g miliseg",\
        (double)(final-inicial));
    #else
        #define T_INICIAL(descripcion)
        #define T_FINAL
    #endif
#endif