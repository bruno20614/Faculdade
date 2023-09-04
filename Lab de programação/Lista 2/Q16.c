#include <stdio.h>
#include <stdbool.h>
#define TAM 100 
  bool verificarDivisivelPorTres(int n){
    return (n%==0) ? true : false   
  }
  bool verificarDivisivelPorCinco(int n){
    return(n%5==0) ? true : false;
  }
  int main(){
    int somatorioTres = 0;
    int somatorioCinco = 0;
    for(int i=0; i<TAM;i++){
        somatorioTres += verifcarDivisivelPorTres(i) ? i : 0;
        somatorioCinco += verifcarDivisivelPorCinco(i) ? i+100 : 0;   
    }
     printf("O somatorio de todos os numeros divisiveis por 3 pertencentes ao intervalo:0, 100         e:%d\n",somatorioTres);   
     printf("O somatorio de todos os numeros divisiveis por 5 pertencentes ao intervalo:100, 200       e:%d",somatorioCinco);
      return 0;
  }
