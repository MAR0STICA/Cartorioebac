#include <stdio.h> // Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // Biblioteca de aloca��o de texto por regi�o
#include <string.h> // Biblioteca respons�vel por cuidar das string

int registro() // Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//in�cio cria��o de vari�veis/string
	char arquivo[40]; //Vari�vel para armazenar o nome do arquivo
	char cpf [40]; // Vari�vel para armazenar o CPF do usu�rio	
	char nome [40]; // Vari�vel para armazenar o nome do usu�rio
	char sobrenome [40]; // Vari�vel para armazenar o sobrenome do usu�rio
	char cargo [40]; // Vari�vel para armazenar o cargo do usu�rio
	//final cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado:  "); // Solicita ao usu�rio que digite o CPF
	scanf("%s", cpf); // L� o CPF do usu�rio e armazena na vari�vel cpf
	
	
	strcpy(arquivo, cpf); // Copia o CPF para a vari�vel arquivo, que ser� usada como nome do arquivo
	
	FILE *file; // Ponteiro para o arquivo
	file = fopen(arquivo, "w"); // Abre ou cria um arquivo para escrita com o mome baseado no CPF
	fprintf(file,cpf); // Escreve o CPF no arquivo
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo no modo de acr�scimo (append)
	fprintf(file, ","); // Adiciona v�rgula ap�s o CPF no arquivo
	fclose(file); // Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado:   ");
	scanf("%s",nome); // L� o nome do usu�rio e armazena na vari�vel nome
	
	file = fopen(arquivo, "a"); // Abre o arquivo no modo de acr�scimo (append)
	fprintf(file,nome); // Escreve o nome no arquivo ap�s a v�rgula
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); // Abre o arquivo no modo de acr�scimo (append)
	fprintf(file,","); // Adiciona uma v�rgula ap�s o nome no arquivo
	fclose(file); // Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado:  "); // Solicita ao usu�rio que digite o sobrenome
	scanf("%s",sobrenome); // L� o sobrenome do us�rio e armazena na vari�vel sobrenome
	
	file = fopen(arquivo, "a"); //Abre o arquivo no modo de acr�scimo(append)
	fprintf(file,sobrenome); // Escreve o sobrenome no arquivo ap�s a v�rgula
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); // Abre o arquivo no modo de acr�scimo (append)
	fprintf(file,","); // Adiciona uma v�rgula ap�s o sobrenome no arquivo
	fclose(file); // Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado:   "); // Solicita ao usu�rio que digite o cargo
	scanf("%s", cargo); // L� o cargo do usu�rio e armazena na vari�vel cargo
	
	file = fopen(arquivo, "a"); // Abre o arquivo no modo de acr�scimo (append)
	fprintf(file,cargo); // Escreve o cargo no arquivo ap�s a v�rgula
	fclose(file); // Fecha o arquivo
	
	system("pause"); //Pausa a execu��o do programa e espera por uma tecla para continuar
	
}

int consulta() // Fun��o respons�vel por consultar os usu�rios cadastrados no sistema
{
	setlocale(LC_ALL, "Portuguese"); // Define o idioma dos textos como portugu�s
	
	char cpf[40]; // Vari�vel para armazenar o CPF a ser consultado
	char conteudo[200]; // Vari�vel para armazenar o cont�udo lido do arquivo
	
	printf("Digite o CPF a ser consultado: "); // Solicita ao usu�rio que digite o CPF para consulta
	scanf("%s",cpf); // L� o CPF do usu�rio e armazena na vari�vel cpf
	
	FILE* file; // Ponteiro para arquivo 
	file = fopen(cpf,"r"); // Abre o arquivo para leitura baseado no CPF fornecido
	
	if(file == NULL) // Verifica se o arquivo existe
    {
	    printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n"); // Informa que o arquivo n�o foi encontrado
    }

    while(fgets(conteudo, 200, file) != NULL) // L� o conte�do do arquivo at� que n�o haja mais linhas
    {
    	printf("\nEssas s�o as informa��es do usu�rio:  "); // Informa que as pr�ximas informa��oes s�o do usu�rio consultado
    	printf("%s", conteudo); // Exibe o conte�do lido do arquivo
    	printf("\n\n");
	}
	
	system("pause"); // Pausa a execu��o do programa e espera por uma tecla para continuar
	
}

int deletar() // Fun��o respons�vel por deletar os usu�rios cadastrados no sistema
{
    char cpf[40]; // Vari�vel para armazenar o CPF a ser deletado
    
    printf("Digite o CPF do usu�rio a ser deletado: ");// Solicita oo usu�rio que digite o CPF a ser deletado
    scanf("%s", cpf); // L� o CPF do usu�rio e armazena na vari�vel cpf
    
    remove(cpf); // Deleta o arquivo correspondente ao CPF fornecido
    
    FILE *file;
    file = fopen(cpf,"r"); // Tenta abrir o arquivo deletado para leitura
    
    if(file == NULL) // Verifica se o arquivo foi realmente deletado
    {
    	printf("O usu�rio n�o se encontra no sistema.\n"); //informa que o cpf n�o foi encontrado e excluiu o arquivo
    	system("pause"); // Pausa a eecu��o do programa e espera por uma tecla para continuar
	}
	
} 

int main() // Fun��o principal que executa o programa
    {
	int opcao=0; // Vari�vel para armazenar a op��o escolhida pelo usu�rio no menu
	int laco=1; // Vari�vel de controle para o la�o do menu
	
	for(laco=1;laco=1;) // La�o infinito para o menu (deve ser laco==1 para funcionar corretamente
	{
	    system("cls"); // Limpa  a tela do console
	    
	    setlocale(LC_ALL, "Portuguese"); //Definindo o idioma dos textos como portugu�s
	
	    printf ("### Cart�rio da EBAC ###\n\n"); // Exibe o t�tulo do menu
        printf("Escolha a op��o desejada do menu:\n\n"); // Solicita ao usu�rio que escolha uma op��o do menu
	    printf("\t1 - Registrar nomes\n"); // Op��o de registro de usu�rios
	    printf("\t2 - Consultar nomes\n"); // Op��o de consultar de usu�rios
	    printf("\t3 - Deletar nomes\n\n"); // Op��o de deleta��o de usu�rio
	    printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: "); // Solicita ao usu�rio que digite a op��o desejada

        scanf("%d", &opcao); // L� a op��o escolhida pelo usu�rio e armazena na vari�vel opcao
    
        system("cls"); // Limpa a tela do console
        
        switch(opcao) // Estrutura de decis�o baseada na op��o esclhida pelo usu�rio
        {
        	case 1: // Caso a op��o seja 1
	        registro(); // Chama a fun��o de registro
	        break; // Sai da estrutura de decis�o
	        
	        case 2: // Caso a op��o seja 2
	        consulta(); // Chama a fun��o de consulta
	        break; //Sai da estrutura de decis�o
	        
	        case 3: // Caso a op��o seja 3 
		    deletar(); // Chama a fun��o de dele��o
		    break; // Sai da estrutura de decis�o
        
            case 4: 
            printf("Obrigado por utilizar o sistema!\n");
            return 0;
            break;
        
		    default: // Caso nenhuma das op��es anteriores seja escolhida
		    printf("Essa op��o n�o est� dispon�vel!\n"); //Informa ao usu�rio que a op��o n�o � v�lida
		    system("pause"); // Pausa a execu��o do programna e espera por uma tecla para continuar 
		    break; // Sai da estrutura de decis�o
				
		}
    
}
	
	
}


