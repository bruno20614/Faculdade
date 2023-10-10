#include <stdio.h>
#include <stdlib.h>
#define TAM 15
int main(){
    int a, maior=0, menor=0;
    float Notas[TAM];

    printf("digite 15 notas");
    printf("\n");
    for (a=0;a<TAM;a++){
      printf("nota %d : ", a+1);
      scanf("%f", &Notas[a]);
      if(a==0){maior=Notas[a];menor=Notas[a];}
      if(Notas[a]>maior){
        maior=Notas[a];
      }
      else{
        if(Notas[a]<menor){
            menor=Notas[a];
        }
      }
    }
    printf("\no maior valor é %d\n", maior);
    printf("\ne o menor valor é %d\n\n", menor);
    return 0;
}
