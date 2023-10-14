#include <stdio.h>

void copiarString(char *destino, const char *origem) {
    while (*origem != '\0') {
        *destino = *origem;
        destino++;
        origem++;
    }
    *destino = '\0'; 
}

int main() {
    char origem[100];
    char destino[100];

    printf("Digite uma string de origem: ");
    scanf("%s", origem);

    copiarString(destino, origem);

    printf("A string de destino copiada é: %s\n", destino);

    return 0;
}
