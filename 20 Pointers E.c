#include <stdio.h>
#include <stdlib.h>

void llena(int *);
void imprime (int *);

int main()
{
    int v[10],*apv;
    apv=&v[0];
    printf("Llenar vector\n");
    llena(apv);
    imprime(apv);
    return 0;
}

void llena(int *apv)
{
    int i;
    // No cambia el apuntdor al inicio apv
    /*for (i=0;i<10;i++)
        *(apv+i)=rand()%50;*/
    //Cambia la direccion de apv
 /* for (i=0;i<10;i++)
  {
     *apv=rand()%50;
      apv=apv+1;
  }*/
 int *apvf;
  apvf=(apv+9);
  for (;apv<=apvf;apv++)
       *apv=rand()%50;

}
void imprime (int *apv)
{
    int i;
    for (i=0;i<10;i++)
        printf("%d  ",*(apv+i));
}
