#include <stdio.h>
#include <stdlib.h>

void func_ej(int *);
void func_ej2(int *);

int main()
{
    int a;
    int *apA;
    printf("Dame el valor de a\n");
    scanf("%d",&a);
    apA=&a;
    func_ej(apA);
    printf("\n Valor de a %d valor del contenido de apA %d ",a,*apA);
    printf("\n Direccion antes de funci�n %p",apA);
    func_ej2(apA);
    printf("\n Valor del contenido de apA %d y direccion de la variable %p ",*apA,apA);
    return 0;
}


void func_ej(int *apA)
{
    *apA=*apA+1;
}

void func_ej2(int *apA)
{
    apA=apA+1;
      printf("\n Valor del contenido de apA %d y direccion de la variable %p ",*apA,apA);
}
