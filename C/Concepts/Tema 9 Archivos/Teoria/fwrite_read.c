/*fwrite.c*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *pf1=NULL, *pf2=NULL;
    char car, cadena[36];
    if((pf1=fopen("f1.txt","wb"))==NULL)
    {
        perror("No se ha podido abrir el archivo");
    }
    if((pf2=fopen("f2.txt","wb"))==NULL)
    {
        perror("No se ha podido abrir el archivo");
    }
    
    fgets(cadena,36,stdin);
    car=getchar();

    fwrite(&car,sizeof(char),1,pf1);
    fwrite(cadena,sizeof(cadena),1,pf2);

    fclose(pf1);
    fclose(pf2);

    FILE *pf3=NULL, *pf4=NULL;
    char car2, cadena2[36];
    if((pf3=fopen("f1.txt","rb"))==NULL)
    {
        perror("No se ha podido abrir el archivo");
    }
    if((pf4=fopen("f2.txt","rb"))==NULL)
    {
        perror("No se ha podido abrir el archivo");
    }

    fread(&car2,sizeof(char),1,pf1);
    fread(cadena2,sizeof(cadena),1,pf2);

    printf("Letra %c, cadena %s",car2,cadena2);

    fclose(pf3);
    fclose(pf4);
}