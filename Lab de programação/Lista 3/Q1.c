#include <stdio.h>

int main() {
    float vetor[15];
    float menor, maior;

    for (int i = 0; i < 15; i++) {
        printf("Digite o %dº elemento: ", i + 1);
        scanf("%f", &vetor[i]);
    }

    menor = vetor[0];
    maior = vetor[0];

    for (int i = 1; i < 15; i++) {
        if (vetor[i] < menor) {
            menor = vetor[i];
        }
        if (vetor[i] > maior) {
            maior = vetor[i];
        }
    }

    float soma = menor + maior;
    printf("A soma do menor elemento (%.2f) e do maior elemento (%.2f) é: %.2f\n", menor, maior, soma);

    return 0;
}

