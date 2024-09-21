#include <stdio.h>
#include <stdlib.h>

void imprime(char);
int main()
{
    char letra= ' ';
    int x;

   imprime(letra);

    return 0;
}
void imprime(char letra)
{
  if (letra=='.')
       return ;
  else
{
      printf("\n Dame letra");
      fflush(stdin);
      scanf("%c",&letra);
      imprime (letra);
      printf("%c",letra);
}
}
