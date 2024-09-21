#include <stdio.h>
#include <stdlib.h>

/*
Hice una estructura helado que lleva los datos generales: tipo y los toppings que lleva
Para automatizar y no escribir los datos a mano, hice una estructura Topping con el nombre y costo
Ambas estructuras no est�n vinculadas expl�citamente, pero se que el topping 0 del helado es el topping
0 de la otra estructura
    Si el helado tuviera una estructura Topping, entonces para cada helado tendr�a que definirle
    el nombre y el costo al topping
    Y habr�a hasta 20*3 estructuras de toppings (que no se necesitan tantas)


*/

//datos de helado
struct Helado{
    int tipo;//1 sencillo o 2 doble
    int toppings[3];//1 arreglo de banderas, 1 si lo tiene 0 si no
};

//Datos de toppings
//no est�n vinculados directamente al helado, es solo para tener la informacion
struct Topping{
    char nombre[8];
    int costo;
};

void initTopping(struct Topping top[3]){//Llena datos iniciales
    strcpy(top[0].nombre, "Chispas");
    top[0].costo = 2;
    strcpy(top[1].nombre, "Oreo");
    top[1].costo = 4;
    strcpy(top[2].nombre, "KitKat");
    top[2].costo = 6;
}

int main(){
    struct Helado helados[20];//maximo 20 helados del cliente
    struct Topping top[3];//descripcion general de los toppings
    int numH=0;//contador de helados
    int opc;//opcion elegida
    int subtotal, total;//subtotal de 1 helado, total de todos
    int i, t;//contadores para ciclos
    initTopping(top);//llena datos de topping

    do{
        printf("Como quieres tu helado?\n1. sencillo 2. doble\n");
        scanf("%d", &opc);
        if(opc == 1){//Si es 1 es sencillo, otra cosa doble
            helados[numH].tipo = 1;
        }else{
            helados[numH].tipo = 2;
        }

        for(t=0; t<3; t++){//recorre datos de los toppings para obtener el nombre
            printf("Quieres %s en tu helado?\n1. Si 0. No\n", top[t].nombre);
            scanf("%d", &opc);
            if(opc == 1){
                helados[numH].toppings[t]=1;
            }else{
                helados[numH].toppings[t]=0;
            }
        }
        numH++;//ya llevo 1 helado m�s

        printf("Quieres otro helado?\n1. Si 0. No\n");
        scanf("%d", &opc);

    }while(opc != 0 && numH<20);//Si le puse que no quer�a o ya tengo 20 helados se sale

    printf("\n*** Total de compra ***\n");

    total = 0;//inicio el acumulador
    for(i=0; i<numH; i++){
        subtotal = 0;//cada helado reinicia el acumulador
        if(helados[i].tipo == 1){
            printf("Helado sencillo ");
            subtotal+=20;
        }else{
            printf("Helado doble ");
            subtotal+=30;
        }
        for(t=0; t<3; t++){//recorre todos los toppings
            if(helados[i].toppings[t] != 0){//si el helado actual tiene ese topping
                printf("con %s ", top[t].nombre);
                subtotal+=top[t].costo;
            }
        }
        printf("\t$%d\n", subtotal);
        total+=subtotal;//sutotal del helado se acumula con el total de la compra
    }//fin for helados

    printf("Total: $%d", total);
}

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

González Robles David Alejadro
Cadena Aguilar Vania
López Vudoyra Ángel
Morán Franco Alethia Silvana
/////////////////////////

struct Heladeria
{
  char nombre[25];
  int precio;
  int preciotop;
};
//////////////////////////
void llenar(struct Heladeria hed[20], int op, int op2, int i, int t[3])
{
  int p[3]={2,4,6}, j;
  if(op==0){
  strcpy(hed[i].nombre,"sencillo");
  hed[i].precio=20;
  }
  else
  {
  strcpy(hed[i].nombre,"doble");
   hed[i].precio=30;
  }
  if(op2==1){
  hed[i].preciotop=0;
    for (int j=0;j<3;j++){
      if(t[j]==1){
      hed[i].preciotop=hed[i].preciotop+p[j];
      }
    }
  }
  else
  {
    hed[i].preciotop=0;
  }
}
//////////////////////////
void imprime(struct Heladeria hed[20], int i){
  int j;
  printf("RESUMEN DE COMPRA\n");
  for(j=0;j<=i;j++){
    printf("Helado %s precio total %d\n", hed[j].nombre, hed[j].precio+hed[j].preciotop);
  }
}
int main() {
  int i=0, op,seguir=1,op2, t[3]={0}, cont;
  char tipo[3][10]={{"chispas"}, {"oreo"}, {"kitkat"}};
  struct Heladeria hed[20];
  printf("BIENVENIDO A LA HELADERIA CHONITA VOL.2\n");
  do{
    printf("Ingrese 0 si desea un helado sencillo, 1 para  doble\n");
     scanf("%d", &op);
    printf("Ingrese 1 si desea entrar a la seccion de toppings\n");
    scanf("%d",&op2);
    if(op2==1)
    {
      for(cont=0;cont<3;cont++)
      {
      printf("Ingrese 1 si desea agregar un topping de %s, ingrese otro valor si no lo desea\n",tipo[cont]);
      scanf("%d",&t[cont]);
      }
    }
    llenar(hed, op, op2, i, t);
    printf("1)Agregar otro helado 2)Finalizar compra\n");
    scanf("%d",&seguir);
    if(seguir==1)
    {
      i++;
    }
    else{
          imprime(hed, i);
    }
  }while (seguir==1 && i<20);
  return 0;
}

Heladería
Una heladería necesita un programa que calcule el precio total de la compra de
helados e “imprima” un ticket con la descripción desglosada de la compra. El precio de un helado se calcula de acuerdo a la siguiente información:
 Si el helado es sencillo, cuesta $20, pero si es doble cuesta $30
 Si lleva como topping Chispas cuesta $2 adicional
 Si lleva como topping Oreo cuesta $4 adicional
 Si lleva como topping Kit Kat cuesta $6 adicional
Los toppings son opcionales y el helado puede llevar más de uno, es decir, se puede
solicitar con chispas y Oreo (pero no se puede elegir múltiples veces el mismo
topping). Al finalizar la selección de los toppings deberás preguntar si el cliente
quiere otro helado o no. Una vez terminada la compra, deberás imprimir en la pantalla el ticket de compra
desglosado con la descripción de cada uno de los helados comprados, su costo y el
costo total de la compra. * Deberás usar al menos 1 estructura. Considera que el máximo de helados por
cliente son 20 * Ejemplo de ticket
Helado sencillo con chispas $22
Helado doble con chispas con oreo con kitkat $42
Helado sencillo con kitkat $26
Total de */
