/*Paso por referencia
En resumen: a la función se le manda la variable con &, se recibe con * (se convierte en apuntador de memoria).
Todos los contenidos son accesibles con *
*/
#include<stdio.h>
/*
void duplica(int entero){
    printf("\n----\n%i %p\n", entero, &entero);
    entero = entero*2;
}*/

void duplicaReferencia(int *enteroIzq, int *entero2){//se recibe con *
    printf("\n----\n%i -> %p\n", *enteroIzq, enteroIzq);//* contenido, & direcci�n    //*entero = *entero * 2;
    printf("\n----\n%i -> %p\n", *entero2, entero2);//* contenido, & direcci�n    //*entero = *entero * 2;
    *enteroIzq = *enteroIzq * 2;
    *entero2 = *entero2 + 5;
}


int main(){
    int entero;//F4 ->6
    int entero2=8;

    printf("Escribe un entero: ");
    scanf("%i", &entero);


    printf("%i tiene %i bytes %p\n", entero, sizeof(entero), &entero);

    /*duplica(entero);
    printf("El doble es: %i\n", entero);*/

    duplicaReferencia(&entero, &entero2);//& hace referencia a la posicion en memoria
    printf("El doble por referencia es: %i en %p\n", entero, &entero);
    printf("El doble por referencia es: %i en %p\n", entero2, &entero2);

}
