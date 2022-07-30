#include <stdio.h>
#include <math.h>

// Celsius para Fahrenheit

main(){
	// Cs = Temperatura em Graus Celsius; Fh = Temperatura em Fahrenheit
	float Cs, Fh;
	
	printf("Digite a temperatura em graus Celsius:\n");
	scanf("%f", &Cs);
	
	Fh = (Cs * 1.8) + 32;
	printf("A temperatura em Fahrenheit e %.1f", Fh);
}
