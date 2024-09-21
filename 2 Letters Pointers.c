#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Gonzalez Robles David Alejandro
Cadena Aguilar Vania
López Vudoyra Ángel
Morán Franco Alethia Silvana
*//*
int main(void) {
  char pal1[20],pal2[20],aux;
  char *ap1,*ap2, *igual;
  int op,i,j,tam1=0,tam2=0, res=0, repite;
  do
  {
char letras[10]={0};
  printf("Escribe la primer palabra: \n");
  fflush(stdin);
  gets(pal1);
  tam1=strlen(pal1);
  ap1=&pal1[0];
  printf("Escribe la segunda palabra: \n");
  fflush(stdin);
  gets(pal2);
  tam2=strlen(pal2);
  ap2=&pal2[0];
  igual=&res;
  *igual=0;
  for(ap1=&pal1[0];*ap1!='\0';ap1+=1)
  {
    for (ap2=&pal2[0];*ap2!='\0';ap2+=1)
    {
      if(*ap1==*ap2)
      {

         repite=0;
         for (i=0;i<*igual;i++)
         {
           if(letras[i]==*ap1)
           {
             repite+=1;
           }
         }
         if(repite==0)
         {
           letras[*igual]=*ap1;
           *igual+=1;
         }
    }
  }
  }
  for (i=0;i<*igual;i++)
  {
    for (j=0;j<*igual-1;j++)
    {
      if (letras[j]>letras[j+1])
      {
        aux=letras[j];
        letras[j]=letras[j+1];
        letras[j+1]=aux;
      }
    }
  }
  if(*igual!=0)
  {
    printf("Las letras que se repiten son: ");
    for (i=0;i<*igual;i++)
    {
    printf("%c  ",letras[i]);
    }
  }
  else
  {
    printf("No se repite ninguna letra \n");
  }
  printf("\nQuieres comparar otras 2 palabras 1.Si 0.No");
  scanf("%d",&op);
  }while(op!=0);
  return 0;
}*/

int main(){
    char palabra1[20], palabra2[20], repetidas[20];
    char *pal1_ptr, *pal2_ptr, *rep_ptr, *aux_ptr;
    char *orden1, *orden2, letra;
    int opc, existe;

    do{
        pal1_ptr = &palabra1[0];
        pal2_ptr = &palabra2[0];

        // 1. Pedir
        printf("Escribe la palabra 1: ");
        scanf("%s", pal1_ptr);
        printf("Escribe la palabra 2: ");
        scanf("%s", pal2_ptr);

        rep_ptr = &repetidas[0];
        // 2. Comparar [perro  perico]
        while(*pal1_ptr != '\0'){
            pal2_ptr = &palabra2[0];
            while(*pal2_ptr != '\0'){
                if(*pal1_ptr == *pal2_ptr){
                    existe = 0;//no se repite
                    for(aux_ptr = &repetidas[0]; aux_ptr < rep_ptr; aux_ptr+=1){
                        if(*aux_ptr == *pal1_ptr){
                            existe = 1;
                        }
                    }
                    if(existe == 0){
                        *rep_ptr = *pal1_ptr;
                        rep_ptr++;
                    }
                }
                pal2_ptr++;
            }
            pal1_ptr++;
        }

        if( rep_ptr > &repetidas[0] ){
            // 3. Ordenar
            for(orden1 = &repetidas[0]; orden1 < rep_ptr-1 ; orden1++){
                for(orden2 = orden1+1 ; orden2 < rep_ptr ; orden2++){
                    if(*orden1 > *orden2){
                        letra = *orden1;
                        *orden1 = *orden2;
                        *orden2 = letra;
                    }
                }
            }

            // 3.b Imprimir
            printf("%s\n", repetidas);
            for(aux_ptr = &repetidas[0]; aux_ptr < rep_ptr; aux_ptr+=1){
                printf("%c ", *aux_ptr);
            }
        }else{
            printf("\nNo hay letras repetidas");
        }

        printf("\nQuieres repetir? 1. Si 0. No");
        scanf("%d", &opc);
    }while(opc == 1);

    return 0;
}
/*
Letras iguales
Solicita 2 palabras al usuario, posteriormente busca qué letras se repiten
en ambas palabras e imprímelas ordenadas alfabéticamente. Aunque haya
letras repetidas, cada una deberá aparecer sólo 1 vez. Si ninguna letra se
repite, debe aparecer un mensaje qe diga que ninguna letra se repite. El usuario debe poder repetir el programa y escribir un nuevo par de
palabras. Debes utilizar solo apuntadores para guardar y modificar el contenido de
todas las variables. Escribe la primer palabra: perro
Escribe la segunda palabra: perico
Las letras que se repiten son: e o p r
Quieres comparar otras 2 palabras? 1. Si 0. No: 1
Escribe la primer palabra: chocolate
Escribe la segunda palabra: popote
Las letras que se repiten son: e o t
Quieres comparar otras 2 palabras? 1. Si 0. No: 1
Escribe la primer palabra: sol
Escribe la segunda palabra: rana
Ninguna letra se repite
Quieres comparar otras 2 palabras? 1. Si 0. No: 0
*/
