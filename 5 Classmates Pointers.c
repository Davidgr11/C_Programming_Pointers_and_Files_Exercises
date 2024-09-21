#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdio.h>
#include<string.h>

//constantes
#define INI 0
#define FIN 1
#define AUX 2
#define AUX2 3

struct Alumno{
    char nombre[15];
    char apellido[15];
};

int main(){
    struct Alumno al[15], *ptr[4];//4 apuntadores, pero todos como arreglo
    struct Alumno tmp;
    int opc, continua;

    ptr[INI] = ptr[FIN] = &al[0];

    do{
        //En estrutura temporal porque no se d�nde debe ir
        printf("Dame el nombre: ");
        scanf("%s", tmp.nombre);
        printf("Dame el apellido: ");
        scanf("%s", tmp.apellido);

        //1. Buscar en la lista actual en d�nde deber�a ir el tmp
        continua = 1;//bandera para saber si sigue o no
        for(ptr[AUX]=ptr[INI]; ptr[AUX]<ptr[FIN] && continua == 1; ){
            //Qu� pasa para que no se mueva el auxiliar (se quede en la posici�n donde debe ir tmp)
            /*
                a) Que el apellido nuevo sea mas peque�o que el de la lista
                b) Que los apellidos sean iguales y que el nombre nuevo sea m�s peque�o que el de la lista
            */
            if(strcmpi(tmp.apellido, ptr[AUX]->apellido) < 0
               || ( strcmpi(tmp.apellido, ptr[AUX]->apellido) == 0 && strcmpi(tmp.nombre, ptr[AUX]->nombre) < 0) ){
                continua = 0;
            }else{
                ptr[AUX]++;
            }
        }

        //2. Mover los alumnos desde el fin a la posici�n actual
        for(ptr[AUX2]=ptr[FIN]; ptr[AUX2]>ptr[AUX] ;ptr[AUX2]--){
            *ptr[AUX2] = *(ptr[AUX2]-1);
        }

        //3. Insertar el tmp en la posici�na ctual
        *ptr[AUX] = tmp;//guardar el nombre
        ptr[FIN]+=1;//mover el fin

        //Imprimir lista
        for(ptr[AUX]=ptr[INI]; ptr[AUX]<ptr[FIN]; ptr[AUX]++){
            printf("%s %s\n", ptr[AUX]->apellido, ptr[AUX]->nombre);
        }
        printf("\nQuieres guardar otro? \n1. Si 0. No\n");
        scanf("%i", &opc);

    //}while(opc==1 && ptr[FIN] < (ptr[INI]+15) );//Opcion A
    //}while(opc==1 && ptr[FIN] <= &al[14] );//Opcion B
    }while(opc==1 && ptr[FIN]-ptr[INI] < 15 );//Opcion C
    printf("La lista se lleno");
}
/*
Lista ordenada
Escribe un programa que permita guardar el nombre y apellidos de hasta
15 alumnos. El nombre del alumno nuevo se debe insertar
alfabéticamente comenzando por apellidos, si son iguales, se comparará el
nombre. Al finalizar la inserción se debe imprimir el listado actual y posteriormente
preguntar si se desea insertar un alumno nuevo o no. Si se llena la lista el programa debe terminar automáticamente (después
de imprimirla). El manejo del arreglo y su navegación se deben hacer únicamente
con apuntadores. Alejandro Lara
La lista:
1. Lara Alejandro
Eduardo Gonzalez
La lista:
1. Gonzalez Eduardo
2. Lara Alejandro
Andrea Gonzalez
La lista:
1. Gonzalez Andrea
2. Gonzalez Eduardo
3. Lara Alejandro
Ana Herrera
La lista:
1. Gonzalez Andrea
2. Gonzalez Eduardo
3. Herrera Ana
4. Lara Alejandro
*/
