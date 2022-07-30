#include <stdio.h>
#include <stdlib.h>


// Lucas E. Klitzke da Silva
// Rafael Cardoso Venâncio
// Est. de Dados
// Atualizado: 10/10/18

struct no
{
	int dado;
	struct no *esq, *dir;
};
struct descritor
{
	int n;
	struct no *i, *f;
};
struct descritor *d;
struct no *p, *q, *r;

void inserirEsq();
void inserirDir();
void inserirInt();
void removerEsq();
void removerDir();
void removerInt();
void imprimir();

int main()
{
	// zerando lista
	d = malloc(sizeof(struct descritor));
	d->i = NULL;
	d->f = NULL;
	d->n = 0;
	
	int escolha;
	do{
		system("cls");
		printf("\n1-Inserir no a esquerda\n2-Inserir no a direita\n3-Inserir intermediario\n4-Remover esquerda\n5-Remover direita\n6-Remover intermediario\n7-Imprimir LCD\n0-Sair\nEscolha: ");
		scanf("%d",&escolha);
		printf("\n");

		switch(escolha)
		{
			case 1:	inserirEsq(); break;
			case 2:	inserirDir(); break;			
			case 3:	inserirInt(); break;
			case 4: removerEsq(); break;
			case 5: removerDir(); break;
			case 6: removerInt(); break;
			case 7: imprimir(); break;
			default: printf("Opcao invalida. Escolha novamente");break;
		}
	}while(escolha != 0);
	return 0;
}

void inserirEsq()
{
	p = malloc(sizeof(struct no));
	if(d->n == 0)
	{
		printf("Novo numero: ");
		scanf("%d", &p->dado);
		p->esq = NULL;
		p->dir = NULL;
		d->i = p;
		d->f = p;
		d->n++;
	}
	else
	{
		p = d->i;
		q = malloc(sizeof(struct no));
		printf("Novo numero: ");
		scanf("%d", &q->dado);
		q->esq = NULL;
		q->dir = p;
		p->esq = q;
		d->i = q;
		d->n++;
	}
}

void inserirDir()
{
	if(d->n == 0)
	{
		inserirEsq();
	}
	else
	{
		p = d->f;
		q = malloc(sizeof(struct no));
		printf("Novo numero: ");
		scanf("%d", &q->dado);
		p->dir = q;
		q->esq = p;
		q->dir = NULL;
		d->f = q;
		d->n++;
	}
}

void inserirInt()
{
	if(d->n == 0)
	{
		p = malloc(sizeof(struct no));
		printf("Lista Vazia, nao e possivel escolher a posicao\nNovo numero: ");
		scanf("%d", &p->dado);
		p->esq = NULL;
		p->dir = NULL;
		d->i = p;
		d->f = p;
		d->n++;
	}
	else
	{
		int pos;
		printf("Insira a posicao onde deseja inserir. Numero de 1 a %d: ", d->n);
		scanf("%d", &pos);
		if(pos == 1)
		{
			inserirEsq();
		}
		else if(pos == d->n)
		{
			inserirDir();
		}
		else if(pos>1 && pos<d->n)
		{
			p = malloc(sizeof(struct no));
			p = d->i;
			int loop;
			for(loop=0; loop<pos-2; loop++)
			{
				p = p->dir;
			}
			q = malloc(sizeof(struct no));
			printf("Novo numero: ");
			scanf("%d", &q->dado);
			q->dir = p->dir;
			q->esq = p;
			p->dir = q;
			d->n++;
		}
		else
		{
			printf("Posicao incorreta. Retornando ao menu");
			system("pause");
		}
	}
}

void removerEsq()
{
	if(d->n == 0)
	{
		printf("Lista vazia.\nImpossível remover.\n");
		system("pause");
	}
	else if(d->n == 1)
	{
		printf("Sua lista so possui um item, vamos remove-lo...\n");
		d->i = NULL;
		d->f = NULL;
		d->n = 0;
		system("pause");
	}
	else
	{
		p = d->i;
		d->i = p->dir;
		d->n--;
		free(p);
		printf("Primeiro no removido.\n");
		system("pause");
	}
}

void removerDir()
{
	if(d->n == 0)
	{
		printf("Lista vazia.\nImpossível remover.\n");
		system("pause");
	}
	else if(d->n == 1)
	{
		printf("Sua lista so possui um item, vamos remove-lo...\n");
		d->i = NULL;
		d->f = NULL;
		d->n = 0;
		system("pause");
	}
	else
	{
		p = d->f;
		q = p->esq;
		q->dir = NULL;
		d->f = q;
		d->n--;
		free(p);
		printf("Ultimo no removido.\n");
		system("pause");
	}
}


void removerInt()
{
	if(d->n == 0)
	{
		printf("Lista vazia, voltando...\n");
		system("pause");
	}
	else if(d->n == 1)
	{
		printf("Sua lista so possui um item, vamos remove-lo...\n");
		d->i = NULL;
		d->f = NULL;
		d->n = 0;
		system("pause");
	}
	else
	{
		system("cls");
		p = d->i;
		int elem = 1;
		do
		{
			printf("Item %d: %d\n",elem, p->dado);
			p = p->dir;
			elem++;
		}while(p != NULL);
		
		int pos, l;
		printf("Insira a posicao a ser apagada.\nNumero de 1 a %d: ", d->n);
		scanf("%d", &pos);
		if(pos == 1)
		{
			removerEsq();
		}
		else if(pos == d->n)
		{
			removerDir();
		}
		else if(pos > d->n)
		{
			printf("Posicao impossivel.\n");
		}
		else
		{
			p= d->i;
			for(l=0; l<pos-2; l++)
			{
				p = p->dir;
			}
			q = p->dir;
			p->dir = q->dir;
			d->n--;
			free(q);
			system("pause");
		}
	}
}

void imprimir()
{
	system("cls");
	if(d->n == 0){
		printf("A lista está vazia.\n\n");
	}
	else{
		p = d->i;
		do{
			printf("%d\n",p->dado);
			p = p->dir;
		}while(p != NULL);
	}
	system("pause");
}
