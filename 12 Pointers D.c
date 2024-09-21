#include <stdio.h>
#include <stdlib.h>
struct direccion

{
    char calle[10];
    int num;
    char col[10];

};typedef struct direccion D;
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
    D dir;
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
void ordena(R *,int);
R *busca_promedio(R*,int,float);
D* busca_direccion(R*,int,N);
C* busca_calificaciones(R*,int,N);


int main()
{
    R ve[10],*apv,*apE;
    int i=0,opc,j;
    apv=&ve[0];
    N nombreB;
    float promB;
    D *apD;
    C *apC;
    do
    {
       printf("\n1. Alta\n2. Imprime \n3. Busca por nombre \n4. Buscar por promedio\n5.Buscar domicilio de un alumno\n6. Buscar calificaciones de alumno\n0.Salir\n");
       scanf("%d",&opc);
       switch(opc)
       {
           case 1: alta(apv,&i);
                 break;
           case 2: ordena(apv,i);
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
            case 5: printf("\n Ingresa el nombre completo a buscar");
                   fflush(stdin);
                   gets(nombreB.np);
                   fflush(stdin);
                   gets(nombreB.app);
                   fflush(stdin);
                   gets(nombreB.apm);
                   apD=busca_direccion(apv,i,nombreB);
                   if (apD!=NULL)
                    printf("\n Domicilio %s %d %s",apD->calle,apD->num,apD->col);
                   else
                    printf("\n No existe alumno ");
                   break;
            case 6:printf("\n Ingresa el nombre completo a buscar");
                   fflush(stdin);
                   gets(nombreB.np);
                   fflush(stdin);
                   gets(nombreB.app);
                   fflush(stdin);
                   gets(nombreB.apm);
                   apC=busca_calificaciones(apv,i,nombreB);
                   if (apC!=NULL)
                     for(j=0;j<3;j++)
                        printf("\n %s %f",(apC+j)->materia,(apC+j)->nota);
                   else
                     printf("\n No existe el alumno ");
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

        printf("\n Domicilio completo calle numero y colonia");
        fflush(stdin);
        gets((apv+*i)->dir.calle);
        scanf("%d",&(apv+*i)->dir.num);
        fflush(stdin);
        gets((apv+*i)->dir.col);
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

void ordena (R*apv,int i)
{
    int k,j;
    R aux;
    for (j=0;j<i;j++)
    {
        for (k=0;k<i-1;k++)
        {
            if (strcmp((apv+k)->name.app,(apv+k+1)->name.app)>0)
            {
                aux=*(apv+k);
                *(apv+k)=*(apv+k+1);
                *(apv+k+1)=aux;
            }
        }
    }
}
void imprime(R *apv,int i)
{
   int j,k;
   for(j=0;j<i;j++)
    {
        printf("\n\n Nombre completo %s %s %s",(apv+j)->name.np,(apv+j)->name.app,(apv+j)->name.apm);
        printf("\n\t Grupo %d",(apv+j)->grupo);
        printf("\n\tDomicilio %s %d %s",(apv+j)->dir.calle,(apv+j)->dir.num,(apv+j)->dir.col);
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
C* busca_calificaciones(R*apv,int i,N nombreB)
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
        return (&(apv+j)->cal);
    else
        return NULL;
}

D *busca_direccion(R*apv,int i, N nombreB)
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
        return (&(apv+j)->dir);
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
        printf("\n\tDomicilio %s %d %s",apE->dir.calle,apE->dir.num,apE->dir.col);
        printf("\n\n Nombre completo %s %s %s",apE->tutor.np,apE->tutor.app,apE->tutor.apm);
        printf("\n\tCalificaciones");
        for(k=0;k<3;k++)
        {
            printf("\n \r%s %f",apE->cal[k].materia,apE->cal[k].nota);
        }
        printf("\n Promedio %f ",apE->promedio);
}
