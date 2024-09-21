#include<stdio.h>
struct datoscliente
{  int numCta;
   char apellido[20],nombre[10];
   double saldo;
   };
int main()
{
    int i;
    struct datoscliente clienteb;
    FILE *ptrF;
    if((ptrF=fopen("credito.dat","wb"))==NULL)
       printf("No pudo abrirse el archivo");
    else
    {
            printf("Dame numero de cuenta");
            scanf("%d",&clienteb.numCta);
            printf("Dame nombre");
            fflush(stdin);
            gets(clienteb.nombre);
            printf("Dame apellido");
            fflush(stdin);
            gets(clienteb.apellido);
            printf("Dame el saldo");
            scanf("%lf",&clienteb.saldo);
            fwrite(&clienteb,sizeof(struct datoscliente),1,ptrF);

       fclose(ptrF);
       printf("Termino de escribir elementos en archivo");
    }  return 0;
  }

/*  25
123
6789
12
5
321*/
