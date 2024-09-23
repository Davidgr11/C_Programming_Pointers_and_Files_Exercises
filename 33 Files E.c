#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//library

struct libro
{
    char nombre[35];
    char autor[30];
    int isbn;
    char editorial[15];
};typedef struct libro biblio;

int escribe_archivo (FILE *);
int lee_archivo (FILE *);
int buscar_isbn(FILE *,int);
int buscar_numreg(FILE *,int);
int modificar_editorial(FILE *,int);
int vaciar_datos_vector(FILE *,biblio[40],int*);
void ordena_vector(biblio [40],int);
void imprime_ordenados(biblio [40],int);

int main()
{

FILE *p;
int num,numisbn,numreg,cont=0,opc,exito,dir=0;
biblio biblioV[40];

do
{
  printf("\n\n\t MENU::\n1.Dar de alta registro en archivo\n2.Leer todo el archivo\n3.Buscar isbn\n4.Acceder info de un # de registro\n5.Modificar editorial\n6.Ordenar informacion por autor\n0.Salir");
  scanf("%d",&opc);
  switch (opc)
  {
  case 1: p=fopen("libros2.bin","ab");
          if (p!=NULL)
             {
                 exito=escribe_archivo(p);
                if (exito==0)
                    printf("\n No se ingreso ningun registro");
             }
          else
             printf("\n No se pudo abrir el archivo");
          printf("cierre archivo\n\n\n");
          fclose(p);
          break;
        case 2:p=fopen("libros2.bin","rb");
            if (p==NULL)
                printf("Error al abrir el archivo");
            else
                {
                    exito=lee_archivo(p);
                    if (exito==0)
                      printf("\n Problemas al leer");
                }
                fclose(p);
                break;
        case 3:p=fopen("libros2.bin","rb");
               if (p==NULL)
                    printf("Error al abrir el archivo");
               else
               {
                   printf("\nDame el isbn que deseas consultar");
                   scanf("%d",&numisbn);
                   exito=buscar_isbn(p,numisbn);
                   if (exito==0)
                    printf("\n Problemas en busqueda ");
                   else
                    printf("\n Busqueda exitosa");

               }
               fclose(p);
               break;
        case 4:p=fopen("libros2.bin","rb");
               if (p==NULL)
                    printf("Error al abrir el archivo");
               else
               {
                 printf("\nDame el numero de registro que deseas consultar");
                 scanf("%d",&numreg);
                 exito=buscar_numreg(p,numreg);
                 if (exito==0)
                    printf("\nProblemas en busqueda ");
                 else
                    printf("\nTermino funcion exitosamente");
                 fclose(p);
               }
                 break;
        case 5:p=fopen("libros2.bin","rb+");
               if (p==NULL)
                  printf("\n Error al abrir el archivo");
               else
               {
                   printf("\n Ingresa el ISBN que deseas modificar ");
                   scanf("%d",&numisbn);
                   exito=modificar_editorial(p,numisbn);
                   if (exito==0)
                      printf("\n Fracaso Modificaci�n ");
                   else
                      printf("\n Modificaci�n exitosa ");

               }
               fclose(p);
               break;
        case 6:p=fopen("libros2.bin","rb");
               if (p!=NULL)
                 {
                     exito=vaciar_datos_vector(p,biblioV,&dir);
                    if (exito==1)
                    {
                        printf("\n Datos vaciados correctamente");
                        ordena_vector(biblioV,dir);
                        imprime_ordenados(biblioV,dir);
                    }
                    else
                        printf("\n No se vacio correctamente el archivo");
                 }
               else
                  printf("\n Error al abrir el archivo ");
               fclose(p);
               break;

  }
}while (opc!=0);

return 0;
}

