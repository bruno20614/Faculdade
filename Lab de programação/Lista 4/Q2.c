#include <stdio.h>

void trocarValores(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

int main() {
    int num1, num2;

    printf("Digite o primeiro número: ");
    scanf("%d", &num1);

    printf("Digite o segundo número: ");
    scanf("%d", &num2);

    printf("Valores antes da troca: num1 = %d, num2 = %d\n", num1, num2);

    trocarValores (&num1, &num2);

    printf("Valores depois da troca: num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}
