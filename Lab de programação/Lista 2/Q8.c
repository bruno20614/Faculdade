int main(int argc, char const *argv[])
{   
    float mercadoria, entrada = 0, prestacoes = 0;
    puts("Insira o valor da mercadoria");
    scanf("%f",&mercadoria);
    entrada = ceil((mercadoria - (mercadoria/3))/2);
    prestacoes = round(mercadoria - entrada)/2;
    printf("A entrada foi de:%.02f\n",entrada);
    printf("Duas parcelas de:%.02f vezes\n",prestacoes);
    

    return 0;
}
