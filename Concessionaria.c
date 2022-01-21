#include <stdio.h>
#include <stdlib.h>

    /*Struct do proprietario do carro: numCelular é o número de celular do proprietário,
    identificador é uma chave de identificação para ligar o proprietário aos seus respectivos carros,
    logo todos os carros pertencentes ao mesmo proprietário terão a mesma chave de identificação*/
  typedef struct proprietario
  {
  char nomeCompleto[70];
  char cpf[11];
  char rg[7];
  char numCelular[13];
  int identificador;
  int quantidadeCarros;
  }Proprietario;
  
    /*Struct do carro: identificador é a mesma chave de identificação que o propietário do(s) carro(s) tem.*/
  typedef struct carro 
  {
  char modelo[25];
  char marca[25];
  char chassi[17];
  int identificador;
  }Carro;
  
  /*Cadastro das características do carro de um proprietário.*/
  void cadastroCarro(int quantidadeCarros, int id, Carro veiculo, FILE *arquivo) {
      
    for (int i = 0; i < quantidadeCarros; i ++){
        printf ("Digite o modelo do carro a ser cadastrado:\n");
        scanf ("%s", veiculo.modelo);
        
        printf ("Digite a marca do carro a ser cadastrada:\n");
        scanf ("%s", veiculo.marca);
        
        printf ("Digite o chassi do carro a ser cadastrado:\n");
        scanf ("%s", veiculo.chassi);
        
        veiculo.identificador = id;
        
        fwrite(&veiculo, sizeof(Carro), 1, arquivo);
    }
    
  }
  
  /*Cadastro das características de um proprietário de um ou mais carros*/
  void cadastroProprietario(Proprietario pessoa, Carro veiculo, FILE *arquivo, int id) {
    printf ("Digite o nome completo da pessoa a ser cadastrada:\n");
    scanf ("%s", pessoa.nomeCompleto);

    printf ("Digite o CPF da pessoa a ser cadastrada:\n");
    scanf ("%s", pessoa.cpf);

    printf ("Digite o RG da pessoa a ser cadastrada:\n");
    scanf ("%s", pessoa.rg);

    printf ("Digite o numero de celular da pessoa a ser cadastrada:\n");
    scanf ("%s", pessoa.numCelular);
    
    pessoa.identificador = id;

    printf ("Digite a quantidade de carros a serem cadastrados no nome de %s:\n", pessoa.nomeCompleto);
    scanf ("%d", &pessoa.quantidadeCarros);
    
    fwrite(&pessoa, sizeof(Proprietario), 1, arquivo);
    
    cadastroCarro(pessoa.quantidadeCarros, pessoa.identificador, veiculo, arquivo);
  }

int main() {

    /*Criacao da variavel que criara um dados.bin*/
  FILE *arquivo;

  Proprietario pessoa;
  Carro veiculo;

  /*Abre o arquivo .bin para editar ou caso nao exista cria um*/
  arquivo = fopen("dados.bin", "ab");

    /*Condicao para caso o arquivo nao abra*/
  if(arquivo == NULL)
  {
    printf("Erro na abertura do arquivo!");
    return 0;
  }
  
  /*variavel que significa a opcao no menu apertado pelo usuario*/
  int opcao;
  
  /*Funcionara como um contador para que sempre que um proprietário e seu(s) carro(s) 
  sejam cadastrado ele somara um e nao se repetira ao longo do programa*/
  int id = 0;
  
    do {
        printf("Digite a opção desejada:\n");
        printf("1.Cadastro das características do proprietário e dos seus respectivos carros;\n");
        printf("2.Sair do programa;\n");
        
        scanf("%d", &opcao);
        
        if (opcao == 1) {
            cadastroProprietario(pessoa, veiculo, arquivo, id);
            id ++;
        }
        
    } while(opcao == 1);

    /*Fecha o arquivo dados.bin*/
    fclose(arquivo);

  return 0;

}
