#include <stdio.h>
#include <stdlib.h>

// Estrutura para armazenar informações sobre ferramentas
struct Ferramenta {
    char nome[50];
    int quantidade;
    float custo;
};

// Função para inicializar o arquivo "hardware.dat" com registros vazios
void inicializarArquivo() {
    FILE *file = fopen("hardware.dat", "wb");
    if (file != NULL) {
        struct Ferramenta vazio = {"", 0, 0.0};
        for (int i = 0; i < 100; i++) {
            fwrite(&vazio, sizeof(struct Ferramenta), 1, file);
        }
        fclose(file);
    } else {
        printf("Não foi possível abrir o arquivo.\n");
        exit(1);
    }
}

// Função para listar todas as ferramentas
void listarFerramentas() {
    FILE *file = fopen("hardware.dat", "rb");
    if (file != NULL) {
        struct Ferramenta ferramenta;
        int i = 0;

        while (fread(&ferramenta, sizeof(struct Ferramenta), 1, file) == 1) {
            if (ferramenta.nome[0] != '\0') {
                printf("#%d - Nome: %s | Quantidade: %d | Custo: %.2f\n", i, ferramenta.nome, ferramenta.quantidade, ferramenta.custo);
            }
            i++;
        }

        fclose(file);
    } else {
        printf("Não foi possível abrir o arquivo.\n");
    }
}

// Função para inserir dados de uma ferramenta
void inserirFerramenta(int numeroRegistro) {
    FILE *file = fopen("hardware.dat", "rb+");
    if (file != NULL) {
        struct Ferramenta ferramenta;

        printf("Digite o nome da ferramenta: ");
        scanf("%s", ferramenta.nome);

        printf("Digite a quantidade: ");
        scanf("%d", &ferramenta.quantidade);

        printf("Digite o custo: ");
        scanf("%f", &ferramenta.custo);

        fseek(file, numeroRegistro * sizeof(struct Ferramenta), SEEK_SET);
        fwrite(&ferramenta, sizeof(struct Ferramenta), 1, file);

        fclose(file);
    } else {
        printf("Não foi possível abrir o arquivo.\n");
    }
}

// Função para excluir uma ferramenta
void excluirFerramenta(int numeroRegistro) {
    FILE *file = fopen("hardware.dat", "rb+");
    if (file != NULL) {
        struct Ferramenta vazio = {"", 0, 0.0};

        fseek(file, numeroRegistro * sizeof(struct Ferramenta), SEEK_SET);
        fwrite(&vazio, sizeof(struct Ferramenta), 1, file);

        fclose(file);
    } else {
        printf("Não foi possível abrir o arquivo.\n");
    }
}

int main() {
    // Inicializa o arquivo com 100 registros vazios
    inicializarArquivo();

    int opcao, numeroRegistro;

    do {
        // Menu
        printf("\n----- Menu -----\n");
        printf("1. Listar todas as ferramentas\n");
        printf("2. Inserir dados de uma ferramenta\n");
        printf("3. Excluir uma ferramenta\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                // Listar todas as ferramentas
                listarFerramentas();
                break;

            case 2:
                // Inserir dados de uma ferramenta
                printf("Digite o número do registro para inserir ou atualizar: ");
                scanf("%d", &numeroRegistro);
                inserirFerramenta(numeroRegistro);
                break;

            case 3:
                // Excluir uma ferramenta
                printf("Digite o número do registro para excluir: ");
                scanf("%d", &numeroRegistro);
                excluirFerramenta(numeroRegistro);
                break;

            case 4:
                // Sair
                printf("Programa encerrado.\n");
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}
