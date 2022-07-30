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

// Fun��o para a sele��o da dificuldade
void SelecDific(FILE *arquivo,int dificuldade){
	
	// Loop para mostrar a dificuldade na tela
	do{
		printf("Dificuldade atual: ");
		switch(dificuldade){
			case 1:
				printf("F�CIL\n"); break;
			case 2:
				printf("M�DIO\n"); break;
			case 3:
				printf("DIF�CIL\n"); break;
			default:
				printf("Achou um bug n� safado"); break;
		}
		linha();
		
		// Sele��o da dificuldade 
		printf("Selecione a dificuldade:\n\t1 - F�cil\t(7 vidas)\n\t2 - M�dio\t(5 vidas)\n\t3 - Dif�cil\t(3 vidas)\n\t0 - Voltar\n> ");
		scanf("%d",&dificuldade);
		
		linha();
		system("cls");
	}while(dificuldade != 0);
	
	printf("Dificuldade atualizada!\n");
}

// Fun��o que executa o menu e suas op��es
void Menu(FILE *arquivo){
	int opcaoMenu,dific=2;  // Dificuldade inicial: m�dio
	
	// Loop do menu
	do{
		linha();
		printf("\tJOGO DA FORCA");
		linha();
		printf("1 - Iniciar jogo\n2 - Selecionar dificuldade\n3 - Sair\n> ");
		scanf("%d",&opcaoMenu);
		
		// Switch para a op��o selecionada no menu
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
				printf("\tAt� breve!");
				break;
				
			default:
				system("cls");
				printf("Op��o %d inv�lida! Tente novamente.\n\n",opcaoMenu);
				system("pause");
				system("cls"); break;
				
		}	
	}while(opcaoMenu != 3);
}

// Fun��o main
int main(){
	int vida,opcaoMenu=0;
	
	// Configura��es iniciais de linguagem, tempo e abertura de arquivo
	setlocale(LC_ALL,"Portuguese");
	srand(time(NULL));
	FILE *arquivo;
	arquivo = fopen("palavras.txt","r");
	
	// Verifica exist�ncia do arquivo
	if(!arquivo){
		printf("Arquivo n�o encontrado ou possui erro.\n");
	}
	
	Menu(arquivo);
	fclose(arquivo);
	return 0;
}
