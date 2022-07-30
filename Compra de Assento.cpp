#include <stdio.h>

int main(){
	//Entrada de dados
	int set,fil,cad,i,j,qtd_vrd=0,qtd_amr=0,qtd_azl=0,qtd_brc=0, arrec,m_qtd;
	int verde[25][200]={0};
	int amarelo[25][200]={0};
	int azul[25][200]={0};
	int branco[25][200]={0};
	
	//Seleção do setor/fileira/cadeira
	while(1){
		printf("Selecione o setor ou opcao:\n\n1 - verde\n2 - amarelo\n3 - azul\n4 - branco\n5 - Encerrar vendas\n6 - Setor mais ocupado\n7 - Sair\n\n");
		scanf("%i",&set);
		printf("\n\n");
		switch(set){
		case 1:
			printf("Selecione a fileira(25) e cadeira(200)\n\n");
			scanf("%i %i",&fil,&cad);
			printf("Fileira %i | Cadeira %i\n\n",fil,cad);
			if(fil < 1 || fil > 25 || cad < 1 || cad > 200){
				printf("Fileira/cadeira invalida!\n");
				break;
			}
			if(verde[fil][cad] == 1)
				printf("Assento ja adquirido!\n");
			else{
				verde[fil][cad] = 1;
				printf("Assento adquirido!\n");
			}
			break;
			
			case 2:
			printf("Selecione a fileira(25) e cadeira(200)\n\n");
			scanf("%i %i",&fil,&cad);
			printf("Fileira %i | Cadeira %i\n\n",fil,cad);
			if(fil < 1 || fil > 25 || cad < 1 || cad > 200){
				printf("Fileira/cadeira invalida!\n");
				break;
			}
			if(amarelo[fil][cad] == 1)
				printf("Assento ja adquirido!\n");
			else{
				amarelo[fil][cad] = 1;
				printf("Assento adquirido!\n");
			break;
			}
			
			case 3:
			printf("Selecione a fileira(25) e cadeira(200)\n\n");
			scanf("%i %i",&fil,&cad);
			printf("Fileira %i | Cadeira %i\n\n",fil,cad);
			if(fil < 1 || fil > 25 || cad < 1 || cad > 200){
				printf("Fileira/cadeira invalida!\n");
				break;
			}
			if(azul[fil][cad] == 1)
				printf("Assento ja adquirido!\n");
			else{
				azul[fil][cad] = 1;
				printf("Assento adquirido!\n");
			}
			break;
			
			case 4:
			printf("Selecione a fileira(25) e cadeira(200)\n\n");
			scanf("%i %i",&fil,&cad);
			printf("Fileira %i | Cadeira %i\n\n",fil,cad);
			if(fil < 1 || fil > 25 || cad < 1 || cad > 200){
				printf("Fileira/cadeira invalida!\n");
				break;
			}
			if(branco[fil][cad] == 1)
				printf("Assento ja adquirido!\n");
			else{
				branco[fil][cad] = 1;
				printf("Assento adquirido!\n");
			}
			break;
			
			case 5:
				printf("Calculando arrecadacao...\n\n");
				// Calculando matrizes
				for(i=0;i<25;i++){
					for(j=0;j<200;j++){
						if(verde[i][j]==1 )
							qtd_vrd++;
					}		
				}
				for(i=0;i<25;i++){
					for(j=0;j<200;j++){
						if(amarelo[i][j]==1)
							qtd_amr++;
					}		
				}
				for(i=0;i<25;i++){
					for(j=0;j<200;j++){
						if(azul[i][j]==1)
							qtd_azl++;
					}		
				}
				for(i=0;i<25;i++){
					for(j=0;j<200;j++){
						if(branco[i][j]==1)
							qtd_brc++;
					}		
				}
				arrec = (qtd_vrd * 100) + (qtd_brc * 25) + (qtd_azl * 35) + (qtd_amr * 50);
				
				printf("A arrecadacao total e de: %i\n\n",arrec);
				return 0;
				
			case 6:
				printf("Calculando setor mais ocupado...\n\n");
				for(i=0;i<25;i++){
					for(j=0;j<200;j++){
						if(verde[i][j]==1)
							qtd_vrd++;
					}			
				}
				for(i=0;i<25;i++){
					for(j=0;j<200;j++){
						if(amarelo[i][j]==1)
							qtd_amr++;
					}			
				}
				for(i=0;i<25;i++){
					for(j=0;j<200;j++){
						if(azul[i][j]==1)
							qtd_azl++;
					}			
				}
				for(i=0;i<25;i++){
					for(j=0;j<200;j++){
						if(branco[i][j]==1)
							qtd_brc++;
					}		
				}
				if(qtd_vrd > qtd_azl  && qtd_vrd > qtd_amr && qtd_vrd > qtd_brc){
					printf("Setor mais ocupado: Verde (%i)\n",qtd_vrd);
					return 0;
				}
				if(qtd_azl > qtd_vrd  && qtd_azl > qtd_amr && qtd_azl > qtd_brc){
					printf("Setor mais ocupado: Azul (%i)\n",qtd_azl);
					return 0;
				}
				if(qtd_amr > qtd_azl  && qtd_amr > qtd_vrd && qtd_amr > qtd_brc){
					printf("Setor mais ocupado: Amarelo (%i)\n",qtd_amr);
					return 0;
				}
				if(qtd_brc > qtd_azl  && qtd_brc > qtd_amr && qtd_brc > qtd_vrd){
					printf("Setor mais ocupado: Branco (%i)\n",qtd_brc);
					return 0;
				}
				else{
					printf("Nenhum setor ocupado!\n\n");
					break;
				}
				
			case 7:
				printf("Obrigado por usar nosso servico!\n");
				return 0;
				break;
				
			default:
				printf("Setor invalido!\n");
				printf("------------------------\n\n");
				break;
		}
	}
}
