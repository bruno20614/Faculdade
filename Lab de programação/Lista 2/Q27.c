#include <stdio.h>

int main( ){
  int maior,menor,num,cont=0;
  while(1){
    puts("Digite um número");
    scanf("%d",&num);

    if (num < 0 && num % 2 == 0){

         break;
    }
    if (cont==0|| num>maior){
       maior=num;
    }
    if (cont==0|| num<menor){
       menor=num;
    }
    
    cont++;
         }
           printf("O resultado é %d \n",(maior*menor));
  return 0;
  
         } 
