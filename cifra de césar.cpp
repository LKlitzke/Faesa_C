#include <stdio.h>
#include <string.h>

// -------- Cifra de César

// Função para codificar a frase
void codificar(char frase[],int c){
	int i;
	for(i=0; i < strlen(frase); i++){
		if(frase[i] == 'z')
			frase[i] = 'c';
		else if(frase[i] == 'y')
			frase[i] = 'b';
		else if(frase[i] == 'x')
			frase[i] = 'a';
		else if(frase[i] == ' ')
			frase[i] = ' ';
		else if(frase[i] == 'Z')
			frase[i] = 'C';
		else if(frase[i] == 'Y')
			frase[i] = 'B';
		else if(frase[i] == 'X')
			frase[i] = 'A';
		else
			frase[i] +=c;
	}
}

// Função para descodificar a frase
void decodificar(char segredo[],int c){
	int i;
	for(i=0; i < strlen(segredo); i++){
		if(segredo[i] == 'c')
			segredo[i] = 'z';
		else if(segredo[i] == 'b')
			segredo[i] = 'y';
		else if(segredo[i] == 'a')
			segredo[i] = 'x';
		else if(segredo[i] == ' ')
			segredo[i]= ' ';
		else if(segredo[i] == 'C')
			segredo[i] = 'Z';
		else if(segredo[i] == 'B')
			segredo[i] = 'Y';
		else if(segredo[i] == 'A')
			segredo[i] = 'X';
		else
			segredo[i] -=c;
	}	
}

// Função para pular linhas (tempo sobrando)
void Plinhas(){
	printf("---------------------\n");
}

// Função Main
main(){
	char frase[30];
	int c=3;
	printf("DIGITE UMA FRASE PARA CODIFICAR: ");
	fgets(frase,30,stdin);
	printf("FRASE A SER CODIFICADA: ");
	puts(frase);
	Plinhas();
	printf("FRASE CODIFICADA: ");
	codificar(frase,c);
	puts(frase);	// Frase codificada
	
	// Fim da codificação e início da decodificação
	printf("---------------------\n\nFRASE A SER DECODIFICADA: ");
	puts(frase);
	printf("\n");
	Plinhas();
	printf("FRASE DECODIFICADA: ");
	decodificar(frase,c);
	puts(frase);	// Frase decodificada
}
