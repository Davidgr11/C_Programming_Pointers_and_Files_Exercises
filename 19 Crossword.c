#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//David Alejandro Gonzalez Robles

struct palabras{
    char palabra[15], dir;
    int x, y;
    int activa;
};typedef struct palabras P;
////////////////////////////////////
void llena(char m[12][11], P per[6]);
void imprime(char m[12][11]);
////////////////////////////////////
int main()
{
    system("color 1f");
    P per[6];
    char m[12][11], posible[15];
    int i, band, correcta, xaux, yaux, j=0;
    printf("-------------BIENVENIDO AL CRUCIGRAMA DE EMPRESAS Y STARTUPS--------------\n");
    llena(m, per);
    do
    {
        printf("------------------------------------------------------------------------------------------------------------\n\n");
        imprime(m);
        printf("PISTAS\n1. Es una empresa multinacional estadounidense cuya principal filial es Google.\n");
        printf("2. Compañía tecnológica multinacional, El famoso sonido de inicio fue creado por Brian Eno.\n");
        printf("3. Es un conglomerado estadounidense de redes sociales. Recibio inicialmente el soporte financiero de Peter Thiel, cofundador de PayPal\n");
        printf("4. La empresa tecnologica mas valiosa del planeta, la distingue el diseño y la creatividad. Su fundador también fundo Pixar y Next\n");
        printf("5. Tiene el objetivo de hacer a la humanidad una especie interplanetaria, primera empresa privada en llegar a la orbita, su fundador es de origen sudafricano\n");
        printf("6. Primera startup unicornio(mil millonaria) mexicana\n");
        printf("\nDAME LA PALABRA CORRECTA\n");
        scanf("%s", &posible);
        strupr(posible);
        band=0;
        for(i=0;i<6 && band==0;i++){
            if(strcmp(per[i].palabra, posible)==0){
                band=1;
                correcta=i;
            }
        }
        if(band==1){
            if(per[correcta].activa==0){
                j++;
                if(per[correcta].dir=='H'){
                    yaux=per[correcta].y;
                    xaux=per[correcta].x;
                    for(i=0;i<15 && per[correcta].palabra[i]!='\0';i++){
                        m[yaux][xaux]=per[correcta].palabra[i];
                        xaux++;
                    }
                }
                else
                {
                    yaux=per[correcta].y;
                    xaux=per[correcta].x;
                    for(i=0;i<15 && per[correcta].palabra[i]!='\0';i++){
                        m[yaux][xaux]=per[correcta].palabra[i];
                        yaux++;
                    }
                }
                per[correcta].activa=1;
            }
            else
            {
                printf("La palabra ya se adivino\n");
                system("pause");
            }
        }
        else
        {
            printf("La palabra no se encuenta en el crucigrama\n");
            system("pause");
        }
        system("cls");
    }while(j!=6);
    imprime(m);
    return 0;
}
void llena(char m[12][11], P per[6]){
    int r, c, yaux, xaux, i;
    strcpy(per[0].palabra, "ALPHABET");
    strcpy(per[1].palabra, "MICROSOFT");
    strcpy(per[2].palabra, "FACEBOOK");
    strcpy(per[3].palabra, "APPLE");
    strcpy(per[4].palabra, "SPACEX");
    strcpy(per[5].palabra, "KAVAK");
    per[0].x=2;
    per[0].y=1;
    per[1].x=1;
    per[1].y=3;
    per[2].x=3;
    per[2].y=5;
    per[3].x=6;
    per[3].y=1;
    per[4].x=1;
    per[4].y=8;
    per[5].x=10;
    per[5].y=5;
    per[0].dir='H';
    per[1].dir='V';
    per[2].dir='H';
    per[3].dir='V';
    per[4].dir='H';
    per[5].dir='V';
    per[0].activa=0;
    per[1].activa=0;
    per[2].activa=0;
    per[3].activa=0;
    per[4].activa=0;
    per[5].activa=0;
    for(r=0;r<12;r++){
        for(c=0;c<11;c++){
            m[r][c]=' ';
        }
    }
    m[1][1]='1';
    m[2][1]='2';
    m[5][2]='3';
    m[0][6]='4';
    m[8][0]='5';
    m[4][10]='6';
    for(r=0;r<6;r++){
        if(per[r].dir=='H'){
                    yaux=per[r].y;
                    xaux=per[r].x;
                    for(i=0;i<15 && per[r].palabra[i]!='\0';i++){
                        m[yaux][xaux]='*';
                        xaux++;
                    }
        }
        else{
            yaux=per[r].y;
            xaux=per[r].x;
            for(i=0;i<15 && per[r].palabra[i]!='\0';i++){
                m[yaux][xaux]='*';
                yaux++;
            }
        }
    }
}
void imprime(char m[12][11]){
    int r, c;
    for(r=0;r<12;r++){
        for(c=0;c<11;c++){
            printf("%c   ", m[r][c]);
        }
        printf("\n");
    }
}
//tablero
//impimir
//Listado de 6 pistas
//no es  necesario el numero, solo da la palabra
//terminar cuando todas se adivinen