int vaciar_datos_vector(FILE *p,biblio VB[40],int *dir)
{
    biblio x;
    int band=0;
    fread(&x,sizeof(struct libro),1,p);
    while(!(feof(p))&&*dir<40)
    {

        strcpy(VB[*dir].nombre,x.nombre);
        strcpy(VB[*dir].autor,x.autor);
        VB[*dir].isbn=x.isbn;
        strcpy(VB[*dir].editorial,x.editorial);
        *dir=*dir+1;
        band=1;
        fread(&x,sizeof(struct libro),1,p);

    }
    return band;
}

void ordena_vector(biblio VB[40],int dir)
{
    int i,j;
    biblio aux;
    for(i=0;i<dir;i++)
    {
        for(j=0;j<dir-1;j++)
        {
            if (strcmp(VB[j].autor,VB[j+1].autor)>0)
            {
                aux=VB[j];
                VB[j]=VB[j+1];
                VB[j+1]=aux;
            }
        }
    }
}

void imprime_ordenados(biblio VB[40],int dir)
{
    int i=0;
    while (i<dir)
    {
        printf("\n\n %s Autor :%s ISBN %d Editorial %s",VB[i].nombre,VB[i].autor,VB[i].isbn,VB[i].editorial);
        i++;
    }
}

int modificar_editorial(FILE *p,int numisbn)
{
    biblio x;
    int band=0;
    char edit[15];

    fread(&x,sizeof(biblio),1,p);
    while(numisbn!=x.isbn && !feof(p))
    {
        fread(&x,sizeof(biblio),1,p);
    }
    if (numisbn==x.isbn)
    {
        printf("\n Ingresa el nombre de la editorial correcta ");
        fflush(stdin);
        gets(edit);
        strcpy(x.editorial,edit);
        fseek(p,-1*sizeof(biblio),SEEK_CUR);
        if (!fwrite(&x,sizeof(biblio),1,p))
            band=0;
        else
           band=1;
    }
    return band;
}

int buscar_numreg(FILE *p,int numreg)
{
    biblio x;
    int band=0;
    fseek(p,(numreg-1)*sizeof(biblio),SEEK_SET);
    if(fread(&x,sizeof(struct libro),1,p))
    {
        band=1;
        printf("\n%s\t%s\t%d\t%s",x.nombre,x.autor,x.isbn,x.editorial);
    }
  return band;
}

int escribe_archivo(FILE *p)
{
    biblio x;
    int alta,band=0;
    do
    {
        printf ("dame el nombre del libro");
        fflush(stdin);
        gets(x.nombre);
        printf("dame el nombre del autor");
        fflush(stdin);
        gets(x.autor);
        printf("dame el isbn");
        scanf("%d",&x.isbn);
        printf("dame la editorial");
        fflush(stdin);
        gets(x.editorial);
        printf("===>%s\t%s\t%d\t%s\n",x.nombre,x.autor,x.isbn,x.editorial);
        if (!fwrite(&x,sizeof(biblio),1,p))
            printf("\n Error al escribir");
        else
        {
           printf("\n Insertado exitosamente");
           band=1;
        }
        printf("deseas dar otra alta 0 para salir");
        scanf("%d",&alta);
        }while(alta!=0);
  return band;
}

int lee_archivo(FILE *p)
{
    biblio x;
    int band=0;
    fread(&x,sizeof(struct libro),1,p);
    printf("\n LIBROS ::\n");
    while(!(feof(p)))
    {
        band=1;
        printf("%s\t%s\t%d\t%s\n",x.nombre,x.autor,x.isbn,x.editorial);
        fread(&x,sizeof(struct libro),1,p);

    }
    return band;
}

int buscar_isbn(FILE *p,int numisbn)
{
    biblio x;
    int band=0;
    fread(&x,sizeof(biblio),1,p);
    while ((x.isbn!=numisbn) && !(feof(p)))
    {

        fread(&x,sizeof(struct libro),1,p);
    }
    if (x.isbn==numisbn)
    {
        printf("%s\t%s\t%d\t%s\n",x.nombre,x.autor,x.isbn,x.editorial);
        band=1;
    }
    else
        printf("Elemento no existe");
  return band;
}
