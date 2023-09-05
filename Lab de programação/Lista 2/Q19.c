#include <stdio.h>
  int main(){
      int A, B,total=0;
      float media=0;
     puts("Digite dois números");
     scanf("%d",&A);
     scanf("%d",&B);

       total = (A > B) ? (A - B) : (B - A);
    
    for (int i=0;i<total;i++){
      
        media+=i;
    }
    printf("A média de %d e %d é : %.2f",A,B,(media/total));
    return 0;
  }
