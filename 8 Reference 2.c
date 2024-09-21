#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*
Generar 20 aleatorios entre 0 y 10
En una funci�n:
-Calcular el promedio
-Decir cuantos numeros son inferiores al promedio
-Decir cuantos numeros son mayores al promedio

El main imprime los totales
*/

void calculaPromedio(int num[20], int *inf, int *may){
    float promedio=0;
    int i;
    //printf("\n%p", inf);
    for(i=0;i<20;i++){
        promedio+=num[i];
    }
    promedio = promedio/20.0;
    *inf = 0;
    *may = 0;

    for(i=0;i<20;i++){
        if(num[i] < promedio){
            *inf=*inf+1;
        }else if(num[i] > promedio){
            *may=*may+1;
        }
    }

    //printf("\n%d son inferiores, %d son mayores al promedio", *inf, *may);
}

int main(){
    int num[20];
    int inf, may, i;
    //printf("%p", &inf);
    //printf("\n%d son inferiores, %d son mayores al promedio\n", inf, may);
    srand(time(NULL));
    //20 aleatorios entre 0 y 10
    for(i=0;i<20;i++){
        num[i] = rand()%11;
        printf("%i ", num[i]);
    }

    calculaPromedio(num, &inf, &may);

    printf("\n%d son inferiores, %d son mayores al promedio", inf, may);
    system("pause");
}
