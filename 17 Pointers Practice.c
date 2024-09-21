#include<stdio.h>
#include<string.h>
#define INI 0
#define FIN 1
#define AUX 2
//González Robles David Alejandro
//Vania Cadena Aguilar
//////////////////////////////////
struct atleta{
    char nombre[10];
    char apellido[10];
    int medalla;
    int pais;
};typedef struct atleta A;
//////////////////////////////////
struct atleta llena(void);

int main(){
    A atl[20], tmp, *ap[3];
    int op, otro, pa, tot[5][4]={0}, *aptot, op2, aux, a=0, b=0, *i, *j, e, r, c, ja, m;
    ap[INI]=ap[FIN]=ap[AUX]=&atl[0];
    aptot=&tot[0][0];
    i=&a;
    j=&b;
    do
    {
        printf("\n----LAS OLIMPIADAS----\n1.Guardar atletas\n2.Ver atletas\n3.Medallero\n4.Salir");
        scanf("%d",&op);
        switch(op)
        {
        case 1: otro=1;
                while(otro==1 && ap[FIN]-ap[INI]<20)
                {
                    *ap[FIN]=llena();
                    printf("¿Deseas agregar otro atleta por el momento?\t1)Si Otro)No\n");
                    scanf("%d", &otro);
                    aptot=&tot[(ap[FIN]->pais)-1][0];
                    *aptot+=1;
                    aptot=&tot[(ap[FIN]->pais)-1][(ap[FIN]->medalla)-1];
                    *aptot+=1;
                    ap[FIN]+=1;
                }
                break;
        case 2: do
                {
                    printf("Selecciona el pais\t1)EUA  2)Rusia  3)China  4)Japon  5)Mexico\n");
                    scanf("%d",&pa);
                    switch(pa)
                    {
                        case 1: printf("Estados Unidos\n");
                                break;
                        case 2: printf("Rusia\n");
                                break;
                        case 3: printf("China\n");
                                break;
                        case 4: printf("Japon\n");
                                break;
                        case 5: printf("México\n");
                                break;
                    }
                    for(ap[AUX]=ap[INI];ap[AUX]<ap[FIN];ap[AUX]++)
                    {
                        if(ap[AUX]->pais==pa){
                            printf("%s %s ", ap[AUX]->apellido, ap[AUX]->nombre);
                            switch(ap[AUX]->medalla)
                        {
                            case 1: printf("Oro\n");
                                break;
                            case 2: printf("Plata\n");
                                break;
                            case 3: printf("Bronce\n");
                                break;
                        }
                        }

                    }
                    printf("¿Quieres imprimir los datos de otro pais?\t1)SI otro)No\n");
                    scanf("%d", &otro);
                }while(otro==1);
                break;
        case 3: printf("¿Como quieres mostrar?\n1)Por todal de medallas  \n2)Por tipo de medallas\n");
                scanf("%d", &op2);
                switch(op2)
                {
                    case 1: e=tot[0][0];
                            r=tot[1][0];
                            c=tot[2][0];
                            ja=tot[3][0];
                            m=tot[4][0];
                            for(*i=0;(*i)<5;(*i)++){
                                for(*j=0;(*j)<4;(*j)++){
                                    if(tot[*j][0]<tot[*j][0]){
                                        aux=tot[*j][0];
                                        tot[*j][0]=tot[(*j)+1][0];
                                        tot[(*j)+1][0]=aux;
                                    }
                                }
                            }
                            for(*i=0;(*i)<5;(*i)++){
                                if(tot[*i][0]==e){
                                    printf("\nEstados Unidos\n");
                                    for(ap[AUX]=ap[INI];ap[AUX]<ap[FIN];ap[AUX]++)
                                    {
                                        if(ap[AUX]->pais==1){
                                            printf("%s %s ", ap[AUX]->apellido, ap[AUX]->nombre);
                                            switch(ap[AUX]->medalla)
                                        {
                                            case 1: printf("Oro\n");
                                                    break;
                                            case 2: printf("Plata\n");
                                                break;
                                            case 3: printf("Bronce\n");
                                                break;
                                        }
                                        }

                                    }
                                }
                                else{
                                    if(tot[*i][0]==r){
                                    printf("\nRusia\n");
                                    for(ap[AUX]=ap[INI];ap[AUX]<ap[FIN];ap[AUX]++)
                                    {
                                        if(ap[AUX]->pais==2){
                                            printf("%s %s ", ap[AUX]->apellido, ap[AUX]->nombre);
                                        switch(ap[AUX]->medalla)
                                        {
                                            case 1: printf("Oro\n");
                                                    break;
                                            case 2: printf("Plata\n");
                                                break;
                                            case 3: printf("Bronce\n");
                                                break;
                                        }}

                                    }
                                }
                                else{
                                    if(tot[*i][0]==c){
                                    printf("\nChina\n");
                                    for(ap[AUX]=ap[INI];ap[AUX]<ap[FIN];ap[AUX]++)
                                    {
                                        if(ap[AUX]->pais==3){
                                            printf("%s %s ", ap[AUX]->apellido, ap[AUX]->nombre);
                                        switch(ap[AUX]->medalla)
                                        {
                                            case 1: printf("Oro\n");
                                                    break;
                                            case 2: printf("Plata\n");
                                                break;
                                            case 3: printf("Bronce\n");
                                                break;
                                        }}

                                    }
                                }
                                else{
                                    if(tot[*i][0]==ja){
                                    printf("\nJapon\n");
                                    for(ap[AUX]=ap[INI];ap[AUX]<ap[FIN];ap[AUX]++)
                                    {
                                        if(ap[AUX]->pais==4){
                                            printf("%s %s ", ap[AUX]->apellido, ap[AUX]->nombre);
                                        switch(ap[AUX]->medalla)
                                        {
                                            case 1: printf("Oro\n");
                                                    break;
                                            case 2: printf("Plata\n");
                                                break;
                                            case 3: printf("Bronce\n");
                                                break;
                                        }}

                                    }
                                }
                                else{
                                    if(tot[*i][0]==m){
                                    printf("\nMexico\n");
                                    for(ap[AUX]=ap[INI];ap[AUX]<ap[FIN];ap[AUX]++)
                                    {
                                        if(ap[AUX]->pais==5){
                                            printf("%s %s ", ap[AUX]->apellido, ap[AUX]->nombre);
                                         switch(ap[AUX]->medalla)
                                        {
                                            case 1: printf("Oro\n");
                                                    break;
                                            case 2: printf("Plata\n");
                                                break;
                                            case 3: printf("Bronce\n");
                                                break;
                                        }}

                                    }
                                }
                                }
                                }
                                }
                                }

                            }
                }
                            break;
        case 4: printf("Adios\n");
                break;
        }

}while(op!=4 && ap[FIN]-ap[INI]<20);

    return 0;
}
////////////////////////////////////
struct atleta llena(void){
    A tmp;
    printf("Dame el nombre\n");
    scanf("%s", &tmp.nombre);
    printf("Dame el apellido\n");
    scanf("%s", &tmp.apellido);
    printf("¿Que medalla gano?\t 1)Oro  2)Plata  3)Bronce\n");
    scanf("%d", &tmp.medalla);
    printf("¿De que pais es?\t 1)EUA  2)Rusia  3)China  4)Japon  5)Mexico\n");
    scanf("%d", &tmp.pais);
    return tmp;
}
