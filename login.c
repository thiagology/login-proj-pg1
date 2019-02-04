#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <locale.h>




//ESTRUTURAS

//p/ criação de usuario
typedef struct usuario USER;
struct usuario
{

char usuario[20];
char senha[20];
int perm;

};

/*Data que ser? usada para armazenar a data de venda do produto para quando estivermos fazendo o balan?o temporal. sempre que uma venda for feita a fun??o deve buscar a data no sistema e preencher essas variaveis*/
typedef struct data DATA;
struct data {
	int data;
	int hora;
	int mes;
	int ano;
};

/*no momento do cadastro o usu?rio vai declarar validade do pruduto que ser? usada em uma fun??o para checar vensimento */

typedef struct validade VALIDADE;
struct validade
{
	int dia;
	int mes;
	int ano;
};

/* struct de produtos vai var usada para gerar o estoque e na parte de vendas */

typedef struct produto PRODUTO;
struct produto
{
	char nome[20];
	int ID;
	float preco;
	DATA data;
	int quantidade;
	char tipo[15];
	VALIDADE validade;
};


//criação de funções

void usuario(); //criação do usuario
int logar(); //login
void Cabecalho(); //cabeçalho
void CadArquivo(); //cadastro
void cadastro_tipo(struct produto *prod); // tipo do produto
void cadastro_val(struct produto *prod); //validade do produto
void buscaProd(); //buscar produto
void exibeEstq(); //exibe o estoque inteiro
void buscaValidade(); //busca produtos pelo mes
void conf(char *ex);








int main()
{

//VARIAVEIS 
  int log = 0,
  fim = 0,
  perm = 0;



//PROGRAMA
  

  do //execução do programa
{
  Cabecalho();

  printf("\n1. Cadastrar Usuario\n2. Login\n");
  int op;
  scanf("%i", &op);
  getchar();
  
 if (op == 1)//cadastro
 {
  
    printf("\n*Cadastrar Usuario*\n\n ");
    
    usuario();
	system("cls");
       
 }
  else if(op == 2)//login
  {
    printf("\n\t*Login*\n");
    int chek = 0;
	do{
	

			perm = logar();
			log = 1;
			chek = 1;
            system("cls");
        	
            
            
      }while(chek == 0);
    


  }
  else
  {
      printf("\n*Opcao invalida*\n\n");
  }

}while(log == 0);

do 
{
  Cabecalho();
    printf("\n\n*****BEM VINDO(A)*****\n");

  if(perm == 1)//execução para o usuario
  {
    do
    {
      int op;
    printf("\n1. Vendas\n2. Fechar caixa\n");
    scanf("%i", &op);

      switch(op)
      {
        case 1:
        printf("\n(Função de Vendas)\n");
        break;

        case 2:
        printf("\n(Função de Lucro)");
        fim = 1;
        break;

        default:
        printf("*Opcao Invalida*\n");
      }
    
    }while(fim == 0);
  }
  else if(perm == 2)//execução para o editor
  {
    do
    {
    	Cabecalho();
      int op;
      printf("\n1. Adicionar/Remover Produtos\n2. Balanco de vendas e Lucros\n0. Sair\n");
      scanf("%i", &op);

      switch(op)
      {


        case 1:
        printf("\n");
        int opc;
            do
		    {
		      setlocale(LC_ALL, "Portuguese");
		
		      Cabecalho();
		
		        printf("\n\n1. Cadastrar produto\n2. Exibir estoque\n3. Buscar no estoque\n4. Remover Produto\n5. Produtos por Validade\n6. Sair\n\n");
		
		        scanf("%i", &opc);
		        getchar();
		
		      switch(opc)
		        {
		          case 1:
		              CadArquivo();
		          break;
		
		          case 2:
		          	exibeEstq();
		          break;
		
		          case 3:
		          	buscaProd();
		          break;
		
		          case 4:
		          break;
		
		          case 5:
		          	buscaValidade();
		          break;
		
		          case 6:
		
		          break;
		
		          default:
		          printf("\n\nOpção invalida!\n\n");
		
		          break;
		
		        };

   			 }while(opc != 6);
   			 system("cls");


        break;

        case 2:
        printf("(Função de Lucro)\n");    
        break;

        case 0:
        fim = 1;
        break;

        default:
        printf("*Opcao Invalida*\n");
      }
    
    }while(fim == 0);

  }
  else
  {
    printf("Você não tem permissao.");
    break;
  }


  while(fim == 1)
  {
    int ses = 1;
    printf("\nAperte 0 para encerrar sessao ou 1 para voltar.\n");
    scanf("%i", &ses);
    if (ses == 0)
    {
      log = 0; 
      fim = 0;
    }
    else if(ses = 1)
    {
      log = 1;
      fim = 0;
    }
    else
    {
      printf("*\nOpcao Invalida\n*");
    }
  }

}while (log == 1);



return 0;
};

