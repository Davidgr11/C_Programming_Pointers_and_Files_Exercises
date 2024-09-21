#include<stdio.h>
#include<stdlib.h>

int push(int*, int*);
int pop(int*, int*);
void imprime(int*, int);

int main()
{
    int V[6], i=0, opc, *apV, val;
    apV=&V[0];
    do
    {
        printf("\nMenu Principal:\n1.Push\n2.Pop\n3.Salir\nOpcion: ");
        scanf("%d",&opc);
        switch(opc)
        {
            case 1:
                val=push(apV, &i);
                if(val==1)
                    printf("\nDato insertado");
                else
                    printf("\nStack lleno   OVERFLOW");
            break;
            case 2:
                val=pop(apV, &i);
                if(val==-1)
                    printf("\nStack vacio   UNDERFLOW");
                else
                    printf("\nEl dato borrado fue: %d", val);
            break;
            case 3: printf("\n Hasta luego");
            break;
            default:
                printf("\nOpcion no vailda");
            break;
        }
        printf("\n");
        imprime(apV, i);
    }while(opc!=3);
    return 0;
}

int push(int *apV, int *i)
{
    int num;
    if(*i<6)
    {
        printf("\nDa un numero: ");
        scanf("%d", &num);
        *(apV+(*i))=num;
        *i=*i+1;
        return(1);
    }
    else
        return(0);
}

int pop(int *apV,int *i)
{
    int num;
    if(*i!=0)
    {
        *i=*i-1;
        num=*(apV+(*i));
        return(num);
          }
    else
    {
        return(-1);
    }
}

void imprime(int *apV, int i)
{
    int j;
    for(j=0;j<i;j++)
    {
        printf(" %d ",*(apV+j));
    }
}
