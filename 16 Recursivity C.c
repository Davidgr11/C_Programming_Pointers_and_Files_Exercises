#include <stdio.h>
#include <stdlib.h>

void llena(int [10]);
void imprec(int [10],int);
int main()
{
    int v[10],i=0,x;
    llena(v);
    printf("\n Invertido\n");
    imprec(v,i);
    return 0;
}
void llena(int v[10])
{
    int i;
    for(i=0;i<10;i++)
    {
        v[i]=rand()%6;
        printf("%d\t",v[i]);
    }
}

void imprec(int v[10],int i)
{
    int x;

    if (i==10)
         {

            return ;
         }


    else
    {
        imprec(v,i+1);
        printf(" %d",v[i]);
    }

}
