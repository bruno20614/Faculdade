#include <stdio.h>

int tamanhoDaString(const char *str) {
    const char *p = str; 
    while (*p != '\0') {
        p++; 
    }
    return p - str; 
}

int main() {
    char minhaString[100]; 

    printf("Digite uma string: ");
    scanf("%s", minhaString);

    int tamanho = tamanhoDaString(minhaString);

    printf("O tamanho da string é: %d\n", tamanho);

    return 0;
}
