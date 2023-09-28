#include <stdio.h>
#include <stdlib.h>
#include <time.h>
unsigned char resultado;

void imprimirBinario(int n){
        int r = 0;
         for(int i = 7; i >= 0; i--) {

            r = n  >> i;

            if(r & 1) {
                printf("1");
            } else {
                printf("0");
            }
        }
          printf(", ");   
}

unsigned char pegandoBit(int aleatorio,  unsigned char armarios, int segundaVez){
    unsigned char armarioElemento;
    armarioElemento = armarios >> aleatorio;
    armarioElemento = armarioElemento << 7;
    armarioElemento = armarioElemento >> 7;
  
    
    if(segundaVez){
         taOcupado(armarioElemento, armarios, aleatorio);
         return 0;
    }

   return armarioElemento;
}

unsigned char DesacupandoOuOcupando( unsigned char armarios, int aleatorio, unsigned char Desacupar){
        unsigned char armarioElemento;
    
        armarioElemento = 0b00000001;
        armarioElemento = armarioElemento << aleatorio;

        //se a pessoa digitar que quer desocupar o armario em uma posição
        if(Desacupar){

            if(!(pegandoBit(aleatorio, armarios, 0))){
                
                printf("Armario ja está desocupado: \n");
                printf(" \n");
                resultado = armarios;
                return armarios;
            };
            
            printf("O armario %d  foi desacupado: \n", aleatorio);
            armarios = armarios ^ armarioElemento;
            imprimirBinario(armarios);
            resultado = armarios;

            return armarios;
        }
        armarios = armarios | armarioElemento;
   
        imprimirBinario(armarios);
        printf(" \nO seu armario está na posição %d nos numeros acima", aleatorio);
        printf("\n");

        resultado = armarios;
        return armarios;
    
}

// verificando se Ta ocupado
 void taOcupado(  unsigned char armarioElemento, unsigned char armarios, int aleatorio ){
    unsigned char armariosResultado;
     if(!(armarioElemento && 1)){
          armariosResultado = DesacupandoOuOcupando(armarios, aleatorio, 0);
    } else{
         
        aleatorio = aleatorio < 7 ? aleatorio: -1;
        pegandoBit(aleatorio+1, armarios, 1);
    }
    
}

int main(){
    // armarios
    unsigned char armarios = 0b01111111;
    int comando;
    unsigned char auxArmario;
    int armario;

    for( ; ; ){

          if(armarios == 255){
            printf("Todos os armarios estão ocupado: \n");
    
            printf("Digite que posição você quer desacupar: \n");
            armario = getchar();
            scanf("%d", &armario);

            DesacupandoOuOcupando(armarios, (int)armario, 2);
            armarios = resultado;
            continue;
        }
     
        printf("\n");
        printf("SISTEMA DE ARMARIOS: \n ");
        printf(" \n");
        printf("O que você quer fazer ?: \n");
        printf("Digite [1] para ocupar um armario \n");
        printf("Digite [2] para desocupar um armario \n");
        printf("Digite [3] para sair do programa\n");
        scanf("%d", &comando);
        
        if(comando == 2){
            printf("Digite que posição você quer desacupar: \n");
            armario = getchar();
            scanf("%d", &armario);

            DesacupandoOuOcupando(armarios, (int)armario, 2);
            armarios = resultado;
            continue;
        } else if( comando > 7){
            printf("Somente temos os  armarios de 0 até 7: \n");
            printf("O armario digitado não existe \n");
            continue;
        } else if( comando == 3){
            break;
        }
        srand((unsigned)time(NULL));
        armario = rand() % 7;
        printf("\n");
        
        auxArmario = pegandoBit(armario, armarios, 0);
        taOcupado(auxArmario, armarios, armario);
        printf("\n");
        armarios = resultado;
    }  
    return 0;
}
