#include <stdio.h>
#include <string.h>

/* Obs: � necess�rio arquivo j� com as palavras
*/
main(){
	int i=1, cont=0, num[5];
	char palavra[20];
	FILE *fp;
	
	// Abre o arquivo
	fp = fopen("lucas.txt","r");
	
	// l� o valor
	while(!feof(fp)){
		fscanf(fp,"%s",&palavra);
		strlwr(palavra); // Converte para min�sculo
		if (strcmp(palavra,"lucas") == 0){
			cont++;
		}
	}
	
	printf("Brazil aparece %i vezes",cont);
	// Verifica se o arquivo foi aberto
	/*if(!fp){
		puts("Erro ao abrir.\n");
		return 0;
	}
	*/
	// Fechar o arquivo
	fclose(fp);
}
