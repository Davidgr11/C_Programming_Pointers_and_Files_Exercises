#include <stdio.h>
#include <stdlib.h>
void imprime (int v[15])
{
  for (int i=0;i<15;i++)
  {
    if(v[i]!=0)
    {
      printf("%d",v[i]);
    }
  }
}
int main() {
  int v[15]={0},opc, guardados,aux,i,nuevo,p;
  int *apnum, *apguarda,*fin;
  apguarda=&guardados;
 *apguarda=0;
 fin=&p;
 *fin=0;
 apnum=&v[0];
  do{
  printf("\n1)Insertar numero al principio\n2)Insertar numero al final\n3)Borrar un numero\n4)Salir\n");
  scanf("%d",&opc);
  if(*apguarda<15)
  {
  switch(opc)
  {
    case 1:  printf("�Que numero desea insertar?\n");
            apnum=&v[0];
            if(*apnum==0)
            {
              scanf("%d",&nuevo);
              *apnum=nuevo;
              *apguarda+=1;
            }
            else
            {
              for(i=14;i>0;i--)
              {
                aux=v[i-1];
                v[i-1]=v[i];
                v[i]=aux;
              }
              scanf("%d",&nuevo);
              *apnum=nuevo;
              *apguarda+=1;
            }
            imprime(v);
    break;
    case 2:
    printf("�Que numero desea insertar?\n");
         apnum=&v[*apguarda];

         if(*apnum==0)
            {
              scanf("%d",&nuevo);
              *apnum=nuevo;
              *apguarda+=1;
            }
            else
            {
              apnum+=1;
              scanf("%d",&nuevo);
              *apnum=nuevo;
              *apguarda+=1;
              }
            imprime(v);
    break;
    case 3:
    printf("�Que numero desea eliminar?\n");
    break;
  }
  }
  else
  {
    printf("El vector ya esta lleno\n");
  }
  }while (opc!=4);
  printf("\nAdioooos");
  return 0;
}

/*
Lista
Escribe un programa que permita guardar hasta 15 n�meros. El programa
debe poder hacer lo siguiente:
1. Insertar un n�mero al final de la lista
2. Insertar un n�mero al inicio de la lista
3. Borrar un n�mero de la lista (la primer ocurrencia)
4. Salir del programa
Despu�s de cada operaci�n se deben imprimir los elementos de la lista. Si la lista ya est� llena y el usuario quiere insertar un n�mero nuevo, deber�s mostrar un mensaje de error, no se inserta ning�n elemento
nuevo y el programa continua. El manejo del arreglo y su navegaci�n se deben hacer �nicamente
con apuntadores. Insertar 5 al inicio
La lista: 5
Insertar 4 al inicio
La lista: 4 5
Insertar 8 al inicio
La lista: 8 4 5
Insertar 4 al final
La lista: 8 4 5 4
Insertar 1 al final
La lista: 8 4 5 4 1
Quitar 4
La lista: 8 5 4 1 <-- Se quita solo la primer ocurrencia


Se ve que funciona bien (salvo el borrado que queda pendiente).

Lo �nico que no me gusta mucho es cuando insertan al final: apnum=&v[*apguarda];
ser�a mejor mover el apuntador al final que estarlo cambiando a la posici�n del contador.

*/
