#include <stdio.h>

int main() {
 int voto=0,voto_paulo=0,voto_renata=0,voto_total=0,voto_nulo=0,voto_branco=0;
  while (voto >= 0){
    puts("Digite um número");
    scanf("%d",&voto);  
 if (voto < 0){
    voto_total = voto_paulo + voto_renata + voto_nulo + voto_branco;
    float porcent_paulo = (float)voto_paulo/voto_total*100; 
    float porcent_renata = (float)voto_renata/voto_total*100;
    float porcent_branco = (float)voto_branco/voto_total*100;
    float porcent_nulo = (float)voto_nulo/voto_total*100;
    printf("==============================================\n");
    printf("Total de votos: %d\n",voto_total);
    printf("Total de votos em Paulo: %.1f %%\n",porcent_paulo);
    printf("Total de votos em Renata: %.1f %%\n",porcent_renata);
    printf("Total de votos em Branco: %.1f %%\n",porcent_branco);
    printf("Total de votos nulos: %.1f %%\n",porcent_nulo);

        if (voto_renata>voto_paulo){
          printf("RENATA GANHOU AS ELEIÇÕES!!\n");
        } else if (voto_renata<voto_paulo){
          printf("PAULO GANHOU AS ELEIÇÕES!!\n");
        } else if (voto_paulo == voto_renata){
          printf("AS ELEIÇÕES EMPATARAM!!\n");
        }
  break;
  }  
    switch (voto){
    case 5:
    voto_paulo = voto_paulo + 1;
    printf("Você votou no Paulo!\n");
    break;
    case 7:
    voto_renata = voto_renata + 1;
    printf("Você votou na Renta!\n");
    break;
    case 0:
    voto_branco = voto_branco + 1;
    printf("Você votou em Branco!\n");
    break;
    default:
    voto_nulo = voto_nulo + 1;
    printf("Você Anulou o voto!\n");
  }
}
return 0;
}



#include <stdio.h>

int main() {
    int num1,num2,resultado;
  puts("Digite um valor");
  scanf("%d",&num1);
  puts("Digite um valor");
  scanf("%d",&num2);
    while (num2==0){
      puts("Digite o segundo número");
      scanf("%d",&num2);
      break;
    }
    resultado=num1/num2;
    printf("resultado %d \n",resultado);
return 0;
           }
