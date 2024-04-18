#include <stdio.h> // Biblioteca de comunicação com o usuário
#include <stdlib.h> // Biblioteca de alocação de espaço em memória
#include <locale.h> // Biblioteca de alocação de texto por região
#include <string.h> // Biblioteca responsável por cuidar das string

int registro() // Função responsável por cadastrar os usuários no sistema
{
	//início criação de variáveis/string
	char arquivo[40]; //Variável para armazenar o nome do arquivo
	char cpf [40]; // Variável para armazenar o CPF do usuário	
	char nome [40]; // Variável para armazenar o nome do usuário
	char sobrenome [40]; // Variável para armazenar o sobrenome do usuário
	char cargo [40]; // Variável para armazenar o cargo do usuário
	//final criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado:  "); // Solicita ao usuário que digite o CPF
	scanf("%s", cpf); // Lê o CPF do usuário e armazena na variável cpf
	
	
	strcpy(arquivo, cpf); // Copia o CPF para a variável arquivo, que será usada como nome do arquivo
	
	FILE *file; // Ponteiro para o arquivo
	file = fopen(arquivo, "w"); // Abre ou cria um arquivo para escrita com o mome baseado no CPF
	fprintf(file,cpf); // Escreve o CPF no arquivo
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo no modo de acréscimo (append)
	fprintf(file, ","); // Adiciona vírgula após o CPF no arquivo
	fclose(file); // Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado:   ");
	scanf("%s",nome); // Lê o nome do usuário e armazena na variável nome
	
	file = fopen(arquivo, "a"); // Abre o arquivo no modo de acréscimo (append)
	fprintf(file,nome); // Escreve o nome no arquivo após a vírgula
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); // Abre o arquivo no modo de acréscimo (append)
	fprintf(file,","); // Adiciona uma vírgula após o nome no arquivo
	fclose(file); // Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado:  "); // Solicita ao usuário que digite o sobrenome
	scanf("%s",sobrenome); // Lê o sobrenome do usário e armazena na variável sobrenome
	
	file = fopen(arquivo, "a"); //Abre o arquivo no modo de acréscimo(append)
	fprintf(file,sobrenome); // Escreve o sobrenome no arquivo após a vírgula
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); // Abre o arquivo no modo de acréscimo (append)
	fprintf(file,","); // Adiciona uma vírgula após o sobrenome no arquivo
	fclose(file); // Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado:   "); // Solicita ao usuário que digite o cargo
	scanf("%s", cargo); // Lê o cargo do usuário e armazena na variável cargo
	
	file = fopen(arquivo, "a"); // Abre o arquivo no modo de acréscimo (append)
	fprintf(file,cargo); // Escreve o cargo no arquivo após a vírgula
	fclose(file); // Fecha o arquivo
	
	system("pause"); //Pausa a execução do programa e espera por uma tecla para continuar
	
}

int consulta() // Função responsável por consultar os usuários cadastrados no sistema
{
	setlocale(LC_ALL, "Portuguese"); // Define o idioma dos textos como português
	
	char cpf[40]; // Variável para armazenar o CPF a ser consultado
	char conteudo[200]; // Variável para armazenar o contéudo lido do arquivo
	
	printf("Digite o CPF a ser consultado: "); // Solicita ao usuário que digite o CPF para consulta
	scanf("%s",cpf); // Lê o CPF do usuário e armazena na variável cpf
	
	FILE* file; // Ponteiro para arquivo 
	file = fopen(cpf,"r"); // Abre o arquivo para leitura baseado no CPF fornecido
	
	if(file == NULL) // Verifica se o arquivo existe
    {
	    printf("Não foi possível abrir o arquivo, não localizado!\n"); // Informa que o arquivo não foi encontrado
    }

    while(fgets(conteudo, 200, file) != NULL) // Lê o conteúdo do arquivo até que não haja mais linhas
    {
    	printf("\nEssas são as informações do usuário:  "); // Informa que as próximas informaçãoes são do usuário consultado
    	printf("%s", conteudo); // Exibe o conteúdo lido do arquivo
    	printf("\n\n");
	}
	
	system("pause"); // Pausa a execução do programa e espera por uma tecla para continuar
	
}

int deletar() // Função responsável por deletar os usuários cadastrados no sistema
{
    char cpf[40]; // Variável para armazenar o CPF a ser deletado
    
    printf("Digite o CPF do usuário a ser deletado: ");// Solicita oo usuário que digite o CPF a ser deletado
    scanf("%s", cpf); // Lê o CPF do usuário e armazena na variável cpf
    
    remove(cpf); // Deleta o arquivo correspondente ao CPF fornecido
    
    FILE *file;
    file = fopen(cpf,"r"); // Tenta abrir o arquivo deletado para leitura
    
    if(file == NULL) // Verifica se o arquivo foi realmente deletado
    {
    	printf("O usuário não se encontra no sistema.\n"); //informa que o cpf não foi encontrado e excluiu o arquivo
    	system("pause"); // Pausa a eecução do programa e espera por uma tecla para continuar
	}
	
} 

int main() // Função principal que executa o programa
    {
	int opcao=0; // Variável para armazenar a opção escolhida pelo usuário no menu
	int laco=1; // Variável de controle para o laço do menu
	
	for(laco=1;laco=1;) // Laço infinito para o menu (deve ser laco==1 para funcionar corretamente
	{
	    system("cls"); // Limpa  a tela do console
	    
	    setlocale(LC_ALL, "Portuguese"); //Definindo o idioma dos textos como português
	
	    printf ("### Cartório da EBAC ###\n\n"); // Exibe o título do menu
        printf("Escolha a opção desejada do menu:\n\n"); // Solicita ao usuário que escolha uma opção do menu
	    printf("\t1 - Registrar nomes\n"); // Opção de registro de usuários
	    printf("\t2 - Consultar nomes\n"); // Opção de consultar de usuários
	    printf("\t3 - Deletar nomes\n\n"); // Opção de deletação de usuário
	    printf("\t4 - Sair do sistema\n\n");
		printf("Opção: "); // Solicita ao usuário que digite a opção desejada

        scanf("%d", &opcao); // Lê a opção escolhida pelo usuário e armazena na variável opcao
    
        system("cls"); // Limpa a tela do console
        
        switch(opcao) // Estrutura de decisão baseada na opção esclhida pelo usuário
        {
        	case 1: // Caso a opção seja 1
	        registro(); // Chama a função de registro
	        break; // Sai da estrutura de decisão
	        
	        case 2: // Caso a opção seja 2
	        consulta(); // Chama a função de consulta
	        break; //Sai da estrutura de decisão
	        
	        case 3: // Caso a opção seja 3 
		    deletar(); // Chama a função de deleção
		    break; // Sai da estrutura de decisão
        
            case 4: 
            printf("Obrigado por utilizar o sistema!\n");
            return 0;
            break;
        
		    default: // Caso nenhuma das opções anteriores seja escolhida
		    printf("Essa opção não está disponível!\n"); //Informa ao usuário que a opção não é válida
		    system("pause"); // Pausa a execução do programna e espera por uma tecla para continuar 
		    break; // Sai da estrutura de decisão
				
		}
    
}
	
	
}


