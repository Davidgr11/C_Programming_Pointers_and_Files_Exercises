#include <stdio.h>
int main ()
{
  int cuenta,cont;
  char nombre[30];
  float saldo;

FILE *ptrCf;
ptrCf=fopen("cliente.txt","a");
if(ptrCf==NULL)
     printf ("El archivo no pudo abrirse");
else
{
    do
    {
      printf("introduzca cuenta nombre y saldo");
      scanf ("%d",&cuenta);
      fflush(stdin);
      gets (nombre);
      scanf ("%f",&saldo);
      fprintf(ptrCf,"%d %s %f\n",cuenta,nombre,saldo);
      printf("Desea continuar teclee 1 para salir");
      scanf("%d",&cont);
    }while(cont!=1);
fclose(ptrCf);
}
/*
ptrCf=fopen("c:\\clientes.dat","r");
  if (ptrCf==NULL)
  {
     printf ("El archivo no pudo abrirse");
  }
  else
{  /*lee la cuenta,sado, y nombre del archivo*/
 /*  printf("%10s%13s%s\n","Cuenta","Nombre","Saldo");
   fscanf(ptrCf,"%d%s%lf",&cuenta,nombre,&saldo);
   while(!feof(ptrCf))
   {
       printf("%d%s%lf\n",cuenta,nombre,saldo);
       fscanf(ptrCf,"%d%s%lf",&cuenta,nombre,&saldo);
    }
   fclose(ptrCf);
}*/
return 0;
}

