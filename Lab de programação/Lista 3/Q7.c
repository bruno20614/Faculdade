#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    srand(time(NULL));

    int vetor[3];
    for (int i = 0; i < 3; i++) {
        vetor[i] = rand() % 20; // Gera um número entre 0 e 19
    }

    int soma = 0;
    for (int i = 0; i < 3; i++) {
        soma += vetor[i];
    }
    float mediaAritmetica = (float)soma / 3;

    float produto = 1.0;
    for (int i = 0; i < 3; i++) {
        produto *= vetor[i];
    }
    float mediaGeometrica = pow(produto, 1.0 / 3);

    printf("Vetor gerado: [%d, %d, %d]\n", vetor[0], vetor[1], vetor[2]);
    printf("Média Aritmética: %.2f\n", mediaAritmetica);
    printf("Média Geométrica: %.2f\n", mediaGeometrica);

    return 0;
}
