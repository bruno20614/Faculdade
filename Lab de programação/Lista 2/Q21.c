#include <stdio.h>

int main() {
    char num[5];
    
    puts("Digite um palíndromo ");
    fgets(num, 6, stdin);
    fflush(stdin);

    if (num[0] == num[4] && num[1] == num[3]) {
        puts("É um Palíndromo!");
    } else {
        puts("Não é um Palíndromo.");
    }    

    return 0;
}
