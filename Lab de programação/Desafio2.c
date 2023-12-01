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

int alocarBlocoBestFit(BlocoLivre** cabeca, int tamanho) {
    BlocoLivre* atual = *cabeca;
    BlocoLivre* anterior = NULL;
    BlocoLivre* melhorAjuste = NULL;

    while (atual) {
        if (atual->tamanho >= tamanho && (!melhorAjuste || atual->tamanho < melhorAjuste->tamanho)) {
            melhorAjuste = atual;
            anterior = anterior;
        }
        anterior = atual;
        atual = atual->proximo;
    }

    if (!melhorAjuste)
        return 0;  

    if (melhorAjuste->tamanho == tamanho) {
        if (!anterior)
            *cabeca = melhorAjuste->proximo;
        else
            anterior->proximo = melhorAjuste->proximo;
    } else {
        BlocoLivre* novoBloco = malloc(sizeof(BlocoLivre));
        novoBloco->tamanho = tamanho;
        novoBloco->proximo = melhorAjuste->proximo;

        melhorAjuste->tamanho -= tamanho;
        melhorAjuste->proximo = novoBloco;
    }

    return 1; 
}

int alocarBlocoFirstFit(BlocoLivre** cabeca, int tamanho) {
    BlocoLivre* atual = *cabeca;
    BlocoLivre* anterior = NULL;

    while (atual) {
        if (atual->tamanho >= tamanho) {
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
        anterior = atual;
        atual = atual->proximo;
    }

    return 0;  
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
                    if (!alocarBlocoFirstFit(&memoria, tamanho))
                        printf("Não há espaço livre suficiente para alocar %d bytes usando First-Fit.\n", tamanho);
                    break;
                case 2:
                    if (!alocarBlocoBestFit(&memoria, tamanho))
                        printf("Não há espaço livre suficiente para alocar %d bytes usando Best-Fit.\n", tamanho);
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
