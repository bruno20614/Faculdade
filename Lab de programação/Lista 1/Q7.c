#include<stdio.h>
    int main(){
int horas,segundo,minuto;
      printf("Digite as horas \n");
      scanf("%d",&horas);
      printf("Digite os minutos \n");
      scanf("%d",&minuto);
      printf("Digite as horas \n");
      scanf("%d",&segundo);
      printf("O total de segundos é:%d",(horas*3600)+(minuto*60)+segundo);
return 0;  
}
