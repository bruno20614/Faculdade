#include <stdio.h>
#include <string.h>

int main() {
    char string1[100], string2[100];
    printf("Digite a primeira string: ");
    scanf("%s", string1);

    printf("Digite a segunda string: ");
    scanf("%s", string2);

    char resultado1[200];
    strcpy(resultado1, string1);  // Copia a primeira string para o resultado1
    strcat(resultado1, string2);  // Concatena a segunda string a resultado1

    printf("Usando strcat(): %s\n", resultado1);

    char resultado2[200];
    int i, j;

    for (i = 0; string1[i] != '\0'; i++) {
        resultado2[i] = string1[i];
    }

    for (j = 0; string2[j] != '\0'; j++) {
        resultado2[i + j] = string2[j];
    }

    resultado2[i + j] = '\0';  // Adiciona o caractere nulo para indicar o final da string
    printf("Sem usar strcat(): %s\n", resultado2);
    return 0;
}
