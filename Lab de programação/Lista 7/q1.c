#include <stdio.h>

  struct Usuario{
  char nome[50];
  int idade;
  char email[50];

  };

int main(void){
    FILE *file=fopen("usuario.csv","w");


  if(file != NULL){
    fprintf(file,"nome,idade,email \n");
    
    struct Usuario usuario;
    char continuar;
  
    do{

      puts("Digite o nome do usuário");
      scanf("%s",usuario.nome);

      puts("Digite a idade do usuário");
      scanf("%d",&usuario.idade);

      puts("Digite o email do usuário");
      scanf("%s",usuario.email);

      fprintf(file,"%s,%d,%s",usuario.nome,usuario.idade,usuario.email);

      puts("Deseja adicionar outro usuário?");
      scanf(" %c", &continuar);
    }while (continuar == 'S' || continuar == 's');

    fclose(file);
    printf("Dados gravados com sucesso");

    }else{

      puts("Não foi possivel abrir o arquivo");
    }

  return 0;
}
