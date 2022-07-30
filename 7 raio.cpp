#include <stdio.h>
#include <math.h>

main(){
	// r = raio; a = área; pi = 3.1416
	float r, a, pi = 3.1416;
	printf("Digite o raio da circunferencia:\n");
	scanf("%f",&r);
	a = pi * r * r;
	printf("A area da circunferencia e: %.2f",a);
	
}
