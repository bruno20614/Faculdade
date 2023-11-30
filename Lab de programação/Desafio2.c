#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um bloco de memória livre
typedef struct FreeBlock {
    int size;
    struct FreeBlock* next;
} FreeBlock;

// Função para inicializar a lista de espaços livres com uma configuração inicial
FreeBlock* initializeMemory() {
    // Aqui, você pode inicializar a lista de espaços livres conforme necessário.
    // Por exemplo, criar uma lista com alguns blocos de tamanhos diferentes.
    FreeBlock* head = (FreeBlock*)malloc(sizeof(FreeBlock));
    head->size = 100;  // Tamanho inicial da memória
    head->next = NULL;

    return head;
}

// Função para exibir a lista de espaços livres
void displayFreeBlocks(FreeBlock* head) {
    FreeBlock* current = head;

    printf("Espaços livres: ");
    while (current != NULL) {
        printf("[%d] -> ", current->size);
        current = current->next;
    }
    printf("Fim\n");
}

// Algoritmo First-Fit para alocar memória
int allocateFirstFit(FreeBlock** head, int size) {
    FreeBlock* current = *head;
    FreeBlock* prev = NULL;

    while (current != NULL) {
        if (current->size >= size) {
            // Encontrou um bloco grande o suficiente
            if (current->size == size) {
                // O bloco é exatamente do tamanho necessário
                if (prev == NULL) {
                    // Remover o bloco do início
                    *head = current->next;
                } else {
                    // Remover o bloco do meio ou final
                    prev->next = current->next;
                }
            } else {
                // Dividir o bloco em dois, alocando o necessário
                FreeBlock* newBlock = (FreeBlock*)malloc(sizeof(FreeBlock));
                newBlock->size = size;
                newBlock->next = NULL;

                current->size -= size;
                newBlock->next = current->next;
                current->next = newBlock;
            }

            return 1;  // Alocado com sucesso
        }

        prev = current;
        current = current->next;
    }

    return 0;  // Não há espaço suficiente
}

// Algoritmo Best-Fit para alocar memória
int allocateBestFit(FreeBlock** head, int size) {
    // Implemente o algoritmo Best-Fit aqui

    return 0;  // Temporário - substitua pela lógica real
}

// Função principal
int main() {
    FreeBlock* memory = initializeMemory();
    int choice, size;

    do {
        displayFreeBlocks(memory);
        printf("Escolha o algoritmo (1 para First-Fit, 2 para Best-Fit, 0 para sair): ");
        scanf("%d", &choice);

        if (choice != 0) {
            printf("Informe o tamanho do bloco necessário: ");
            scanf("%d", &size);

            switch (choice) {
                case 1:
                    if (!allocateFirstFit(&memory, size)) {
                        printf("Não há espaço livre suficiente para alocar %d bytes.\n", size);
                    }
                    break;
                case 2:
                    // Implemente chamada para alocar usando Best-Fit
                    break;
                default:
                    printf("Escolha inválida. Tente novamente.\n");
            }
        }
    } while (choice != 0);

    // Libera a memória restante na lista de espaços livres
    FreeBlock* current = memory;
    while (current != NULL) {
        FreeBlock* next = current->next;
        free(current);
        current = next;
    }

    return 0;
}
