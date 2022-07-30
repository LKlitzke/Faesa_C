#include <stdio.h>

typedef struct Aluno{
	char nome[20];
	int matricula;
	float nota[3];
	float media;
}Aluno;

Aluno LerAluno(){
	Aluno x;
	int i;
	printf("Digite o nome: \n");
	scanf("%s",x.nome);
	printf("Digite a matricula: \n");
	scanf("%i",&x.matricula);
	for(i=0;i<3;i++){
		printf("Digite a nota %i: \n",i+1);
		scanf("%f",&(x.nota[i]));
	}
	return x;
}

float CalculaMedia(Aluno x){
	int i;
	float media= 0;
	for(i=0;i<3;i++){
		media += x.nota[i];
	}
	media = media/3;
	return media;
}

int PassouAluno(Aluno x){
	if(x.media >= 7)
		printf("Aprovado.");
	else
		printf("Reprovado.");
		
}
void imprimirAluno(Aluno x){
	int i;
	float media=0;
	printf("Nome: %s\n",x.nome);
	printf("Matricula: %i\n",x.matricula);
	for(i=0;i<3;i++){
		printf("Nota %d: %.2f\n",i+1,x.nota[i]);
	}
	printf("Media: %.2f",x.media);
}

main(){
	int i;
	Aluno x;
	x = LerAluno();
	x.media = CalculaMedia(x);
	imprimirAluno(x);
	PassouAluno(x);
}
