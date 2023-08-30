#include <stdio.h>

int main() {
    int num1,num2,resultado;
  puts("Digite um valor");
  scanf("%d",&num1);
  puts("Digite um valor");
  scanf("%d",&num2);
    while (num2==0){
      puts("Digite o segundo número");
      scanf("%d",&num2);
      break;
    }
    resultado=num1/num2;
    printf("resultado %d \n",resultado);
return 0;
           }
