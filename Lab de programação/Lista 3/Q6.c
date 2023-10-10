#include <stdio.h>
#include <string.h>

int main() {
    char entrada[100];

    printf("Digite uma string: ");
    scanf("%s", entrada);

    int comprimento = strlen(entrada);

    printf("String na forma inversa: ");
    
    for (int i = comprimento - 1; i >= 0; i--) {
        printf("%c", entrada[i]);
    }

    printf("\n");

    return 0;
}
