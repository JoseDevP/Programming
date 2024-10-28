#include <stdio.h>  
#include <stdlib.h>  

int main(void)
{
    printf("%s\n",__DATE__);
    printf("%s\n",__TIME__);
    printf("%s\n",__FILE__);
    int nLinea=__LINE__;
    printf("%d\n",nLinea);
    //int std=__STDC__;
    //printf("%d\n",std);
}