#include <stdio.h>
#include <math.h>

main(){
	// aq = distância A ao quadrado; bq = distância B ao quadrado
	//c = distância entre os pontos
	float x1, x2, y1, y2, a, b, c, aq, bq;
	printf("Digite a posicao X da coordenada 1\n");
	scanf("%f", &x1);
	printf("Digite a posicao X da coordenada 2\n");
	scanf("%f", &x2);
	a = x2 - x1;
	aq = a * a;
	printf("Digite a posicao y da coordenada 1\n");
	scanf("%f", &y1);
	printf("Digite a posicao y da coordenada 2\n");
	scanf("%f", &y2);
	b = y2 - y1;
	bq = b * b;
	// fórmula estendida para evitar bugs
	c = sqrt(aq + bq);
	printf("A distancia entre os pontos e %.1f", c);
	
}
