#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>


//função de arquivos
FILE *AbrirArquivo(char s[15])
{
  FILE *p;
  p = fopen(s, "rb");
  if(p == NULL)
  {
    p = fopen(s, "wb");
  };
  return (p);
};

//usuario
typedef struct
{

char usuario[20];
char senha[20];
int perm;

}Login;

//encomenda
typedef struct{

char cliente[20];
char prazo[11];
char produto[20];

}Encomenda;

int cadEncomenda()
{
    Encomenda cadastro;
    char opcao;
    char i;
    int sair = 0;

  do
  {

  
      printf("\n\t*Encomenda*\nNome do cliente: \n")  ;
        scanf("%s", cadastro.cliente);
            getchar();


        printf("\n Prazo de entrega: \n");
        scanf("%s", cadastro.prazo);
        getchar();


        printf("\n Produto: \n");
        scanf("%s", cadastro.produto);
        getchar();    


                printf("\n\n\nNome do cliente: %s\nPrazo: %s\nProduto: %s\n", cadastro.cliente, cadastro.prazo, cadastro.produto);                                                                             
                printf("\n\nFinalizar encomenda? (s ou n)\n");
                scanf("%c", &i);
                if(i == 's')
                {
                  printf("\nEncomenda realizada com sucesso!\n");
                  sair = 1;

                }
                else if(i == 'n')
                {
                  
                }
                else
                {
                  printf("\nOpção inválida!\n");
                }

  }while (sair == 0);

}

