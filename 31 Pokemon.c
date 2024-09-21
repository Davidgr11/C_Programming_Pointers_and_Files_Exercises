#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<conio.h>

#define PLAYER 0//pos del arreglo del jugador
#define ATK 3//num de ataques de cada uno

struct ataque{//definici�n del ataque
    char nombre[30];
    int poder;
    int prob;
};

struct pokemon{//definici�n de los pokemon
    char nombre[15];
    int hp;
    struct ataque ataques[ATK];
};

//--------------

struct pokemon creaPokemon(char nombre[15], int hp){
    struct pokemon tmp;
    strcpy(tmp.nombre, nombre);
    tmp.hp = hp;
    return tmp;
}

void creaAtaques(struct ataque at[3], int pos, char nombre[30], int poder, int prob){
    strcpy(at[pos].nombre, nombre);
    at[pos].poder = poder;
    at[pos].prob = prob;
}

void imprimeStats(struct pokemon poke){//funci�n que recibe estructura e imprime sus datos
    printf("%s>>  ", poke.nombre);
    printf("HP: %d\n", poke.hp);
}

void imprimeAtaques(struct pokemon poke){//funci�n que recibe estructura e imprime sus ataques (que est�n dentro de otra estructura)
    int i;
    for(i=0; i<ATK; i++){
        printf("\t%d. %s\n",i+1, poke.ataques[i].nombre);
    }
}

int main(){
    struct pokemon pkmn[2];//listado de peleadores
    int ataque;//ataque elegido
    int actual=0; //pokemon del turno actual
    int otro=1; //pokemon que no tiene el turno actual

    srand(time(NULL));

    //*** Llena datos base ****
    pkmn[0] = creaPokemon("Pikachu", 220);
    creaAtaques(pkmn[0].ataques, 0, "Impact trueno", 50, 60);
    creaAtaques(pkmn[0].ataques, 1, "Ataque rapido", 30, 80);
    creaAtaques(pkmn[0].ataques, 2, "Trueno", 90, 40);

    pkmn[1] = creaPokemon("Eevee", 200);
    creaAtaques(pkmn[1].ataques, 0, "Golpe de cabeza", 35, 90);
    creaAtaques(pkmn[1].ataques, 1, "Ataque rapido", 30, 80);
    creaAtaques(pkmn[1].ataques, 2, "Derribo", 45, 70);

    //*** Inicia combate ***
    do{
        printf("-----------------------------\n");
        imprimeStats(pkmn[0]);
        imprimeStats(pkmn[1]);
        printf("-----------------------------\n");

        printf("Turno de %s\n", pkmn[actual].nombre);
        if(actual == PLAYER){//turno de jugador
            printf("Que ataque quieres usar?\n");
            imprimeAtaques(pkmn[actual]);
            do{
                printf("?");
                scanf("%d", &ataque);
            }while(ataque <1 && ataque>ATK);//fuera de rango de ataques, pide de nuevo
            ataque--;
        }else{//turno PC
            ataque = rand()%ATK;//ataque aleatorio: 0,1 o 2
        }

        //usar ataque
        printf("%s uso: %s\n", pkmn[actual].nombre, pkmn[actual].ataques[ataque].nombre);
        if(rand()%100 < pkmn[0].ataques[ataque].prob){//si un n�mero entre 0 y 100 es menor a la precision de ataque, causa da�o
            printf("%s -%d HP!\n", pkmn[otro].nombre, pkmn[actual].ataques[ataque].poder);
            pkmn[otro].hp-= pkmn[actual].ataques[ataque].poder;
        }else{
            printf("Pero fallo\n");
        }

        actual=(actual+1)%2;//limitarlo a 0 y 1
        otro=(otro+1)%2;//limitarlo a 0 y 1
        printf("\n\n");
        getch();//pausa entre cada turno

    }while(pkmn[actual].hp > 0);//si el pokemon que inicia turno tiene HP
    //fin de juego
    printf("***************************\n");
    if(pkmn[PLAYER].hp > 0 ){//Si el pokemon del jugador tiene vida, gana
        printf("Ganaste!");
    }else{
        printf("Perdiste!");
    }
    printf("\n***************************\n");
    getch();
}
