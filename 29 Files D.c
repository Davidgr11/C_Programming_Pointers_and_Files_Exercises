#include<stdio.h>
struct datoscliente
{  int numCta;
   char apellido[20],nombre[10];
   double saldo;};

int main()
{
    struct datoscliente clienteb;
    FILE *ptrF;
    if((ptrF=fopen("C:\Users\David Alejandro\Documents\Programación\Progra.Estruct\Archivos y extras\Archivos 3g\credito.dat","wb"))==NULL)
       printf("No pudo abrirse el archivo");
    else
    {
       printf("%6s%16s%11s\n","Cta","Apellido","Nombre","Saldo");
       fread(&clienteb,sizeof(struct datoscliente),1,ptrF);
        while(!feof(ptrF))
         {
            printf(" %8d %s %s  %f\n",clienteb.numCta,clienteb.apellido,clienteb.nombre,clienteb.saldo);
            fread(&clienteb,sizeof(struct datoscliente),1,ptrF);
          }
       fclose(ptrF);
    }  return 0;
  }
