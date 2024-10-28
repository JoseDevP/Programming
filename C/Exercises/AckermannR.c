/*
    Ackermann:
    A(m,n) para m = 0 -> n+1
    A(m,n) para m > 0 y n = 0 -> A(m-1,1)
    A(m,n) para m > 0 y n > 0 -> A(m-1,A(m,n-1))
*/

#include <stdio.h>

int Ackermann(int m, int n)
{
  if (m == 0)
    return n+1;
  else if (n == 0)
    return Ackermann(m-1, 1);
  else
    return Ackermann(m-1, Ackermann(m,n-1));
}

int main(void)
{
    int n=0;
    int m=0;

    printf("Input value for n:  ");
    scanf("%d",&n); while(getchar() != '\n');

    printf("Input value for m:  ");
    scanf("%d",&m); while(getchar() != '\n');

    if (m < 0 || n < 0)
    {
        printf("Values for m and n must be negatives\n");
        return 1; 
    }

    int res=Ackermann(m,n);
    printf("Result: %d",res);
    return 0;
}