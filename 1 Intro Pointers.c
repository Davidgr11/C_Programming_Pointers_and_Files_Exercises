#include<stdio.h>
#include<string.h>
int main(){
    char palabra[30];
    char *p_ap;
    int vocales, tam, letra;
    int *v_ap;
    printf("Dame una palabra:");
    scanf("%s", palabra);
    v_ap = &vocales;
    *v_ap = 0;
    p_ap = &palabra[0];
    while(*p_ap != '\0'){//mientras no sea el fin de la palabra
        if(*p_ap == 'a' || *p_ap == 'e' || *p_ap == 'i' || *p_ap == 'o' || *p_ap == 'u'){
            *v_ap+=1;
        }
        p_ap+=1;
    }
    printf("La palabra tiene %i vocales", *v_ap);
}
/*#include <stdio.h>
Variables:
nombre
direccion de memoria
valor

Apuntador
nombre
direccion de memoria
valor es una direcci�n


int main(){
    int num1, num2, resp;
    int *ap;//declarar apuntador

    //validar que est� entre 1 y 9 con apuntador
    ap = &num1;//que espacio quiero cambiar, asigna la direccion
    do{
        printf("Dame el numero 1:");
        scanf("%i", &num1);
    }while(*ap>9 || *ap<1);

    ap = &num2;//que espacio quiero cambiar, asigna la direccion
    do{
        printf("Dame el numero 2:");
        scanf("%i", &num2);
    }while(*ap>9 || *ap<1);

    ap = &resp;//que espacio quiero cambiar, asigna la direccion
    *ap = num1 * num2;//lo que tiene ese espacio, cuanto vale?

    printf("%i x %i = %i",num1, num2, resp);
    return 0;
}*/
