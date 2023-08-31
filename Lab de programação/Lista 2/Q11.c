#include <stdio.h>
int main()
{   
    int A,B, TAM = 0, i=0;

    puts("Insira o intervalo da faixa de valores comecando de A ate B");
    scanf("%d",&A);
    scanf("%d",&B);

    TAM = (A > B) ? (A - B) : (B - A); 
    i = (A > B) ? B : A;
    
    while (TAM!=0)
    {
        (i%4 == 0) ? printf("%d e divisivel por 4. O quadrado de %d e: %d\n",i,i,(i*i)) : printf("%d nao e divisivel por 4\n",i);
        i++;
        TAM--;
    }
    
    return 0;
}
