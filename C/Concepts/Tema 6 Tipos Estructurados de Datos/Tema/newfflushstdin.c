/* En vez de usar while(getchar()!='\n')
    Usaremos  fgets(cadena,sizeof(cadena),stdin)
*/
#include <stdio.h>

int main(void)
{
    int entero;
    double real;
    char respuesta = 's', cadena[81];

    printf("Introducir un nº entero y un nº real:\n");
    scanf("%d %lf", &entero, &real);
    printf("%d + %f = %f\n\n",entero,real,entero+real);

    fgets(cadena,sizeof(cadena),stdin); //limpia el buffer metiendolo aqui

    printf("Introducir cadenas para fgets.\n");
    while (respuesta=='s' && fgets(cadena,sizeof(cadena),stdin)!=NULL)
    {
        printf("%s\n",cadena);
        do
        {
            printf("¿Desea continuar? (s/n) ");
            respuesta=getchar();
            while (getchar() != '\n');
            
        } while ((respuesta) != 's' && (respuesta != 'n'));
        
    }
    
}