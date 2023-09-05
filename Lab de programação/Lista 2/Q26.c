#include <stdio.h>

int binario(int x){
  return (x == 0) ? 0: (binario(x/2)*10) | (x%2);
}
int main()
{
    for (int i = 0; i < 256; i++)
    {
        printf("%d em binario: %d, em octal: %o, em hexadecimal: %x\n",i,binario(i),i,i);
    }
    return 0;
}
