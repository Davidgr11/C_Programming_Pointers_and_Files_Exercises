#include<stdio.h>
#include<string.h>

struct Atleta{
    char nombre[15];
    char apellido[15];
    int medalla;
    int pais;
};

struct Pais{
    int i;
    char nombre[15];
    int medallas[3];
};
char medalla[3][10]={"Oro", "Plata", "Bronce"};

//-----------

// Llena los datos de los paises: nombre y total de medallas
struct Pais * llenaPaises(struct Pais paises[5]){
    struct Pais *pfin;
    pfin = &paises[0];
    strcpy(pfin->nombre, "Estados Unidos");
    pfin->i = 0;
    pfin->medallas[0] = pfin->medallas[1] = pfin->medallas[2] = 0;
    pfin++;
    strcpy(pfin->nombre, "Rusia");
    pfin->i = 1;
    pfin->medallas[0] = pfin->medallas[1] = pfin->medallas[2] = 0;
    pfin++;
    strcpy(pfin->nombre , "China");
    pfin->i = 2;
    pfin->medallas[0] = pfin->medallas[1] = pfin->medallas[2] = 0;
    pfin++;
    strcpy(pfin->nombre , "Japon");
    pfin->i = 3;
    pfin->medallas[0] = pfin->medallas[1] = pfin->medallas[2] = 0;
    pfin++;
    strcpy(pfin->nombre , "Mexico");
    pfin->i = 4;
    pfin->medallas[0] = pfin->medallas[1] = pfin->medallas[2] = 0;
    pfin++;
    return pfin;
}

//Busca el pais en el listado y aumenta 1 al contador de la medalla
void agregaMedalla(struct Pais paises[5], struct Pais *ini, struct Pais *fin , int pais, int medalla){
    struct Pais *aux;
    for(aux = ini; aux<fin; aux++){
        if(aux->i == pais){
            aux->medallas[medalla]++;
        }
    }
}

/*imprime listado de paises, el ultimo parametro indica si lleva medalla o no
    Si no lleva, ordena por id
    Si lleva no ordena, pero imprime medallas
*/
void imprimePais(struct Pais paises[5], struct Pais *ini, struct Pais *fin, int medallas){
    struct Pais *p_aux1, *p_aux2, tmp;
    int i;

    if(medallas == 0){//No quiero ver medallas, quiero ver los paises que hay
        //ordenar por ID
        for(p_aux1 = ini; p_aux1<fin-1; p_aux1++){
            for(p_aux2 = p_aux1+1; p_aux2<fin; p_aux2++){
                if( p_aux1->i > p_aux2->i){
                    tmp = *p_aux1;
                    *p_aux1 = *p_aux2;
                    *p_aux2 = tmp;
                }
            }
        }
    }

    for(p_aux1 = ini; p_aux1<fin; p_aux1++){
        if(medallas == 0){
            printf("\t%i. %s\n", p_aux1->i, p_aux1->nombre);
        }else{
            printf("\t%s\t", p_aux1->nombre);
            for(i=0; i<3; i++){
                printf("%i %s\t", p_aux1->medallas[i], medalla[i]);
            }
            printf("\n");
        }
    }
}

//Imprime listado de atletas del pais elegido
void imprimeAtletaPais(struct Atleta atletas[15], int pais, struct Atleta *ini, struct Atleta *fin){
    struct Atleta *aux;
    for(aux = ini; aux<fin; aux++){
        if(aux->pais == pais){
            printf("\t%s %s - Medalla: %s\n", aux->nombre, aux->apellido, medalla[aux->medalla]);
        }
    }
    printf("\n");
}


//Ordena paises por total de medallas. si hay empate, ordena por nombre
void medalleroTotal(struct Pais paises[5], struct Pais *p_ini, struct Pais *p_fin){
    struct Pais *p_aux1, *p_aux2, tmp;
    int total1, total2;

    for(p_aux1 = p_ini; p_aux1 < p_fin-1; p_aux1++){
        for(p_aux2 = p_aux1+1; p_aux2 < p_fin; p_aux2++){
            total1 = (p_aux1->medallas[0]+p_aux1->medallas[1]+p_aux1->medallas[2]);
            total2 = (p_aux2->medallas[0]+p_aux2->medallas[1]+p_aux2->medallas[2]);

            if( total1 < total2 || ( total1 == total2 && strcmp(p_aux1->nombre, p_aux2->nombre) > 0) ){
                tmp = *p_aux1;
                *p_aux1 = *p_aux2;
                *p_aux2 = tmp;
            }
        }
    }
}

