#include <stdio.h>
#include <stdlib.h>
struct Alumno{
    int clave;
    char nombre[15];
};

int main(){
    struct Alumno alum[20], al_tmp;
    struct Alumno *ap_ini, *ap_fin, *ap_aux;//aupuntadores a la estructura
    int opc;

    ap_ini = ap_fin = &alum[0];

    do{
        printf("Que quieres hacer?\n");
        printf("1) Guardar un alumno al final\n");
        printf("2) Guardar un alumno al inicio\n");
        printf("3) Borrar un alumno por clave\n");
        printf("4) Salir\n");
        scanf("%i", &opc);

        switch(opc){
            case 1:
                //Inserto donde esta el fin
                printf("Cual es la clave ULSA? ");
                scanf("%i", &al_tmp.clave);
                printf("Cual es el nombre? ");
                scanf("%s", al_tmp.nombre);
                *ap_fin = al_tmp;//Si el contenido es una estructura completa con *
                //recorrer final
                ap_fin = ap_fin+1;
            break;
            case 2:
                //Inserto donde esta el fin
                printf("Cual es la clave ULSA? ");
                scanf("%i", &al_tmp.clave);
                printf("Cual es el nombre? ");
                scanf("%s", al_tmp.nombre);
                //Recorro los elementos
                for(ap_aux=ap_fin; ap_aux > ap_ini; ap_aux--){
                    *ap_aux = *(ap_aux-1);//Si el contenido es una estructura completa con *
                }
                //Insertar alumno
                *ap_ini = al_tmp;//Si el contenido es una estructura completa con *
                //recorrer final
                ap_fin = ap_fin+1;
            break;
            case 3:
                printf("Cual clave ULSA quieres borrar? ");
                scanf("%i", &al_tmp.clave);

                for(ap_aux = ap_ini;
                    ap_aux < ap_fin && al_tmp.clave != ap_aux->clave;
                    ap_aux++);//Este for no tiene contenido, solo mueve el apuntador hasta la primer ocurrencia de la clave

                //El for termina porque se acab� la lista o porque se encontr� la clave
                if(ap_aux < ap_fin){//Si est� en la lista
                    ap_fin--;
                    while(ap_aux < ap_fin){
                        *ap_aux = *(ap_aux+1);//Si el contenido es una estructura completa con *
                        ap_aux++;
                    }
                }else{
                    printf("La clave no esta en la lista");
                }

            break;
        }

        //Imprimir la lista
        printf("\n------------\n");
        if(opc != 4){
            for(ap_aux = ap_ini; ap_aux < ap_fin; ap_aux++){
                printf("Clave: %i\nNombre: %s\n", ap_aux->clave, ap_aux->nombre);
                ////Si el contenido es de un campo de la estructura con ->
            }
        }
        printf("------------\n");

    }while(opc != 4);

    return 0;
}
