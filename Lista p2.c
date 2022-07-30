#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


// Declara��o do struct
struct no{
	int dado;
	struct no *prox;
};
struct no *lista, *p, *q, *k;


// Pr�-declara��o de fun��es
void Menu();
void InserirEsq();
void InserirDir();
void Imprimir();
void Contar();
void InserirMeio();
void Soma();


// Fun��o main
int main(){
	setlocale(LC_ALL,"Portuguese");
	lista = NULL;
	int esc = 1;
	while(esc != 0){
		Menu();
		printf("\n> ");
		scanf("%d",&esc);
		printf("\n");
		switch(esc){
			case 1:
				InserirEsq();
				break;
				
			case 2:
				InserirDir();
				break;
			
			case 3:
				Imprimir();
				break;
			
			case 4:
				system("cls");
				break;
			
			case 5:
				InserirMeio();
				break;
				
			case 6:
				Contar();
				break;
			
			case 7:
				Soma();
				break;
			
			case 0:
				esc = 0;
				break;
				
			default:
				printf("Escolha inv�lida.\n\n");
		}
	}
	return 0;
}


// Menu
void Menu(){
	printf("--------------------\n");
	printf("MENU\n1 - Inserir � Esquerda\n2 - Inserir � Direita\n3 - Imprimir lista\n4 - Limpar console\n5 - Inserir na N-�sima posi��o\n6 - Contar n�s\n7 - Somar n�s\n0 - Sair\n");
	printf("--------------------\n");
}


// Fun��o Inserir � esquerda
void InserirEsq(){
	p = malloc(sizeof(struct no));
	printf("Digite o valor: ");
	scanf("%d",&p->dado);
	p->prox = lista;
	lista = p;
	printf("\n");
}


// Fun��o Inserir � direita
void InserirDir(){
	p = malloc(sizeof(struct no));
	printf("Digite o valor: ");
	scanf("%d",&p->dado);
	p->prox = NULL;
	if(lista == NULL){
		lista = p;
	}
	else{
		q = lista;
		while(q->prox != NULL){
			q = q->prox;
		}
		q->prox = p;
	}
}


// Fun��o Imprimir lista
void Imprimir(){
	if(lista == NULL){
		printf("Lista vazia.\n\n");
	}
	else{
		printf("\tLISTA:\n");
		q = lista;
		do{
			printf("\t%d\n",q->dado);
			q = q->prox;
		}while(q != NULL);
		printf("\n");
	}
}


// Fun��o Contar quantidade de n�s
void Contar(){
	int cont = 0;
	if(lista == NULL){
		printf("Lista vazia.\n\n");
	}
	else{
		k = lista;
		do{
			cont++;
			k = k->prox;
		}while(k != NULL);
		printf("Contagem: %d\n\n",cont);
	}
}

// Fun��o de Inser��o Intermedi�ria
void InserirMeio(){
	int pos,i,cont = 0;
	printf("Digite a posi��o: ");
	scanf("%d",&pos);
	
	// Contador de n�s
	k = lista;
	do{
		cont++;
		k = k->prox;
	}while(k != NULL);
	
	if(cont < pos-1){
		printf("Inser��o imposs�vel.\n\n");
	}
	else{
		if(pos-1 == cont){
		InserirDir();
		}
		else{
			p = malloc(sizeof(struct no));
			printf("Digite o valor: ");
			scanf("%d",&p->dado);
			q = lista;
			for(i=0;i<pos-2;i++){
				q = q->prox;
			}
			p->prox = q->prox;
			q->prox = p;
		}
	}
}


// Fun��o de Soma de n�s
void Soma(){
	int soma = 0;
	if(lista == NULL){
		printf("Lista vazia.\n\n");
	}
	else{
		k = lista;
		do{
			soma+= k->dado;
			k = k->prox;
		}while(k != NULL);
		printf("Soma: %d\n\n",soma);
	}
}

