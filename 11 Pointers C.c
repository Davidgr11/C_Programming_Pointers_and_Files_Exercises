#include <stdio.h>
#include <stdlib.h>
struct calificaciones
{
    char materia[15];
    float nota;
};typedef struct calificaciones C;

struct nombre
{
    char np[15];
    char app[15];
    char apm[15];

};typedef struct nombre N;

struct registo_escolar
{
    N name;
    char dir[20];
    N tutor;
    int grupo;
    C cal[3];
    float promedio;
};typedef struct registo_escolar R;

void alta (R*,int*);
void imprime (R*,int);
R* busca_nombre (R*,int,N);
void imprimeuno(R*);
float fprom(C*);
R *busca_promedio(R*,int,float);


int main()
{
    R ve[10],*apv,*apE;
    int i=0,opc;
    apv=&ve[0];
    N nombreB;
    float promB;
    do
    {
       printf("\n1. Alta\n2. Imprime \n3. Busca por nombre \n4. Buscar por promedio\n0.Salir\n");
       scanf("%d",&opc);
       switch(opc)
       {
           case 1: alta(apv,&i);
                 break;
           case 2: //ordena(apv,i);
                 imprime(apv,i);
                 break;
            case 3: printf("\n Ingresa el nombre completo a buscar");
                   fflush(stdin);
                   gets(nombreB.np);
                   fflush(stdin);
                   gets(nombreB.app);
                   fflush(stdin);
                   gets(nombreB.apm);
                   apE=busca_nombre(apv,i,nombreB);
                   if (apE!=NULL)
                     imprimeuno(apE);
                   else
                      printf("\n No existe ese alumno ");
                   break;
            case 4:printf("\n Ingrese el promedio a buscar ");
                   scanf("%f",&promB);
                   apE=busca_promedio(apv,i,promB);
                   if (apE!=NULL)
                    imprimeuno(apE);
                   else
                    printf("\n Ninguno coincide con ese promedio");
                   break;



       }
    }while (opc!=0);

    return 0;
}



void alta (R*apv,int *i)
{
    int j;
    if (*i<10)
    {
        printf("\n Ingresa el nombre completo ");
        fflush(stdin);
        gets((apv+*i)->name.np);
        fflush(stdin);
        gets((apv+*i)->name.app);
        fflush(stdin);
        gets((apv+*i)->name.apm);
        printf("\n grupo ");
        scanf("%d",&(apv+*i)->grupo);
        printf("\n Ingresa el nombre completo del padre o tutor ");
        fflush(stdin);
        gets((apv+*i)->tutor.np);
        fflush(stdin);
        gets((apv+*i)->tutor.app);
        fflush(stdin);
        gets((apv+*i)->tutor.apm);

        printf("\n Domicilio");
        fflush(stdin);
        gets((apv+*i)->dir);
        for(j=0;j<3;j++)
        {
            printf("\n Nombre de la materia");
            fflush(stdin);
            gets((apv+*i)->cal[j].materia);
            printf("\n Nota obtenida");
            scanf("%f",&(apv+*i)->cal[j].nota);
        }

        (apv+*i)->promedio=fprom(&(apv+*i)->cal[0]);

        *i=*i+1;
    }
    else
        printf("\n No hay espacio");
}

float fprom(C *apC)
{
    int i;
    float prom=0;
    for(i=0;i<3;i++)
    {
        prom=prom + (apC+i)->nota;
    }
    prom=prom/3;
    return prom;
}

void imprime(R *apv,int i)
{
   int j,k;
   for(j=0;j<i;j++)
    {
        printf("\n\n Nombre completo %s %s %s",(apv+j)->name.np,(apv+j)->name.app,(apv+j)->name.apm);
        printf("\n\t Grupo %d",(apv+j)->grupo);
        printf("\n\tDomicilio%s",(apv+j)->dir);
        printf("\n\n Nombre completo %s %s %s",(apv+j)->tutor.np,(apv+j)->tutor.app,(apv+j)->tutor.apm);
        printf("\n\tCalificaciones");
        for(k=0;k<3;k++)
        {
            printf("\n \r%s %f",(apv+j)->cal[k].materia,(apv+j)->cal[k].nota);
        }
        printf("\n\t Promedio %f ",(apv+j)->promedio);

    }
}
R* busca_nombre(R*apv,int i,N nombreB)
{
    int j=0,band=0;
    while (j<i && band==0)
    {
       if (strcmp(nombreB.np,(apv+j)->name.np)==0 && strcmp(nombreB.app,(apv+j)->name.app)==0)
          band=1;
       else
           j++;
    }
    if (band==1)
        return (apv+j);
    else
        return NULL;
}

R* busca_promedio(R *apv,int i, float prom)
{
     int j=0,band=0;
    while (j<i && band==0)
    {
       if (prom==(apv+j)->promedio)
          band=1;
       else
           j++;
    }
    if (band==1)
        return (apv+j);
    else
        return NULL;
}

void imprimeuno(R* apE)
{
    int k;
      printf("\n Nombre completo %s %s %s",apE->name.np,apE->name.app,apE->name.apm);
        printf("\n\t Grupo %d",apE->grupo);
        printf("\n\tDomicilio%s",apE->dir);
        printf("\n\n Nombre completo %s %s %s",apE->tutor.np,apE->tutor.app,apE->tutor.apm);
        printf("\n\tCalificaciones");
        for(k=0;k<3;k++)
        {
            printf("\n \r%s %f",apE->cal[k].materia,apE->cal[k].nota);
        }
        printf("\n Promedio %f ",apE->promedio);
}
