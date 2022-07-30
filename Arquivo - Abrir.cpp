#include <stdio.h>

main(){
	char nome[20];
	FILE *fp;
	// Abre o arquivo
	fp = fopen("RolaGrossa.txt","r");
	
	// lê o valor
	fscanf(fp,"%s",nome);
	
	// Verifica se o arquivo foi aberto
	if(!fp){
		puts("Erro ao abrir.\n");
		return 0;
	}
	
	// Fechar o arquivo
	fclose(fp);
	printf(" -- %s -- \n",nome);
}
