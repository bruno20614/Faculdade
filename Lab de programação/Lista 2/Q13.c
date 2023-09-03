#include <stdio.h>

int main(void) {
  int a;
  int b;
  int T = 0;
  int i = 0;
  int somatorio = 0;
  puts("Digite dois números um intervalo A e B");
  printf("n1: ");
  scanf("%d",&a);
  printf("n2: ");
  scanf("%d",&b);

  T = (a > b ) ? (a - b) : (b - a);
  i = (a > b) ? b : a;

    while (T != 0)         
    {
        if (i % 2 == 0) {
          printf("%d é par \n",i);
            somatorio += i;
      } else printf("%d é impar \n",i);
           
        
          i++;
          T--;
    }
  printf("O somatorio de todos os numeros pares entre: %d e %d foi: %d",a,b,somatorio);
  return 0;
}
