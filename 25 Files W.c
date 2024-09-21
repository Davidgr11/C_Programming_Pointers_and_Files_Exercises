
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Gonzalez Robles David Alejandro
Cadena Aguilar Vania
López Vudoyra Ángel
Morán Franco Alethia Silvana
*/
int main()
{
    system("color 1f");
    FILE *file;
    char producto[10][50],aux[50];
    int i=0,j,opc,cont=0;
    file=fopen("archivolista.txt", "w+");
    printf("Lista de super\n");
    do
    {
    printf("\n----¿Que deseas?----\n1.Agregar algo a la lista\n2.Leer la lista\n3.Salir\n");
    scanf("%d",&opc);
    if(opc==1)
    {
        printf("Que quieres agregar a la lista\n");
        scanf("%s",producto[0]);
        fprintf(file,"%s\n",producto[0]);
        cont++;
        system("cls");
    }
    else
    {
    rewind(file);
    for(i=0;i<cont;i++)
    {
        //strcpy(nombres[r], fgets(archivo));
        fgets(producto[i],100,file );
        printf(" %s \n ", producto[i]);
    }
   for(i=0;i<cont;i++){
        for(j=0;j<cont-1;j++){
            if(strcmp(producto[j], producto[j+1])>0){
                strcpy(aux, producto[j]);
                strcpy(producto[j], producto[j+1]);
                strcpy(producto[j+1], aux);
            }
        }
    }
    printf("\n---------------------------------------\nLos productos ordenados son\n");
    //fputs("Lista ordenada\n",file);
    for(i=0;i<cont;i++){
        //fprintf(file,"\n%s", producto[i]);
        printf("%s\n", producto[i]);
    }
   fclose(file);
    }
    }while(opc!=3);
    return 0;
}
