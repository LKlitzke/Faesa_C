#include <stdio.h>
#include <stdlib.h>

// Estrutura Vasco (???)
struct Vasco{
	int codigo;
	float valor;
};


// Função que busca o valor no vetor a partir do código correspondente
float BuscaV(int CodProc,Vasco vet[]){
	int valorP, i;
	for(i=0; i<4; i++){
		if(vet[i].codigo == CodProc){
			valorP = vet[i].codigo;
		}
	}
	return valorP;
}


// Função main
int main(){
	struct Vasco vet[4];
	int i,j, CodProc, opcao = 1;
	float Valor;
	
	// Preenchimento dos vetores
	for(i=0; i<4; i++){
		printf("\nDigite o codigo:\n> ");
		scanf("%d",&vet[i].codigo);
		
		printf("\nDigite o valor:\n> ");
		scanf("%f",&vet[i].valor);
	}
	
	// *TESTE* Imprime os valores
	for(j=0; j<4; j++){
		printf("\nVetor %d:\nCodigo: %d\nValor: %f\n--------\n",j,vet[j].codigo,vet[j].valor);
	}
	
	while(opcao == 1){
		// Lê o código correspondente ao valor
		printf("\nDigite o codigo a ser procurado:\n> ");
		scanf("%d",&CodProc);
		
		// Realiza a busca do valor e armazena
		Valor = BuscaV(CodProc,vet);
		printf("\nO valor encontrado para o codigo %d e: %f",CodProc,Valor);
		
		// Sai do programa ou realiza outra busca
		printf("\nDeseja buscar novamente ou sair?\n1 - Buscar\t(outro valor) - Sair\n\n");
		scanf("%d",&opcao);
	}
}


