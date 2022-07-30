#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void linha(){
	printf("\n--------------------------------\n");
}

void JogoIniciar(FILE *arquivo,int dificuldade){
	int i,Valor = 1 + rand()%7;
	char palavra[30]={};
	arquivo = fopen("palavras.txt","r");
	for(i=0;i<Valor;i++){
		fscanf(arquivo,"%s",palavra);
	}
	printf("%s",palavra);
	
}

// Função para a seleção da dificuldade
void SelecDific(FILE *arquivo,int dificuldade){
	
	// Loop para mostrar a dificuldade na tela
	do{
		printf("Dificuldade atual: ");
		switch(dificuldade){
			case 1:
				printf("FÁCIL\n"); break;
			case 2:
				printf("MÉDIO\n"); break;
			case 3:
				printf("DIFÍCIL\n"); break;
			default:
				printf("Achou um bug né safado"); break;
		}
		linha();
		
		// Seleção da dificuldade 
		printf("Selecione a dificuldade:\n\t1 - Fácil\t(7 vidas)\n\t2 - Médio\t(5 vidas)\n\t3 - Difícil\t(3 vidas)\n\t0 - Voltar\n> ");
		scanf("%d",&dificuldade);
		
		linha();
		system("cls");
	}while(dificuldade != 0);
	
	printf("Dificuldade atualizada!\n");
}

// Função que executa o menu e suas opções
void Menu(FILE *arquivo){
	int opcaoMenu,dific=2;  // Dificuldade inicial: médio
	
	// Loop do menu
	do{
		linha();
		printf("\tJOGO DA FORCA");
		linha();
		printf("1 - Iniciar jogo\n2 - Selecionar dificuldade\n3 - Sair\n> ");
		scanf("%d",&opcaoMenu);
		
		// Switch para a opção selecionada no menu
		switch(opcaoMenu){
			case 1:
				system("cls");
				JogoIniciar(arquivo,dific);
				break;
			
			case 2:
				system("cls");
				SelecDific(arquivo, dific);
				break;
			
			case 3:
				linha();
				printf("\tAté breve!");
				break;
				
			default:
				system("cls");
				printf("Opção %d inválida! Tente novamente.\n\n",opcaoMenu);
				system("pause");
				system("cls"); break;
				
		}	
	}while(opcaoMenu != 3);
}

// Função main
int main(){
	int vida,opcaoMenu=0;
	
	// Configurações iniciais de linguagem, tempo e abertura de arquivo
	setlocale(LC_ALL,"Portuguese");
	srand(time(NULL));
	FILE *arquivo;
	arquivo = fopen("palavras.txt","r");
	
	// Verifica existência do arquivo
	if(!arquivo){
		printf("Arquivo não encontrado ou possui erro.\n");
	}
	
	Menu(arquivo);
	fclose(arquivo);
	return 0;
}
