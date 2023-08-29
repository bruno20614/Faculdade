#include <stdio.h>
  int main(){
    int pedro_altura=110;
    int jose_altura=150;
    int pedro_cresc=3;
    int jose_cresc=2;
    int ano=0;
      while(pedro_altura<jose_altura){
        pedro_altura += pedro_cresc;
        jose_altura  += jose_cresc;
        ano++;
                                     }
        printf("Pedro ultrapassa josé em %d anos \n",ano);

         return 0;
            }
