#include<stdio.h>
/*
1. Apuntador de tipo archivo
2. Abrir el archivo con el apuntador
3. Operaciones (lectura o escritura)
4. Cerrar el archivo con el apuntador
*/

int main(){
    //1. Apuntador de tipo archivo
    FILE *file;
    char linea[100];

    //2. Abrir el archivo con el apuntador
    file = fopen("files/archivo_clase.txt", "r");//que archivo (en donde esta mi .c hay una carpeta files), como? (r = Read)
    if(file){
        //3. Operaciones (lectura o escritura)
        printf("Archivo abierto");
        printf("Lo que dice el archivo es:\n");
        while(!feof(file)){//mientras no sea fin de archivo
            if(fgets(linea, 100, file)){//lee una linea de m�ximo 100 letras
                printf("%s", linea);//imprime lo que ley�
            }
        }
    }else{
        printf("No se puede abrir el archivo");
    }
    //4. Cerrar el archivo con el apuntador
    fclose(file);
}

#include<stdio.h>
/*
1. Apuntador de tipo archivo
2. Abrir el archivo con el apuntador
3. Operaciones (lectura o escritura)
4. Cerrar el archivo con el apuntador
*/

int main(){
    //1. Apuntador de tipo archivo
    FILE *file;
    char linea[100], linea2[100];
    int i, otro;

    //2. Abrir el archivo con el apuntador
    file = fopen("files/archivo_nuevo3.csv", "w");//que archivo (en donde esta mi .c hay una carpeta files), como? (w = Write) (a = Append)
    if(!file){
        printf("No se puede abrir el archivo");
        return 1;
        //exit(1);
    }
    //3. Operaciones (lectura o escritura)
    i=1;
    printf("Archivo creado\n");
    do{
        printf("Dame un nombre: ");
        scanf("%s", linea);
        printf("Dame un apellido: ");
        scanf("%s", linea2);
        fprintf(file, "%s,%s\n", linea, linea2);
        //fputs(linea, file);
        printf("Quieres otro? 1. Si 0.No\n");
        scanf("%i", &otro);
        i++;
    }while(otro == 1);

    //4. Cerrar el archivo con el apuntador
    fclose(file);
}
/*
fgets()<--
fscanf()

fputs()
fprintf()<--
*/
