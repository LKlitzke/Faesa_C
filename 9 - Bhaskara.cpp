#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>

// Calculadora de Bhaskara 
linha(){
	printf("----------------------------------------\n");
}
Fim(){
	linha();
	printf("\tFIM DA OPERAÇÃO!\n");
	linha();
	system("pause");
	system("cls");	
}

bhaskara(float a,float b,float c){
	float delta, x1,x2;
	delta = pow(b,2) - 4*a*c;
	linha();
	printf("\n");
	printf("O valor de Delta é: %.1f\n",delta);
	if (delta > 0){
		//Calculando x1
		x1 = -b + sqrt(delta);
		x1 = x1/(2*a);
		printf("O valor de x1 é: %.1f\n",x1);
		//Calculando x2
		x2 = -b - sqrt(delta);
			x2 = x2/(2*a);
		printf("O valor de x2 é: %.1f\n",x2);
		
		printf("O X de vértice está em: %.1f\nO Y de vértice está em: %.1f\n\n",-b/(2*a),-delta/(4*a));
		Fim();
	}
	
	else if(delta == 0){
		//Calculando x
		x1 = -b + sqrt(delta);
		x1 = x1/(2*a);
		printf("O valor de x é: %.0f\n\n",x1);
		Fim();
	}
	
	else
		printf("X não possui um valor real, pois Delta é menor que zero.\n\n");
		Fim();
}

// d = b² - 4.a.c 
// x = (-b +- raiz d) / 2a

int main(){
	setlocale(LC_ALL,"Portuguese");
	float A,B,C;
	while(1){
		linha();
		printf("\tCALCULADORA DE BHASKARA\n");
		linha();
		printf("\n\tESTRUTURA DA EQUAÇÃO:\n\tAx² + Bx + C = 0\n\n");
		printf("CONSIDERE O SINAL NEGATIVO COM O VALOR DE A, B ou C!\n");
		printf("Digite o valor de A:\n");
		scanf("%f", &A);
		printf("Digite o valor de B:\n");
		scanf("%f", &B);
		printf("Digite o valor de C:\n");
		scanf("%f", &C);
		linha();
		if(C < 0)
			printf("\n\tEQUAÇÃO FORNECIDA:\n\t%.0fx² + %.0fx %.0f = 0\n\n",A,B,C);
		else
			printf("\n\tEQUAÇÃO FORNECIDA:\n\t%.0fx² + %.0fx + %.0f = 0\n\n",A,B,C);
		bhaskara(A,B,C);
	}
}

// I USED TO BE AN ADVENTURER LIKE YOU, THEN I TOOK AN ARROW IN THE KNEE
