#include <stdio.h>
#define TAM 75

int main(int argc, char const *argv[])
{
    for (int i = 0; i < TAM; i++)
    {
        (i%4 == 0) ? printf("%d e divisivel por 4. O quadrado de %d e: %d\n",i,i,(i*i)) : printf("%d nao e divisivel por 4\n",i);
    }
    return 0;
}
