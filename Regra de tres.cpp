#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>

// Calculadora de Bhaskara 
linha(){
	printf("-----------------------------\n");
}

bhaskara(float a,float b,float c){
	float delta, x1,x2;
	delta = pow(b,2) - 4*a*c;
	x1 = -b + sqrt(delta);
	x1 = x1/(2*a);
	printf("%f",x1);
}
// d = b² - 4.a.c 
// x = (-b +- raiz d) / 2a
int main(){
	setlocale(LC_ALL,"Portuguese");
	float A,B,C;
	printf("CALCULADORA DE BHASKARA\n");
	linha();
	printf("\n\tESTRUTURA DA EQUAÇÃO:\n\tAx² + Bx + C = 0\n\n");
	printf("CONSIDERE O SINAL NEGATIVO COM O VALOR DE A, B ou C!\n");
	printf("Digite o valor de A\n");
	scanf("%f", &A);
	printf("Digite o valor de B\n");
	scanf("%f", &B);
	printf("Digite o valor de C\n");
	scanf("%f", &C);
	bhaskara(A,B,C);
}

// IF YOU CAN READ THIS, THEN YOU ARE NOT BLIND!
