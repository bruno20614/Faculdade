#include <stdio.h>

int main() {
   int n,fat;
  while( 1){
  printf("Digite um número \n");
  scanf("%d",&n);
    for(fat = 1; n > 1; n = n - 1)
  {      
      fat = fat * n;
  }
  printf("O valor em fatorial é %d \n",fat);
                }
  return 0;
            }
