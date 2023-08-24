#include <stdio.h>

int main()
{   
    int num1,num2;
    printf("Digite um numero: ");
    scanf("%d", &num1);

    printf("Digite outro numero: ");
    scanf("%d", &num2);
  
    num1 >= num2 && num1 % num2 == 0 ? printf("E multiplo !") : printf("Nao e multiplo !");

    return 0;
}
