#include <stdio.h>

int main()
{   
    int n;
     int i;
    puts("Insira o numero para consultar sua tabuada");
    scanf("%d",&n);
    for (i = 0; i < 10; i++) printf("%d x %d = %d \n",n,i,(n*i));
    return 0;
}
