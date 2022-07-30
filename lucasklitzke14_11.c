#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Nome: Lucas Eduardo Klitzke da Silva
// Estrutura de Dados
// Data: 14/11/18


/*INFORMAÇÕES: Criar vetor de tamanho 4, com um struct em cada. O struct terá 3 campos, "serviço","Operação" e "início".
 Existem 4 serviços, 0,1,2 e 3. o serviço 0 e 2 é de tipo FILA, 1 e 3 do tipo PILHA. O usuário fará solicitações de INSERIR e REMOVER serviços.
	LSE somente!
 Fila: FIFO
 Pilha: LIFO
*/


struct sv{
	int s;
	char op;
	struct no *ini;
};

struct no{
	int num;
	struct no *prox;
};
struct no *p,*q,*r,*s;
struct sv vet[4];

// Variáveis globais
int i,j;

// Pré-declaração de funções
void Inserir();
void Remover();
void Imprimir();

// Função main
int main(int argc, char *argv[]){
	int esc;
	setlocale(LC_ALL,"Portuguese");
	system("color 0F");
	
	// Zerando o ponteiro
	for(i=0;i<4;i++){
	vet[i].ini = NULL;
	}
	
	// Inicializando valor de serviço
	for(i=0;i<4;i++){
	vet[i].s = i;
	}
	
	// Definindo tipo de operação (f = fila // p = pilha)
	vet[0].op = 'f';
	vet[1].op = 'p';
	vet[2].op = 'f';
	vet[3].op = 'p';
	
	// Menu
	do{
		printf("-------- MENU --------\n1 - Inserir serviço\n2 - Remover serviço\n3 - Limpar console\n4 - Imprimir\n0 - Sair\n----------------------\n> ");
		scanf("%d",&esc);
		printf("\n");
		
		switch(esc){
			case 1:
				Inserir(); break;
				
			case 2:
				Remover(); break;
				
			case 3:
				system("cls"); break;
			
			case 4:
				Imprimir(); break;
				
			case 0:
				esc = 0; break;
				
			default:
				printf("Opção inválida.\n\n");
				break;
		}
	}while(esc != 0);
	return 0;
}

// Função Inserir serviços
void Inserir(){
	p = malloc(sizeof(struct no));
	int esc, num;
	printf("Selecione o registro:\n\t0 (Fila)\n\t1 (Pilha)\n\t2 (Fila)\n\t3 (Pilha)\n> ");
	scanf("%d",&esc);
	if(esc < 0 || esc > 3){
		printf("Registro inexistente.");
	}
	else{
		printf("\n");
		printf("Digite o número da operação:\n> ");
		scanf("%d",&p->num);
		printf("\n");
		
		// Fila e Pilha
		p->prox = vet[esc].ini;
		vet[esc].ini = p;
		printf("Operação %d adicionada ao registro %d.",p->num,esc);
	}
	printf("\n\n");
}

// Função Remover serviços
void Remover(){
	int esc,cont=0;
	printf("Selecione o registro:\n\t0 (Fila)\n\t1 (Pilha)\n\t2 (Fila)\n\t3 (Pilha)\n> ");
	scanf("%d",&esc);
	printf("\n");
	if(esc < 0 || esc > 3){
		printf("Registro inexistente.");
	}
	else{
		if(vet[esc].ini == NULL){
			printf("O Registro está vazio.");
		}
		else{
			// Fila
			if(esc == 0 || esc == 2){
				q = vet[esc].ini;
					do{
						r = q;
						cont++;
						q = q->prox;
					}while(q != NULL);
					
					if(cont == 1){
						vet[esc].ini = NULL;
						printf("Operação %d removida.\n",r->num);
						free(r);
					}
					else{
						r = vet[esc].ini;
						for(i=0;i<cont-2;i++){
							r = r->prox;
						}
						s = r->prox;
						printf("Operação %d removida.\n",s->num);
						r->prox = NULL;
						free(s);
					}
			}
			
			//Pilha
			else if(esc == 1 || esc == 3){
				q = vet[esc].ini;
					vet[esc].ini = q->prox;
					printf("Operação %d removida.\n",q->num);
					free(q);
			}	
		}
	}
	printf("\n\n");
}

// Função Imprimir serviços
void Imprimir(){
	for(i=0;i<4;i++){
		q = vet[i].ini;
		if(q == NULL){
			printf("\nRegistro %d vazio.\n",i);
		}
		else{
			printf("\nRegistro %d: ",i);
			do{
				printf("%d ",q->num);
				q = q->prox;	
			}while(q != NULL);
			printf("\n");
		}
	}
	printf("\n");
}
