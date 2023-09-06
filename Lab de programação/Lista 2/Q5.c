
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n,maior = 0,menor = 0;
    do
    {
        puts("Insira um valor para n");
        scanf("%d",&n);
        if(n ==0) continue;
        n > maior ? (maior = n) : (menor =n);
    } while (n!=0);
    printf("O maior valor fornecido foi: %d\nO menor valor fornecido foi: %d",maior,menor);
    
    return 0;
}
