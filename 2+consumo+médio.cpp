#include <stdio.h>
#include <math.h>

main(){
	// km = distância percorrida; l = combustível utilizado; csm = consumo médio
	float km, l, csm;
	printf("Digite a distancia percorrida (em km):\n");
	scanf("%f",&km);
	
	printf("Digite o total de combustivel utilizado (em litros):\n");
	scanf("%f",&l);
	
	csm = km / l;
	printf("O consumo medio e %.2f km/l",csm);
}
