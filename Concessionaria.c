#include <stdio.h>
#include <stdlib.h>

int main() {

    /*Criacao da variavel que criara um arquivo .txt*/
  FILE *arquivo;

    /*Struct do proprietario do carro*/
  struct proprietario
  {
  char nomeCompleto[100];
  char cpf[100];
  char rg[100];
  char cel[100];
  int quantidadeCarros;
  };

    /*Struct do carro*/
  struct carro {
  char nome[100];
  };

  struct proprietario pessoa[20];
  struct carro veiculo[100];

    /*Cariaveis de auxilio em loops e condicoes*/
  int nP, nC, p = 0, i = 0, u = 0;

    /*Abre o arquivo .txt para editar ou caso nao exista cria um*/
  arquivo = fopen("dados.txt", "ab");

    /*Condicao para caso o arquivo nao abra*/
  if(arquivo == NULL)
  {
  printf("Erro na abertura do arquivo!");
  return 0;
  }

    /*Cadastro de dados*/
  printf("Digite a quantidade de pessoas a serem cadastradas:\n");
  scanf ("%d", &nP);

  for (i = 0; i < nP; i ++) {
    printf ("Digite o nome completo da %d° pessoa a ser cadastrada:\n", i + 1);
    scanf ("%s", pessoa[i].nomeCompleto);
    printf ("Digite o CPF da pessoa a ser cadastrada:\n");
    scanf ("%s", pessoa[i].cpf);
    printf ("Digite o RG da pessoa a ser cadastrada:\n");
    scanf ("%s", pessoa[i].rg);
    printf ("Digite o numero de celular da pessoa a ser cadastrada:\n");
    scanf ("%s", pessoa[i].cel);
    printf ("Digite a quantidade de carros a serem cadastrados no nome de %s:\n", pessoa[i].nomeCompleto);
    scanf ("%d", &pessoa[i].quantidadeCarros);

    for (u = 0; u < pessoa[i].quantidadeCarros; u ++) {
      printf ("Digite o nome do %d° carro do/a %s a ser cadastrada:\n", u + 1, pessoa[i].nomeCompleto);
      scanf ("%s", veiculo[p].nome);
      p ++;
    }
  }

  p = 0;
  i = 0;
  u = 0;

    /*Printa os dados criados anteriormente na tela e os adiciona ao arquivo .txt*/
  for (i = 0; i < nP; i ++) {
    printf ("Nome completo:\t%s\n", pessoa[i].nomeCompleto);
    fprintf(arquivo, "%s", "Nome Completo: ");
    fwrite(pessoa[i].nomeCompleto, sizeof (char), 100, arquivo);
    fprintf(arquivo, "%s", "\n");

    printf ("CPF:\t%s\n", pessoa[i].cpf);
    fprintf(arquivo, "%s", "CPF: ");
    fwrite(pessoa[i].cpf, sizeof (char), 100, arquivo);
    fprintf(arquivo, "%s", "\n");

    printf ("RG:\t%s\n", pessoa[i].rg);
    fprintf(arquivo, "%s", "RG: ");
    fwrite(pessoa[i].rg, sizeof (char), 100, arquivo);
    fprintf(arquivo, "%s", "\n");

    printf ("Numero de celular:\t%s\n", pessoa[i].cel);
    fprintf(arquivo, "%s", "Numero de Celular: ");
    fwrite(pessoa[i].cel, sizeof (char), 100, arquivo);
    fprintf(arquivo, "%s", "\n");

    printf ("Quantidade de carros:\t%d\n", pessoa[i].quantidadeCarros);
    fprintf(arquivo, "%s", "Quantidade de carros: ");
    fprintf(arquivo, "%d", pessoa[i].quantidadeCarros);
    fprintf(arquivo, "%s", "\n");

    printf ("Carro(s):");

    for (u = 0; u < pessoa[i].quantidadeCarros; u ++){
      fprintf(arquivo, "%s", "Carro: ");
      printf ("\t%s", veiculo[p].nome);
      fwrite(veiculo[p].nome, sizeof (char), 100, arquivo);
      fprintf(arquivo, "%s", "\n");
      p ++;
    }
    printf ("\n");
    fprintf(arquivo, "%s", "\n");
    printf("------------------------------\n");
  }

    /*Fecha o arquivo .txt*/
  fclose(arquivo);

  return 0;
}
