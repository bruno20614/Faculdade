#include <stdio.h>

int main(void) {
  int F,C=10;
    while(F<212){
      F = (9 * C + 160) / 5;
        printf("%d graus Celsius convertido em Farenheit e : %d graus\n",C,F);
        C+=10;
    }
  
  return 0;
}
