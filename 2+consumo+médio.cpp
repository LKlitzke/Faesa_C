#include <stdio.h>
#include <math.h>

main(){
	// km = dist�ncia percorrida; l = combust�vel utilizado; csm = consumo m�dio
	float km, l, csm;
	printf("Digite a distancia percorrida (em km):\n");
	scanf("%f",&km);
	
	printf("Digite o total de combustivel utilizado (em litros):\n");
	scanf("%f",&l);
	
	csm = km / l;
	printf("O consumo medio e %.2f km/l",csm);
}
