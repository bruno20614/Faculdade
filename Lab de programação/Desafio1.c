#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    char armarios[8];
    int opcao, armario, i;
    srand(time(NULL));
    for(i = 0; i < 8; i++){
        armarios[i] = 0;
    }
    do{
        printf("\n1. Ocupar armario\n2. Liberar armario\n3. Sair\n");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                armario = rand() % 8;
                armarios[armario] = 1;
                break;
            case 2:
                printf("Digite o armario: ");
                scanf("%d", &armario);
                armarios[armario] = 0;
                break;
            case 3:
                break;
            default:
                printf("Opcao invalida\n");
        }
        for(i = 0; i < 8; i++){
            if(armarios[i] == 0){
                printf("Armario %d: Livre\n", i);
            }else{
                printf("Armario %d: Ocupado\n", i);
            }
        }
    }while(opcao != 3);
    return 0;
}

