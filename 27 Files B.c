#include <stdio.h>
int main()
{
   int cuenta; char nombre[30];float saldo,cont=0;
  FILE *ptrCf;


  if (( ptrCf=fopen("cliente.txt","a"))==NULL)
  {
     printf ("El archivo no pudo abrirse");
  }
  else
 {  /*lee la cuenta,sado, y nombre del archivo*/
   printf("%10s%13s%10s\n","Cuenta","Nombre","Saldo");

rewind(ptrCf);
//while(!feof(ptrCf))
   while(cont!=3)
   {
       fscanf(ptrCf,"%d%s%f\n",&cuenta,&nombre,&saldo);
       printf("%d  %s  %f\n",cuenta,nombre,saldo);



       cont=cont+1;
    }
   fclose(ptrCf);
 }   return 0;
}

