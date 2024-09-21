#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void convierteMayusculas(char *);
void imprimeCaracter(const char *);

int main()
{
    char cadena[]="caracteres y $32.98";
    printf ("la cadena antes de la conversion es :%s\n",cadena);
    convierteMayusculas(cadena);
    printf("La cadena despues de la conversion es : %s\n",cadena);
    imprimeCaracter(cadena);
    return 0;
}

void convierteMayusculas(char *ptrS)
{
    while(*ptrS !='\0')
    {
        if(islower(*ptrS))
           *ptrS=toupper(*ptrS);
        ++ptrS;
    }


}

void imprimeCaracter(const char *ptrS)


{
    printf("\nla cadena es %p\n",ptrS);

    for (;*ptrS!='\0';ptrS++)
    {
        printf("%c",*ptrS);
        printf("\n");
    }
}
