/*A partir de la misma baraja de cartas �C�mo se har�a un juego de "UNO" (un poco modificado)?

Despu�s de revolverlas se reparten 7 entre 2 jugadores: La persona y la PC, posteriormente una carta se coloca al
frente (pila de juego) para dar comienzo al juego, y el resto se quedan en la pila de robo.
El jugador en turno deber� seleccionar una carta con el mismo n�mero o la misma figura que se colocar� en la pila de juego,
si no tiene, debe robar una carta y el turno pasa al siguiente jugador.
El juego termina cuando no haya m�s cartas en la pila para robar (gana el que tenga una suma de cartas menor), o cuando
un jugador se quede sin cartas (es el ganador).

Otras modificaciones para mayor dificultad
1 jugador humano y 3 PC
Si se roba una carta, �sta se puede jugar inmediatamente
Quitar de la baraja la J, Q y K, a�adir las cartas Reversa y Saltar (en 4 colores)*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct carta{52
    int num, figura, activa;
};
struct jugadores{2, 7r

};
