#include <stdio.h>
#define TAM 10
  int fat(int n){
      return(n==0) ? 1 : (fat(n-1)*n);
      
  }
  int main (){
    for(int i=1; i<=TAM;i++){

      (i%2) ? printf("O fatorial de %d e: %d \n",i,fat(i)) : printf("%d e par\n",i);
    }
    return 0;
  }
