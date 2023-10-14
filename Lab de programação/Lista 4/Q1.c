#include <stdio.h>

int main(void) {
  int num1= 15;
  int num2 = 10;

 int *pnum1= &num1;
  int *pnum2= &num2;

  int soma = *pnum1 + *pnum2;
  int *psoma = &soma;
  
  printf("O valor da soma de %d e %d é: %d\n", *pnum1, *pnum2, soma);
  
  printf("O endereço de memoria é %d",&soma);
  return 0;
}
