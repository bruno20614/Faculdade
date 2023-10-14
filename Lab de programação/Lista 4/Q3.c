#include <stdio.h>

int main() {
    int numero;
    int menor;
    int *p_menor = &menor; 
    int criterio = 0;
  
    menor = 2147483647;

    while (1) {
        printf("Digite um número (para encerrar, digite %d): ", criterio);
        scanf("%d", &numero);

        if (numero == criterio) {
            printf("Programa encerrado.\n");
            break;
        }

        if (numero < *p_menor) {
            *p_menor = numero; 
        }

        printf("Menor valor até agora: %d\n", *p_menor);
    }

    return 0;
}
