#include <stdio.h>
#include <stdlib.h>

#define TAM 10

void ordenaMBurbuja(int * arreglo,const int tamanio);
void intercambia(int *ptrElemento1,int *ptrElemento2);

int main()
{
   int a[TAM]={2,6,4,8,12,10,89,68,45,1};
   int *apa=&a;

   int i;
   printf("\nElementos del arreglo en desorden\n");

   for(i=0;i<TAM;i++)
{
    printf("%4d  %d\n",a[i],*(apa+i));

}
ordenaMBurbuja(apa,TAM);
printf ("\nLos elementos ordenados son \n");
 for(i=0;i<TAM;i++)
{
    printf("%4d",a[i]);
}
printf("\n");
return 0;
}
void ordenaMBurbuja (int * arreglo, const int tamanio)
{
    int pasada;
    int j;


    for(pasada=0;pasada<tamanio-1;pasada++)
    {
        for(j=0;j<tamanio-1;j++)
        {
           // if (arreglo[j]>arreglo[j+1]){
              if (*(arreglo+j)>*(arreglo+j+1)){

               //intercambia(&arreglo[j],&arreglo[j+1]);}
               intercambia((arreglo+j),(arreglo+j+1));}
        }
    }

}

void intercambia(int *ptrElemento1,int *ptrElemento2)
{
    int almacena=*ptrElemento1;
    *ptrElemento1=*ptrElemento2;
    *ptrElemento2=almacena;
}
