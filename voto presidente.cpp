#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
	int v_1=0, v_2=0, v_3=0, v_4=0, v_5=0, v_6=0,esc,v=0;
	setlocale(LC_ALL,"portuguese");
	printf("\n-----------------------------------------------------\n");
	printf("--------*******VOTAÇÃO PRESIDENCIAL********----------\n");
	
	while(1){
		printf("-----------------ESCOLHA A OPÇÃO---------------------\n");
		printf(" 0 = Sair\n 1 = Votar\n 2 = Calcular total de votos\n");
		printf("-----------------------------------------------------\n\n Sua escolha: ");
		scanf("%i",&esc);
		system("cls");
		if(esc==0){
			printf("Finalizando votação!\n");
			return 0;
		}
		if(esc>2 || esc<0){
			printf("Escolha inválida!\n\n");
		}
		if (esc == 1){
			printf("Insira seu voto: \n1- Candidato 1\n2- Candidato 2\n3- Candidato 3\n4- Candidato 4\n5- Nulo\n6- Branco\n\n Seu voto: ");
			scanf("%i",&v);
			system("cls");
			printf("\nVoto registrado, prossiga na escolha abaixo\n\n");
			switch (v){
			case 1:
				v_1++;
				break;
			case 2:
				v_2++;
				break;
			case 3:
				v_3++;
				break;
			
			case 4:
				v_4++;
				break;
			
			case 5:
				v_5++;
				break;
			
			case 6:
				v_6++;
				break;
			default:
				printf("Voto inválido\n");
			}
		}
		if (esc==2){
			system("cls");
			printf("---------------------------------------------------\n");
			printf("----------------VALIDANDO VOTAÇÃO------------------\n");
			printf("---------------------------------------------------\n\n");
			if (v == 0){
				printf("Nenhum voto constado!\n");
				return 0;
			}
			if(v_1+v_2+v_3+v_4 >v_5+v_6)
				printf("Votação validada!\n\n");
			else if (v_1+v_2+v_3+v_4 == v_5+v_6)
				printf("Votação empatada!\n\n");
			else
				printf("Votação não válida!\n\n");
			printf("Número de votos para cada candidato: %d\n",v_1+v_2+v_3+v_4);
			printf("Candidato 1: %i\n",v_1);
			printf("Candidato 2: %i\n",v_2);
			printf("Candidato 3: %i\n",v_3);
			printf("Candidato 4: %i\n\n",v_4);
			printf("Numero de votos nulos e em branco: %d\n",v_5+v_6);
			printf("Nulos: %i\n",v_5);
			printf("Branco: %i\n\n",v_6);
		}
	}
}
