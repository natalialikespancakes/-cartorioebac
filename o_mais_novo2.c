#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //blibioteca respons�vel por cuidar da string 


int registro()
{  
  //inicio cria��o de vari�veis/string 
  char arquivo [40];
  char cpf[40];
  char nome [40];
  char sobrenome [40];
  char cargo[40];
  //final da cria��o de vari�veis/string 
  
  printf("Digite o CPF a ser cadastrado: "); //coletando informa��es do usu�rio 
  scanf("%s", cpf); //%s refere-se a string
  
   strcpy(arquivo, cpf);//Responsavel por copiar os valores da string
   
   FILE*file; // cria o arquivo
   file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
   fprintf(file, cpf); // salva o valor do arquivo
   fclose(file); // fecha o arquivo
   
   file = fopen(arquivo, "a"); // abre o arquivo
   fprintf(file,","); // salva o arquivo
   fclose(file); // fecha o arquivo
   
   printf("Digite o nome a ser cadastrado: "); // Pedindo o usu�rio para digitar o nome que sera cadastrado
   scanf("%s",nome); //%s refere-se a string
   
   
   file = fopen(arquivo, "a"); // abre o arquivo	
   fprintf(file,nome); // salva o arquivo
   fclose(file); // fecha o arquivo
   
   file = fopen(arquivo, "a"); // cria o arquivo e abre o arquivo
   fprintf(file,","); // Salva o arquivo
   fclose(file); // fecha o arquivo
   
   printf("Digite o sobrenome a ser cadastrado:  "); // Pede o sobrenome do usu�rio
   scanf("%s" ,sobrenome); //%s refere-se a string
   
   file = fopen(arquivo, "a"); // abre a file
   fprintf(file,sobrenome); // salva a informa��o na file
   fclose(file); // fecha a file
   
   file = fopen(arquivo, "a"); // abre o arquivo
   fprintf(file,","); // salva o arquivo
   fclose(file); // Fecha o arquivo
   
   printf("Digite o cargo a ser cadastrado: "); // Pede o usu�rio para digitar o cargo que eles ( o usu�rio ) querem que seja cadastrado
   scanf("%s",cargo); //%s refere-se a string
   
   file = fopen(arquivo, "a"); // abre a file
   fprintf(file,cargo); // salva a informa��o na file
   fclose(file); // Fecha a file
   
   system("pause"); // pausa o sistema para voltar na pagina do inicio
	
}


int consulta()
{
	char cpf[40]; // inicio  cria��o de vari�veis/string    
	char conteudo[200]; // Final da cria��o de vari�veis/string    
	
	printf("Digite o CPF a ser consultado: "); // pedindo o usu�rio para o cpf cadastrado para poder ser consultado
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file;
	file = fopen(cpf,"r"); // abrindo a file
	
	if(file == NULL) // if quer dizer "se"
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizada!.\n"); // se o cpf etiver incorreto ou n�o salvo o programa fala "N�o foi possivel abrir o arquivo, n�o localizada!" 
	}
	
	while(fgets(conteudo, 200, file)!= NULL) 
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); //deixa o usu�rio saber que as informa��es esta salva 
		printf("%s", conteudo);
		printf("\n\n"); // essa partes esta aqui pra deixar o codigo mais limpo 
	}
	
	system("pause"); // pausa o sistema para voltar na pagina do inicio
	
	
	
	 
}

int deletar()
{
	   char cpf[40]; // este � o limite de digitos gue o cpf pode ter 
	   
	   
	   printf("Digite o cpf a ser deletado: "); // pede o usu�rio para digitar o cpf que o usu�rio quer deletar 
	   scanf("%s",cpf); //%s refere-se a string
	   
	   remove(cpf); // Aqui o cpf ja esta deletado
	   
	   FILE *file;
	   file = fopen(cpf,"r"); // abrindo a file
	   
	   if(file == NULL) // if quer dizer "se"
	   {
	   	printf("O usu�rio n�o se encontra no sistema!.\n "); // aqui � uma mensagem falando que nao pode achar o usu�rio no sistema porque ja foi deletado 
	   	system("pause"); // pausa o sistema e volta para a pagina do inicio
	   }
}

int main()
{
	int opcao=0; //Definindo vari�veis 
	int laco=1;
	
	for(laco=1;laco=10;)
    {
	
	system("cls");
	
    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	printf("### Meu computador ###\n\n"); //inicio do menu
	printf("Escolha a op��o desejada do menu:\n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes \n");
	printf("\t3 - Deletar nomes \n\n");
	printf("Op��o: ");//fim do menu
	
    scanf("%d", &opcao); //armazenando a escolha do usu�rio 
    
    system("cls"); //responsavel por limpar a tela


    switch(opcao) //inicio da sele��o do menu 
    {
    	case 1:
    registro(); //chamada de fun��es 
	
	    break;
	
	   	
	   case 2:
		consulta();
    
    break;
    
    case 3:
	 deletar(); 
	 
	  break;
	  
	
	  
	  default:
	  	printf("Essa op��o n�o est� disponivel!\n");
	system("pause"); // Pausa o sistema
    }
	
   }
   
    
}
