 /*punteros.c*/
//DA ERROR
 #include <stdio.h>

 int main(void)
 {
    int a = 10, *p, *q;
    double b = 0.0;

    q=&a;

    b=*q;
    *p=20;// NO HEMOS DICHO A DONDE APUNTA

    printf("En la dirección %p está el dato %g\n",q,b);
    printf("En la dirección %p está el dato %g\n",p,*p);
 }