//************FUNCÕES EDSON************
//produtos



    /*Data que será usada para armazenar a data de venda do produto para quando estivermos fazendo o balanço temporal. sempre que uma venda for feita a função deve buscar a data no sistema e preencher essas variaveis*/ 

    struct Data {
      int data;
      int hora;
      int mes;
      int ano;
    };

    /*no momento do cadastro o usuário vai declarar validade do pruduto que será usada em uma função para checar vensimento */

    struct Validade
    {
      int dia;
      int mes;
      int ano;
    };

    /* struct de produtos vai var usada para gerar o estoque e na parte de vendas */

    struct Produto
    {
      char nome[20];
      int ID;
      float preco;
      struct Data pdata;
      int quantidade;
      char tipo[15];
      struct Validade pvalidade;	
    };

    /*função para confirmar preenchimento de campo do cadastro*/

    int avancar(int *avan)
    {
      int opc;
      printf("\nAvançar para proximo item?(1-Sim/2-Nao)\n");
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



    /*Aqui eu comecei a fazer as funções para o cadastro de produtos*/

    void cadastro_char(struct Produto *prod, int *vet)
    {
      
      int cont = *vet;
      
        printf("\nDigite o nome do produto:\n");
        scanf("%s", prod[cont].nome);
          
    };

    void cadastro_int(struct Produto *prod, int *vet)
    {
      
      int cont = *vet;

        printf("\nDigite o numero de identificação do produto!\n");
        scanf("%i", &prod[cont].ID);
        
    };

    void cadastro_float(struct Produto *prod, int *vet)
    {

      int cont = *vet;
      
        printf("\nDigite o preço do produto!\n");
        scanf("%f", &prod[cont].preco);
      
    };

    void cadastro_val(struct Produto *prod, int *vet)
    {

      int cont = *vet;

        int d,m,a;

        printf("\nValidade do Produto!\n");
        printf("\nDia: \n");
        scanf("%i", &d);
          if(d > 0 && d < 31 )
          {
            prod[cont].pvalidade.dia = d;

              printf("\nMes: \n");
              scanf("%i", &m);
                
                    if(m > 0 && m < 13 )
                    {
                      prod[cont].pvalidade.mes = m;

                      printf("\nAno: \n");
                      scanf("%i", &a);

                          if( a > 2018)
                          {
                            prod[cont].pvalidade.ano = a;
                          }
                          else
                          {
                            printf("Ano invalido!");
                          };
                    }

                    else
              {
                printf("\nData inválida!\n");
              };
                    }
                    
          

          else
          {
            printf("\nData inválida!\n");
          };
        
    };

    void cadastro_quantidade(struct Produto *prod, int *vet)
    {

      int cont = *vet;

        printf("\nDigite a quantidade: \n");
        scanf("%i", &prod[cont].quantidade);
        
    };

    void cadastro_tipo(struct Produto *prod, int *vet)
    {
      
      int cont = *vet;
      char opc = '0';
          
        printf("\nTipo de produto:\n\n1-Limpeza\n2-Cereais\n3-Massas\n4-Frios\n5-Bebidas\n6-Laticinios\n7-Outro\n\n");
        scanf("%c", &opc);
        getchar();
        switch(opc)
        {
          case '1':
          strcpy(prod[cont].tipo, "Limpeza");
          break;
          case '2':
          strcpy(prod[cont].tipo, "Cereais");
          break;
          case '3':
          strcpy(prod[cont].tipo, "Massas");
          break;
          case '4':
          strcpy(prod[cont].tipo, "Frios");
          break;
          case '5':
          strcpy(prod[cont].tipo, "Bebidas");
          break;
          case '6':
          strcpy(prod[cont].tipo, "Laticinios");
          break;
          case '7':
          strcpy(prod[cont].tipo, "Verde");
          break;

          default:
          printf("\n\nOpção inválida!\n\n");
          break;

        };    
        
    };



    void conf(char *ex, int *cont)
    {
      char opc;

      printf("\n\n1-Encerrar cadastro\n2-Refazer cadastro\n3-Novo cadastro\n\n");
      scanf("%s", &opc);
      getchar();

      switch(opc)
      {
        case '1':
        *cont = *cont + 1;
        *ex = 'x';
        break;
        
        case '2':
        break;

        case '3':
        *cont = *cont + 1;
        *ex = 'n';
        break;

        default:
        printf("\n\nOpcao invalida!\n\n");
        break;
      };
    };





int main()
{

//VARIAVEIS THIAGO
  int log = 0,
  fim = 0,
  perm = 0;
  Login login;

//VARIAVEIS EDSON
  FILE *p;
  p = fopen("Estoque.txt", "w");
	char sair = 'n';
  int contador = 0;

	struct Produto estoque[100];
  int av;


//PROGRAMA
  printf("\n\t*********NO CONTROLE*********\n");

  do //execução do programa
{
  
  printf("\n1. Cadastrar Usuario\n2. Login\n");
  int op;
  scanf("%i", &op);
  getchar();
  
 if (op == 1)//cadastro
 {
  
    printf("\n*Cadastrar Usuario*\nLogin: ");
    scanf("%s", login.usuario);
    getchar();
    printf("Senha: ");
    scanf("%s", login.senha);
    getchar();   
    do
    {
      printf("Permissao: ");
      scanf("%i", &perm);
      getchar();
      if(perm == 1 || perm == 2)
      {
        login.perm = perm;
        break;
      }
      else
      {
        printf("\nOpcao invalida\n");
      }
    }while(perm == 0);

    printf("\nCadastro realizado com sucesso!\n");
	system("cls");
       
 }
  else if(op == 2)//login
  {
    printf("\n\t*Login*");
    char login1[20], senha1[20];
    int chek = 0;

      do
      {
          printf("\nUsuario: ");
          scanf("%s", login1); 
          if (strcmp(login.usuario, login1) == 0) 
          {
              printf("Senha: ");
            scanf("%s",senha1); 
            if (strcmp(login.senha, senha1) == 0) 
            {
              printf("Logado");          
              chek++;
              log = 1;
              system("cls");
            }
            else
            {
              printf("Senha incorreta. Tente Novamente:\n");      
            }
          }
          else
          {
            printf("Login Incorreto. Tente novamente:\n");
          }      
      }while(chek == 0);
    


  }
  else
  {
      printf("\n*Opcao invalida*\n\n");
  }

}while(log == 0);

do 
{
    printf("\n\n*****BEM VINDO(A)*****\n");

  if(login.perm == 1)//execução para o usuario
  {
    do
    {
      int op;
    printf("\n1. Vendas\n2. Encomendas\n3. Fechar caixa\n");
    scanf("%i", &op);

      switch(op)
      {
        case 1:
        printf("\n(Função de Vendas)\n");
        break;

        case 2:
        cadEncomenda();
         
        break;

        case 3:
        printf("\n(Função de Lucro)");
        fim = 1;
        break;

        default:
        printf("*Opcao Invalida*\n");
      }
    
    }while(fim == 0);
  }
  else if(login.perm == 2)//execução para o editor
  {
    do
    {
      int op;
      printf("\n1. Mudar Precos\n2. Adicionar/Remover Produtos\n3. Balanco de vendas e Lucros\n0. Sair\n");
      scanf("%i", &op);

      switch(op)
      {

        case 1:
        printf("\n(Função de Preços)\n");
        break;
        

        case 2:
        printf("\n");
        int exit = 1;
        			do
			 		{
			 			int menu;
  						
			 			printf("\n1. Para cadastro de produto\n2. Estoque\n0. Para voltar\n");
			 			scanf("%i", &menu);
			 			getchar();
			 			
			 			switch(menu)
			 			{
			 				case 1:
                     do
                    {
                    
                    do{
                        av = 0;
                        cadastro_char(estoque, &contador);
                        avancar(&av);

                    }while(av != 1);
                    
                    do{
                        av = 0;
                        cadastro_int(estoque, &contador);
                        avancar(&av);

                    }while(av != 1);

                    do{
                        av = 0;
                        cadastro_float(estoque, &contador);
                        avancar(&av);

                    }while(av != 1);

                    do{
                        av = 0;
                        cadastro_val(estoque, &contador);
                        avancar(&av);

                    }while(av != 1);

                    do{
                        av = 0;
                        cadastro_quantidade(estoque, &contador);
                        avancar(&av);

                    }while(av != 1);

                    do{
                        av = 0;
                        cadastro_tipo(estoque, &contador);
                        avancar(&av);

                    }while(av != 1);


                    conf(&sair, &contador);

                    }while(sair != 'x');
                      
                  fwrite(estoque, sizeof(estoque), contador + 1, p);
                  fclose(p);
			 					break;
			 				
			 				case 2:
               					printf("(\nFunção de Estoque)\n");
			 					break;
			 					
			 				case 0:
			 					exit = 0;
			 					break;
			 				
			 				default:
			 					printf("\nOpcao invalida!\n");
			 					
			 			}
			 				
					 }while(exit != 0);
					 system("cls");
        break;

        case 3:
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
    printf("Você não tem permissão.");
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
      system("cls");
    }
    else
    {
      printf("*\nOpcao Invalida\n*");
    }
  }

}while (log == 1);



return 0;
};
