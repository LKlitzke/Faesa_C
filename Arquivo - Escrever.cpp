#include <stdio.h>

main(){
	char nome[20];
	FILE *cuzin;
	cuzin = fopen("Escrever2.txt","w");
	fprintf(cuzin,"teste ambienal2222\npaçoca");
	fclose(cuzin);
}