//funções

void Cabecalho()
{
  system("cls");

  printf("\n\n=======================================\n");
  printf("==============NO CONTROLE==============\n");
  printf("=======================================\n\n");
};

void usuario()
{
  FILE *usuarios;
  USER user;

  usuarios = fopen("usuario1.txt", "ab");
  
  if(usuarios == NULL)
  {
  	printf("Problema da abertura do arquivo.\n");
  }
  else
  {
  	do
  	{
  		fflush(stdin);
  		printf("Digite o login: ");
  		gets(user.usuario);
  		
  		fflush(stdin);
  		printf("Digite a senha: ");
  		gets(user.senha);
  		
  		printf("Digite a permissao: ");
  		scanf("%d", &user.perm);
  		
  		fwrite(&user, sizeof(USER), 1, usuarios);
  		
  		printf("\nCadastro realizado com sucesso!\n");
  		
  		printf("Deseja fazer novo cadastro?(s/n)?\n");
  		
	}while(getche() == 's');
	fclose(usuarios);
  }
}

int logar()
{
	FILE *usuarios;
	USER user;
	char nome[30];
	char senha[30];
	int run = 0;
	int perm = 0;
	
	usuarios = fopen("usuario1.txt", "rb");
	
	if(usuarios == NULL){
		printf("Problema da abertura do arquivo.\n");
	}
	else
	{

			
		fflush(stdin);
		printf("\nDigite o nome: ");
		gets(nome);
		
		fflush(stdin);
		printf("Digite a senha: ");
		gets(senha);
		
		
			while( fread(&user, sizeof (USER), 1, usuarios) == 1)
			{
				if(strcmp(nome, user.usuario) == 0)
				{
					if(strcmp(senha, user.senha) == 0)
					{
					  printf("Login bem sucedido.\n");
						perm = user.perm;
					}
				}
			}

	}
	
	fclose(usuarios);
	
	return (perm);
}



void buscaProd()
{
  FILE *est;
  est = fopen("estoque.txt", "rb");
  PRODUTO prod;
  char produto[30];
  Cabecalho();

	  if(est == NULL)
	  {
	    printf("Erro ao abrir arquivo!");
	  }
	  else
	  {
	  	fflush(stdin);
	  	printf("Digite o produto para buscar: \n");
	  	gets(produto);
	  	while( fread(&prod, sizeof(PRODUTO), 1, est) == 1)
	  	{
	  		if(strcmp(produto, prod.nome) == 0)
	  		{
				printf("\nProduto: %s\n", prod.nome);
				printf("ID: %i\n", prod.ID);
				printf("Tipo: %s\n", prod.tipo);
				printf("Quantidade: %i\n", prod.quantidade);
				printf("Preco: %.2f\n", prod.preco);
				printf("Validade: %i/%i/%i \n", prod.validade.dia, prod.validade.mes, prod.validade.ano);
				printf("---------------------------------\n\n");
					  		
			}
		}
	  }
	fclose(est);
	getch();
}

void exibeEstq()
{
  FILE *est;
  est = fopen("estoque.txt", "rb");
  PRODUTO prod;
  Cabecalho();
  

	  if(est == NULL)
	  {
	    printf("Erro ao abrir arquivo!");
	  }
	  else
	{
		
	
	  	while( fread(&prod, sizeof(PRODUTO), 1, est) == 1)
	  	{
				printf("Produto: %s\n", prod.nome);
				printf("ID: %i\n", prod.ID);
				printf("Tipo: %s\n", prod.tipo);
				printf("Quantidade: %i\n", prod.quantidade);
				printf("Preco: %.2f\n", prod.preco);
				printf("Validade: %i/%i/%i \n", prod.validade.dia, prod.validade.mes, prod.validade.ano);
				printf("---------------------------------\n\n");	  		
		}
	  }
	fclose(est);
	getch();
}

void buscaValidade()
{
  FILE *est;
  est = fopen("estoque.txt", "rb");
  PRODUTO prod;
  Cabecalho();

	  if(est == NULL)
	  {
	    printf("Erro ao abrir arquivo!");
	  }
	  else
	  {
	  	int val;
	  	printf("Digite o mes da validade: \n");
	  	scanf("%d", &val);

	  	while( fread(&prod, sizeof(PRODUTO), 1, est) == 1)
	  	{
	  		if(val == prod.validade.mes )
	  		{
				printf("\nProduto: %s\n", prod.nome);
				printf("ID: %i\n", prod.ID);
				printf("Tipo: %s\n", prod.tipo);
				printf("Quantidade: %i\n", prod.quantidade);
				printf("Preco: %.2f\n", prod.preco);
				printf("Validade: %i/%i/%i \n", prod.validade.dia, prod.validade.mes, prod.validade.ano);
				printf("---------------------------------\n\n");
			}
		}
	  }
	fclose(est);
	getch();
}

