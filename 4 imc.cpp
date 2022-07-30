#include <stdio.h>
#include <math.h>

// IMC - Índice de Massa Corporal

 int main(){
	float peso, altura, IMC;
	
	printf("Digite seu peso:\n");
	scanf("%f",&peso);
	printf("Digite sua altura:\n");
	scanf("%f",&altura);
	
	IMC = peso / (altura * altura);
	printf("Seu IMC e %.2f",IMC);
}
