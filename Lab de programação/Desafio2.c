#include <stdio.h>
#include <stdlib.h>
typedef struct BlocoLivre {
    int tamanho;
    struct BlocoLivre* proximo;
} BlocoLivre;

BlocoLivre* inicializarMemoria() {
    BlocoLivre* cabeca = malloc(sizeof(BlocoLivre));
    cabeca->tamanho = 100;
    cabeca->proximo = NULL;
    return cabeca;
}

void exibirBlocosLivres(BlocoLivre* cabeca) {
    printf("Blocos livres: ");
    while (cabeca) {
        printf("[%d] -> ", cabeca->tamanho);
        cabeca = cabeca->proximo;
    }
    printf("Fim\n");
}

int alocarBloco(BlocoLivre** cabeca, int tamanho) {
    BlocoLivre* atual = *cabeca;
    BlocoLivre* anterior = NULL;

    while (atual && atual->tamanho < tamanho) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (!atual)
        return 0;  

    if (atual->tamanho == tamanho) {
        if (!anterior)
            *cabeca = atual->proximo;
        else
            anterior->proximo = atual->proximo;
    } else {
        BlocoLivre* novoBloco = malloc(sizeof(BlocoLivre));
        novoBloco->tamanho = tamanho;
        novoBloco->proximo = atual->proximo;

        atual->tamanho -= tamanho;
        atual->proximo = novoBloco;
    }

    return 1;  
}

int main() {
    BlocoLivre* memoria = inicializarMemoria();
    int escolha, tamanho;

    do {
        exibirBlocosLivres(memoria);
        printf("Escolha o algoritmo (1 para First-Fit, 2 para Best-Fit, 0 para sair): ");
        scanf("%d", &escolha);

        if (escolha != 0) {
            printf("Informe o tamanho do bloco necessário: ");
            scanf("%d", &tamanho);

            switch (escolha) {
                case 1:
                    if (!alocarBloco(&memoria, tamanho))
                        printf("Não há espaço livre suficiente para alocar %d bytes.\n", tamanho);
                    break;
                case 2:
                  m
                    break;
                default:
                    printf("Escolha inválida. Tente novamente.\n");
            }
        }
    } while (escolha != 0);

    while (memoria) {
        BlocoLivre* proximo = memoria->proximo;
        free(memoria);
        memoria = proximo;
    }

    return 0;
}
