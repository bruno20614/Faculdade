int binario(int x){
  return (x == 0) ? 0: (binario(x/2)*10) | (x%2);
}
#include <stdio.h>

int main(int argc, char const *argv[])
{
    unsigned char Y;
    unsigned char X;
    puts("Insira um valor para X");
    scanf("%d", &X);
    puts("Insira um valor para Y");
    scanf("%d", &Y);
    printf("X:%d \nY:%d \n",binario(X),binario(Y));
    return 0;
}
