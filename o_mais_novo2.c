#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //blibioteca responsável por cuidar da string 


int registro()
{  
  //inicio criação de variáveis/string 
  char arquivo [40];
  char cpf[40];
  char nome [40];
  char sobrenome [40];
  char cargo[40];
  //final da criação de variáveis/string 
  
  printf("Digite o CPF a ser cadastrado: "); //coletando informações do usuário 
  scanf("%s", cpf); //%s refere-se a string
  
   strcpy(arquivo, cpf);//Responsavel por copiar os valores da string
   
   FILE*file; // cria o arquivo
   file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
   fprintf(file, cpf); // salva o valor do arquivo
   fclose(file); // fecha o arquivo
   
   file = fopen(arquivo, "a"); // abre o arquivo
   fprintf(file,","); // salva o arquivo
   fclose(file); // fecha o arquivo
   
   printf("Digite o nome a ser cadastrado: "); // Pedindo o usuário para digitar o nome que sera cadastrado
   scanf("%s",nome); //%s refere-se a string
   
   
   file = fopen(arquivo, "a"); // abre o arquivo	
   fprintf(file,nome); // salva o arquivo
   fclose(file); // fecha o arquivo
   
   file = fopen(arquivo, "a"); // cria o arquivo e abre o arquivo
   fprintf(file,","); // Salva o arquivo
   fclose(file); // fecha o arquivo
   
   printf("Digite o sobrenome a ser cadastrado:  "); // Pede o sobrenome do usuário
   scanf("%s" ,sobrenome); //%s refere-se a string
   
   file = fopen(arquivo, "a"); // abre a file
   fprintf(file,sobrenome); // salva a informação na file
   fclose(file); // fecha a file
   
   file = fopen(arquivo, "a"); // abre o arquivo
   fprintf(file,","); // salva o arquivo
   fclose(file); // Fecha o arquivo
   
   printf("Digite o cargo a ser cadastrado: "); // Pede o usuário para digitar o cargo que eles ( o usuário ) querem que seja cadastrado
   scanf("%s",cargo); //%s refere-se a string
   
   file = fopen(arquivo, "a"); // abre a file
   fprintf(file,cargo); // salva a informação na file
   fclose(file); // Fecha a file
   
   system("pause"); // pausa o sistema para voltar na pagina do inicio
	
}


int consulta()
{
	char cpf[40]; // inicio  criação de variáveis/string    
	char conteudo[200]; // Final da criação de variáveis/string    
	
	printf("Digite o CPF a ser consultado: "); // pedindo o usuário para o cpf cadastrado para poder ser consultado
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file;
	file = fopen(cpf,"r"); // abrindo a file
	
	if(file == NULL) // if quer dizer "se"
	{
		printf("Não foi possivel abrir o arquivo, não localizada!.\n"); // se o cpf etiver incorreto ou não salvo o programa fala "Não foi possivel abrir o arquivo, não localizada!" 
	}
	
	while(fgets(conteudo, 200, file)!= NULL) 
	{
		printf("\nEssas são as informações do usuário: "); //deixa o usuário saber que as informações esta salva 
		printf("%s", conteudo);
		printf("\n\n"); // essa partes esta aqui pra deixar o codigo mais limpo 
	}
	
	system("pause"); // pausa o sistema para voltar na pagina do inicio
	
	
	
	 
}

int deletar()
{
	   char cpf[40]; // este é o limite de digitos gue o cpf pode ter 
	   
	   
	   printf("Digite o cpf a ser deletado: "); // pede o usuário para digitar o cpf que o usuário quer deletar 
	   scanf("%s",cpf); //%s refere-se a string
	   
	   remove(cpf); // Aqui o cpf ja esta deletado
	   
	   FILE *file;
	   file = fopen(cpf,"r"); // abrindo a file
	   
	   if(file == NULL) // if quer dizer "se"
	   {
	   	printf("O usuário não se encontra no sistema!.\n "); // aqui é uma mensagem falando que nao pode achar o usuário no sistema porque ja foi deletado 
	   	system("pause"); // pausa o sistema e volta para a pagina do inicio
	   }
}

int main()
{
	int opcao=0; //Definindo variáveis 
	int laco=1;
	
	for(laco=1;laco=10;)
    {
	
	system("cls");
	
    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	printf("### Meu computador ###\n\n"); //inicio do menu
	printf("Escolha a opção desejada do menu:\n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes \n");
	printf("\t3 - Deletar nomes \n\n");
	printf("Opção: ");//fim do menu
	
    scanf("%d", &opcao); //armazenando a escolha do usuário 
    
    system("cls"); //responsavel por limpar a tela


    switch(opcao) //inicio da seleção do menu 
    {
    	case 1:
    registro(); //chamada de funções 
	
	    break;
	
	   	
	   case 2:
		consulta();
    
    break;
    
    case 3:
	 deletar(); 
	 
	  break;
	  
	
	  
	  default:
	  	printf("Essa opção não está disponivel!\n");
	system("pause"); // Pausa o sistema
    }
	
   }
   
    
}
