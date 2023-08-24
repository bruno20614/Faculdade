#include <stdio.h>

int main()
{   
    int num, part;

    printf("Digite um numero: ");
    scanf("%d", &num);

    if(num >= 0){
       do {
           part = num % 10;
           printf("%d", part);
           num /= 10;
       }while (num != 0);

    }
    else if(num < 1){
        num *= -1;

        printf("-");
        do{
            part = num % 10;
           printf("%d", part);
           num /= 10;
       }while (num != 0);
    }
    return 0;
}
