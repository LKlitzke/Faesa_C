#include <stdio.h>
#include <string.h>
#include <locale.h>

// Alunos: Erikson Ferreira, Lucas Klitzke, Pablo Barbato, Ricardo Vaccari
// Data: 20/06/2018
// Disciplina: TP2

// Struct para dados
struct Frase{
	char Frase[100];
	int vezes;
} func[100];

// Função para pular linhas
void Linha(){
	printf("-------------------------------------------------------\n");
}

// Função para remover pontuação
void Remover(char str[], char letra){
	int i,j;
	for(i=0; i < strlen(str) ; i++)
	{
		if(str[i] == letra)
		{
			for(j=i; j < strlen(str); j++)
			{
				str[j] = str[j+1];
			}
			i--;
		}
	}
}
int EscreverPalavras(int total){
		// Salva palavras no arquivo
	FILE *escrever;
	int i;
	escrever = fopen("wordcount.json","w");	
	if(!escrever){
		printf("Impossível acessar o(s) arquivo(s).\n");
		return 0;
	}
	else
		printf("Arquivos acessados com sucesso\n");
	fprintf(escrever,"{\n\n");
	for(i=0;i<total;i++){
		printf("'%s' : %d\n",func[i].Frase,func[i].vezes);
		fprintf(escrever,"'%s' : %d\n",func[i].Frase,func[i].vezes);
	}
	fprintf(escrever,"\n}\n");
	fclose(escrever);
}

// Main
main(){
	setlocale(LC_ALL,"Portuguese");
	int i=0,j,l,m,n;
	int contagem=0, tamanho=0;
	char pontos[] = ".!?-,()'";
	char temporario[100];


	// Acessa os arquivos
	FILE *ler;
	ler = fopen("arquivo.txt","r");
	
	printf(" VERIFICNADO LEITURA DE ARQUIVOS:\n > ");
	if(!ler){
		printf("Impossível acessar o(s) arquivo(s).\n");
		return 0;
	}
	else
		printf("Arquivos acessados com sucesso\n");


	// Inicia leitura da frase, remove pontuação e soma repetições
	Linha();
	while(!feof(ler)){
		fscanf(ler," %s", &temporario);
		strlwr(temporario);
		for(j=0;j< strlen(pontos);j++){			
			Remover(temporario,pontos[j]);
		}
		
		if(strlen(temporario) > 2){
			for(i=0; i < contagem; i ++){
				if(strcmp(temporario, func[i].Frase) == 0){
					func[i].vezes++;
					break;
				}
			}
			if(i == contagem){ // se nao encontrou
				strcpy(func[contagem].Frase,temporario);
				func[contagem].vezes = 1;
				contagem++;
			}
			
		}
	}
	// Fecha o arquivo
	fclose(ler);
	EscreverPalavras(contagem);
	
	// Mostra informações 
	Linha();
	printf("\nINFORMAÇÕES SOBRE O ARQUIVO:\n\n");
	printf("> A QUANTIDADE DE PALAVRAS MANTIDAS É: %d\n",contagem);
	printf("> A CONTAGEM DE PALAVRAS FOI SALVA NO ARQUIVO 'wordcount.json'.\n");	


}