//Ordena paises por tipo de medallas. Si hay empate de oro, ordena por plata, si hay empate por bronce
void medalleroTipo(struct Pais paises[5], struct Pais *p_ini, struct Pais *p_fin){
    struct Pais *p_aux1, *p_aux2, tmp;

    for(p_aux1 = p_ini; p_aux1 < p_fin-1; p_aux1++){
        for(p_aux2 = p_aux1+1; p_aux2 < p_fin; p_aux2++){

            if( p_aux1->medallas[0] < p_aux2->medallas[0] ||
                ( p_aux1->medallas[0] == p_aux2->medallas[0] && p_aux1->medallas[1] < p_aux2->medallas[1]) ||
                ( p_aux1->medallas[0] == p_aux2->medallas[0] && p_aux1->medallas[1] == p_aux2->medallas[1] && p_aux1->medallas[2] < p_aux2->medallas[2])
            ){
                tmp = *p_aux1;
                *p_aux1 = *p_aux2;
                *p_aux2 = tmp;
            }
        }
    }

}


//----------
int main(){
    struct Atleta atletas[20], *ini, *fin, *aux;
    struct Pais paises[5], *p_ini, *p_fin, *p_aux;
    int opc1, opc2;
    FILE *file;

    ini = fin = &atletas[0];
    p_ini=&paises[0];

    file = fopen("datosAtletas.dat", "rb");
    if(file){
        /*while( fread(&atleta[i], sizeof(struct Atleta), 1, file) ){
            i++;
        }*/
        while( fread(fin, sizeof(struct Atleta), 1, file) ){
            //agregaMedalla(paises, p_ini, p_fin, fin->pais, fin->medalla);
            fin++;
        }
    }
    fclose(file);

    file = fopen("datosPaises.dat", "rb");
    if(file){
        fread(paises, sizeof(struct Pais), 5, file);
        p_fin = &paises[4];
        p_fin++;
    }else{

        p_fin = llenaPaises(paises);
    }
    fclose(file);


    do{
        printf("1. Guardar atleta\n");
        printf("2. Ver atletas por pais\n");
        printf("3. Medallero\n");
        printf("0. Salir\n");
        scanf("%i", &opc1);
        switch(opc1){
            case 1://Guardar
                if(fin<=&atletas[19]){
                    printf("Escribe el pais\n");
                    do{
                        imprimePais(paises, p_ini, p_fin, 0);//listado sin medallas
                        scanf("%i", &fin->pais);
                    }while(fin->pais <0 || fin->pais>4);
                    printf("Escribe el nombre: ");
                    scanf("%s", fin->nombre);
                    printf("Escribe el apellido: ");
                    scanf("%s", fin->apellido);
                    do{
                        printf("Que medalla obtuvo?\n\t0. Oro\n\t1. Plata\n\t2. Bronce\n");
                        scanf("%i", &fin->medalla);
                    }while(fin->medalla < 0 || fin->medalla>2);
                    //---Agregar medallas a pais
                    agregaMedalla(paises, p_ini, p_fin, fin->pais, fin->medalla);

                    fin++;

                }else{
                    printf("Atletas completos\n");
                }
            break;
            case 2://Ver
                printf("Que pais quieres ver?\n");
                do{
                    imprimePais(paises, p_ini, p_fin, 0);//listado sin medallas
                    scanf("%i", &opc2);
                }while(opc2 <0 || opc2>4);
                //---Imprime todos los atletas del pais elegido
                imprimeAtletaPais(atletas, opc2, ini, fin);
            break;
            case 3://Medallero
                printf("Que medallero quieres ver?\n\t0. Por total de medallas\n\t1. Por tipo de medalla\n");
                scanf("%i", &opc2);
                if(opc2 == 0){
                    medalleroTotal(paises, p_ini, p_fin);
                }else{
                    medalleroTipo(paises, p_ini, p_fin);
                }
                imprimePais(paises, p_ini, p_fin, 1);//listado con medallas
            break;
            default://Guardar archivo
                file = fopen("datosAtletas.dat", "wb");
                for(aux = ini; aux<fin; aux++){
                    fwrite(aux, sizeof(struct Atleta),1, file);
                }
                /*for(i=0;i<tam; i++){
                    fwrite(&atletas[i], sizeof(struct Atleta),1, file);
                }*/
                fclose(file);

                file = fopen("datosPaises.dat", "wb");
                fwrite(paises, sizeof(struct Pais),5, file);
                fclose(file);

            break;

        }
        printf("\n\n\n");
    }while(opc1>0);
}
