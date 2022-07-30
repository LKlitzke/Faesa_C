#include <stdio.h>
#include <stdlib.h>

struct nose{
	int dado;
	struct nose *prox;
};
struct nose *lista, *p, *q;

struct node{
	int dado;
	struct node *esq, *dir;
};
struct node *x, *y;

struct descritor{
	int n;
	struct node *i,*f;
};
struct descritor *d;

int a,b,valor;

void criarLSE();
int removerLSEesq();
int removerLSEdir();
void inserirLDE(int valor);
void transporLSELDE();
void imprimirLDE();


int main(int argc, char *argv[]) {
	
	//zerando listas
	lista = NULL;
	d = malloc(sizeof(struct descritor));
	d->i = NULL;
	d->f = NULL;
	d->n = 0;
	
	criarLSE();
	transporLSELDE();
	imprimirLDE();
	
	return 0;
}


void criarLSE(){
	printf("Lista Simplesmente Encadeada...: ");
	for(a=9;a>=0;a--){
		p = malloc(sizeof(struct nose));
		p->dado = a;
		p->prox = lista;
		lista = p;
		printf("%d ",p->dado);
	}
	printf("\n");
}

int removerLSEesq(){
	int valor;
	p=lista;
	lista=p->prox;
	valor=p->dado;
	free(p);
	return valor;
}

int removerLSEdir(){
	p = lista;
	while(p->prox !=NULL){
		q = p;
		p=p->prox;
	}
	q->prox = NULL;
	valor = p->dado;
	free(p);
	return valor;
	
}

void inserirLDE(int valor){
	x = malloc(sizeof(struct node));
	
	if(d->n == 0){
		d->n = 1;
		d->i = x;
		d->f = x;
		x->dado = valor;
		x->esq = NULL;
		x->dir = NULL;
	}
	else{
		y = d->f;
		y->dir = x;
		x->esq = y;
		x->dir = NULL;
		x->dado = valor;
		d->f = x;
		d->n = d->n + 1;		
	}
}

void transporLSELDE(){
	int v;
	for(a=0;a<5;a++){
		v = removerLSEesq();
		inserirLDE(v);
		v= removerLSEdir();
		inserirLDE(v);
	}
}

void imprimirLDE(){
	x = d->i;
	printf("Lista Duplamente Encadeada.....: ");
	while(x!=0){
		printf("%d ",x->dado);
		x = x->dir;
	}
	printf("\n");
}

