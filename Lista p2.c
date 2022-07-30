#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


// Declaração do struct
struct no{
	int dado;
	struct no *prox;
};
struct no *lista, *p, *q, *k;


// Pré-declaração de funções
void Menu();
void InserirEsq();
void InserirDir();
void Imprimir();
void Contar();
void InserirMeio();
void Soma();


// Função main
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
				printf("Escolha inválida.\n\n");
		}
	}
	return 0;
}


// Menu
void Menu(){
	printf("--------------------\n");
	printf("MENU\n1 - Inserir à Esquerda\n2 - Inserir à Direita\n3 - Imprimir lista\n4 - Limpar console\n5 - Inserir na N-ésima posição\n6 - Contar nós\n7 - Somar nós\n0 - Sair\n");
	printf("--------------------\n");
}


// Função Inserir à esquerda
void InserirEsq(){
	p = malloc(sizeof(struct no));
	printf("Digite o valor: ");
	scanf("%d",&p->dado);
	p->prox = lista;
	lista = p;
	printf("\n");
}


// Função Inserir à direita
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


// Função Imprimir lista
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


// Função Contar quantidade de nós
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

// Função de Inserção Intermediária
void InserirMeio(){
	int pos,i,cont = 0;
	printf("Digite a posição: ");
	scanf("%d",&pos);
	
	// Contador de nós
	k = lista;
	do{
		cont++;
		k = k->prox;
	}while(k != NULL);
	
	if(cont < pos-1){
		printf("Inserção impossível.\n\n");
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


// Função de Soma de nós
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

