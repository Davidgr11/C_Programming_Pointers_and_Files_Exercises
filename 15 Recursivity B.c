#include <stdio.h>
#include <stdlib.h>

int binario(int,int);
int main()
{
    int num,c=1,x;
    printf("\n Numero a convertir a binario\n");
    scanf("%d",&num);
    x=binario(num,c);
    printf("\n El numero binario es %d ",x);

    return 0;
}

int binario(int num,int c)
{
    if (num==0)
        return 0;
    else

        return num%2*c + binario(num/2,c*10);
}