//edson
void cadastro_char(struct produto *prod)
{
	
	
		printf("\nDigite o nome do produto!\n");
		scanf("%s", prod->nome);
			
};

void cadastro_int(struct produto *prod)
{
	
		printf("\nDigite o numero de identifica??o do produto!\n");
		scanf("%i", &prod->ID);
		
};

void cadastro_float(struct produto *prod)
{

	
		printf("\nDigite o pre?o do produto!\n");
		scanf("%f", &prod->preco);
		

};

void cadastro_val(struct produto *prod)
{

		int d,m,a = 0;

		printf("\nValidade do Produto!\n");
        printf("\nDia: \n");
		scanf("%i", &d);
    getchar();
        if(d > 0 && d < 31 )
      {
        prod->validade.dia = d;

          printf("\nMes: \n");
          scanf("%i", &m);
          getchar();
                if(m > 0 && m < 13 )
                {
                  prod->validade.mes = m;

                  printf("\nAno: \n");
                  scanf("%i", &a);
                  getchar();

                      if( a > 2018)
                      {
                        prod->validade.ano = a;
                      }
                      else
                      {
                        printf("Ano invalido!");
                      };
                }

                else
          {
            printf("\nData inv?lida!\n");
          };
                }



      else
      {
        printf("\nData inv?lida!\n");
      };

};


void conf(char *ex)
{
  char opc;

  printf("\n\n1-Encerrar cadastro\n2-Novo cadastro\n\n");
  scanf("%s", &opc);
  getchar();

  switch(opc)
  {
    case '1':

    *ex = 's';
    break;
    
    case '2':
    printf("Novo cadastro");
    *ex = 'n';
    break;

    default:
    printf("\n\nOpcao invalida!\n\n");
    break;
  };
};

void cadastro_tipo(struct produto *prod)
{

  char opc;

    printf("\nTipo de produto:\n\n1-Limpeza\n2-Cereais\n3-Massas\n4-Frios\n5-Bebidas\n6-Laticinios\n7-Frut\n\n");
    scanf("%c", &opc);
    getchar();

    switch(opc)
    {
      case '1':
      strcpy(prod->tipo, "Limpeza");
      break;

      case '2':
      strcpy(prod->tipo, "Cereais");
      break;

       case '3':
      strcpy(prod->tipo, "Massas");
      break;

       case '4':
      strcpy(prod->tipo, "Frut");
      break;

       case '5':
      strcpy(prod->tipo, "Bebidas");
      break;

       case '6':
      strcpy(prod->tipo, "Laticinios");
      break;

       case '7':
      strcpy(prod->tipo, "Verde");
      break;

      default:
      printf("\n\nOpcao invalida!\n\n");
      break;

    };

};

/*fun??o para confirmar preenchimento de campo do cadastro*/

int avancar(int *avan)
{
  int opc;
  printf("\nAvancar para proximo item?(1-Sim/n2-Nao)\n");
  scanf("%i", &opc);
  getchar();

      if(opc == 1)
      {
        *avan = 1;
        return 1;
      }
      else
      {
        printf("\n\nTente novamente!\n\n");
        return 0;
      };

  };

  void cadastro_quantidade(struct produto *prod)
{


		printf("\nDigite a quantidade: \n");
		scanf("%i", &prod->quantidade);
		
};

void CadArquivo()
{
  FILE *est;
  est = fopen("estoque.txt", "ab");
  PRODUTO prod;
  char sair;
  Cabecalho();
  int av;

  if(est == NULL)
  {
    printf("Erro ao abrir arquivo!");
  }

  else
  {
    do
    {
        //Nome

  do{
      av = 0;
      cadastro_char(&prod);
      avancar(&av);

  }while(av != 1);

		//ID

	do{
      av = 0;
      cadastro_int(&prod);
      avancar(&av);

  }while(av != 1);

		//Preço

		
  do{
      av = 0;
      cadastro_float(&prod);
      avancar(&av);

  }while(av != 1);


		//Val
do{
      av = 0;
      cadastro_val(&prod);
      avancar(&av);

  }while(av != 1);

      //Quantidade      
  do{
      av = 0;
      cadastro_quantidade(&prod);
      avancar(&av);

  }while(av != 1);

		//tipo

    do{
      av = 0;
      cadastro_tipo(&prod);
      avancar(&av);

  }while(av != 1);


        fwrite(&prod, sizeof(PRODUTO), 1, est);


        
    conf(&sair);

    }while(sair != 's');

    fclose(est);

  };
};



