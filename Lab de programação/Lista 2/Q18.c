#include <stdio.h>
#define  TAM 64
int main(void) {
  
  long double somatorio=1,inicio=1;
  for(int i=1;i<=TAM;i++){

    inicio = inicio*2;
      somatorio+=inicio;
  }
     printf("o resultado é %Lf \n",somatorio);
  return 0;
}
