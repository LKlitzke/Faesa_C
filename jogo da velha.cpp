#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

// JOGO DA VELHA - Created by L. Klitzke - 06/21

/* Função para determinar o estado de vitória da partida
		WinStatus 0 -> Ninguém ganhou (ainda)
		WinStatus 1 -> Jogador ganhou
		WinStatus 2 -> Computador ganhou
		WinStatus 3 ->  Empate
*/
int VerificarWinStatus(char campo[3][3], int counter=0){
	int WinStatus = 0;
	
	// Verificação por linha
	if(campo[0][0] == campo[0][1] && campo[0][0] == campo[0][2] && campo[0][0] != ' '){
		campo[0][0] == 'o' ? WinStatus = 1 : WinStatus = 2;
	}
	else if(campo[1][0] == campo[1][1] && campo[1][0] == campo[1][2] && campo[1][0] != ' '){
		campo[1][0] == 'o' ? WinStatus = 1 : WinStatus = 2;
	}
	else if(campo[2][0] == campo[2][1] && campo[2][0] == campo[2][2] && campo[2][0] != ' '){
		campo[2][0] == 'o' ? WinStatus = 1 : WinStatus = 2;
	}
	// Verificação por coluna
	else if(campo[0][0] == campo[1][0] && campo[0][0] == campo[2][0] && campo[0][0] != ' '){
		campo[0][0] == 'o' ? WinStatus = 1 : WinStatus = 2;
	}
	else if(campo[0][1] == campo[1][1] && campo[0][1] == campo[2][1] && campo[0][1] != ' '){
		campo[1][0] == 'o' ? WinStatus = 1 : WinStatus = 2;
	}
	else if(campo[0][2] == campo[1][2] && campo[0][2] == campo[2][2] && campo[0][2] != ' '){
		campo[2][0] == 'o' ? WinStatus = 1 : WinStatus = 2;
	}
	// Verificação por diagonal
	else if(campo[0][0] == campo[1][1] && campo[0][0] == campo[2][2] && campo[0][0] != ' '){
		campo[0][0] == 'o' ? WinStatus = 1 : WinStatus = 2;
	}
	else if(campo[0][2] == campo[1][1] && campo[0][2] == campo[2][0] && campo[0][2] != ' '){
		campo[0][2] == 'o' ? WinStatus = 1 : WinStatus = 2;
	}
	// Verificação por empate
	else if(counter == 9)
		WinStatus = 3;
	
	return WinStatus;
}

// Função para inserir linhas no cmd
void Linha(){
	printf("\n-----------------------------------");
}

// Função para mostrar a matriz
void MostrarMatriz(char campo[3][3]){
	int i,j;
	printf("\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf(" %c ",campo[i][j]);
			(j < 2) ? printf("|") : NULL;
		}
		(i < 2) ? printf("\n-----------\n") : NULL;
	}
}

int main(){
	int winStatus = 0,jogar,jogadaL,jogadaC,counter=0;
	int i,j;
	setlocale(LC_ALL,"Portuguese");
	srand(time(NULL));

	printf("Quer jogar Jogo da Velha comigo? 1 - Sim | 0 - Não\n> ");
	scanf("%d",&jogar);
	
	// Loop para iniciar e/ou continuar jogando
	while(jogar == 1){
		Linha();
		printf("\nMuito bem! Vamos preparar o campo...\n");
		
		// Reseta a matriz
		char campo[3][3] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
		bool campoBool[3][3] = {false};
		counter = 0;
		
		printf("\nTudo pronto! Você será a bolinha e jogará primeiro. Vamos indo?\n");
		system("pause");
		
		do{
			do{
				system("cls");
				MostrarMatriz(campo);
				
				printf("\n\nOnde você quer jogar? [linha](1,2,3) [coluna](1,2,3)\n\t> ");
				scanf("%d %d",&jogadaL,&jogadaC);
				
				// Verifica se a jogada é possível
				if(campoBool[jogadaL-1][jogadaC-1] == true){
					printf("\nEi, Este lugar já está ocupado! Tente novamente!\n");
					system("pause");
				}
				else{
					campo[jogadaL-1][jogadaC-1] = 'o';
					counter++;
					break;
				}
			}while(campoBool[jogadaL-1][jogadaC-1] == true);
			
			campoBool[jogadaL-1][jogadaC-1] = true;
			printf("Você jogou no [%d,%d]!\n",jogadaL,jogadaC);
			winStatus = VerificarWinStatus(campo,counter);
			
			// Verifica se o jogo acabou
			if(winStatus == 1 || winStatus == 2 || winStatus == 3){
				break;
			}
			
			printf("\nOkay, agora é minha vez...\n");
			system("pause");
			system("cls");
			
			// Loop para determinar um campo aleatório e válido
			do{
				jogadaL = rand() % 3;
				jogadaC = rand() % 3;
				if(campoBool[jogadaL][jogadaC] == false){
					campo[jogadaL][jogadaC] = 'x';
					counter++;
					break;
				}
			}while(campoBool[jogadaL][jogadaC] == true);
			
			campoBool[jogadaL][jogadaC] = true;
			printf("Joguei no [%d,%d]!\n",jogadaL+1,jogadaC+1);
			MostrarMatriz(campo);
			
			printf("\n\n");
			system("pause");
			winStatus = VerificarWinStatus(campo,counter);
			
		}while(winStatus == 0);
		
		system("cls");
		MostrarMatriz(campo);
		
		// Mensagem final do vencedor
		switch(winStatus){
			case 1:
				printf("\nVocê ganhou! :(\n");
				break;
			case 2:
				printf("\nEu ganhei! :D\n");
				break;
			case 3:
				printf("\nDeu velha! :|\n");
				break;
		}
		
		Linha();
		printf("\nQuer jogar novamente?\n 1 - Sim  0 - Não\n> ");
		scanf("%d",&jogar);
	}
}
