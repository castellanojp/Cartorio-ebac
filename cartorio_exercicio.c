#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memoria 
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável pela string

int registro() //função responsável por cadastrar os usuários
{
	
	setlocale(LC_ALL, "Portuguese");// definindo linguagem
	
    char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	 
	printf("Digite o cpf que deseja cadastrar: ");
	scanf("%s",cpf);
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings
	
	FILE *file;//cria o arquivo 
	file= fopen(arquivo,"w");//cria o arquivo
	fprintf(file,cpf);//salva a variável 
	fclose(file);//fecha o arquivo
	
	file= fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	fclose(file);
	
	file= fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file= fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);
    fclose(file);
    
    file= fopen(arquivo,"a");
    fprintf(file,sobrenome);
    fclose(file);
    
  	file= fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:");
	scanf("%s", cargo);
	
	file= fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");// definindo linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado:\n");
	scanf("%s,",cpf);//armazenando a variável "cpf" utilizando a função "%s"
	printf("\n");
	
	FILE *file;
	file= fopen(cpf,"r");//abre o arquivo "cpf" e o lê
	
	
		if(file == NULL)//se a informaçao nao existir mostra o seguinte texto
	{
		printf("O arquivo selecionado não foi encontrado!\n");
	}
	
	
	while(fgets(conteudo, 200, file)!= NULL);//enquanto houver informação, armazene em conteudo se for diferente de NULL
	{
     printf("Essas são as informações do usuário:");
     printf("%s", conteudo);
     printf("\n\n");		
	}
	
	system("pause");
	fclose(file);
	
}

int deletar()
{
	char cpf[40];

	printf("Digite o cpf do usuário que deseja deletar:");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário foi deletado com sucesso!\n");
		system("pause");
	}
}

int main()
  {
    int opcao=0;//definindo variaveis
    int laco=1;
    
    for(laco=1;laco=1;)
    
	{
	
      system("cls");
	
	  setlocale(LC_ALL, "Portuguese");// definindo linguagem
	
	  printf("\t Cartório da EBAC \t\n\n");// inicio do menu
	  printf("Escolha a opção desejada do menu:\n\n");
	  printf("\t1 - Registrar nomes\n");
	  printf("\t2 - Consultar nomes\n");
   	  printf("\t3 - Deletar nomes\n\n");
   	  printf("\t4 - Sair do sistema\n");
	  printf("Opção: ");//fim do menu
    
	scanf("%d", &opcao);//armazenando escolha do usuario
	
	system("cls");//responsável por limpar a tela
	
	switch(opcao)//inicio da seleção
	{
		case 1:
		registro();
		break;
		
		case 2:
	    consulta();
		break;
		
		case 3:
		deletar();
		break;
		
		case 4:
		printf("Obrigado por utilizar o sistema!\n");
		return 0;
		break;	
		
		default:
		printf("Essa opção nao está disponível\t");
		system("pause");
		break;
		
	}//fim da seleção
	
  }
    
}

