#include <stdio.h>
#define itens 2				// Utilizando apenas dois itens
#define UF 27				// Utilizando todos os 27 estados


	// Inicialização da Operação Lava Prato
	// Grupo: Alexandre, Anderson e Lucas Klitzke
	
int main(){
    int linhas;
    int i, j, k;
    float m_MedioES[UF][itens];		// Média estadual
    float v_MedioN[itens];			// Média nacional
    float s_item;					// Soma dos itens (para calcular a média)
    float qtd_item;					// Quantidade de itens
    printf("================================================================\n");
    printf("\t\t OPERACAO LAVA PRATO\n");
	printf("================================================================\n");
	
	
				// Declarção de variáveis, matrizes e vetores
	printf("Digite a quantidade de linhas:	");
	scanf("%i",&linhas);
    float m_dados[linhas][itens+2];	// Matriz de dados de pregão,id do estado, e itens
    
    
				// Obtenção de dados
    for (i=0; i<linhas; i++){
        for (j=0; j<1; j++){
            printf("Digite o numero do pregao: ");
            scanf("%f", &m_dados[i][j]);
            printf("Digite o ID do Estado: ");
            scanf("%f", &m_dados[i][j+1]);
            for (k=2; k<4; k++){
                printf("Digite o valor do item %d : ", k-1);
                scanf("%f", &m_dados[i][k]);
            }
            printf("=========================================================\n\n");
        }
    }
    
				// Fazendo a média do produto por estado e por país

			// País
    for (i=0; i<1; i++){
        for (j=2; j<(itens+2); j++){
            qtd_item = 0;
            s_item = 0;								// Resetando o valor da Soma e da quantidade para não interferir nos itens seguintes
            for (k=0;k<linhas;k++){
               	qtd_item++;
                s_item += m_dados[k][j];
            }
        v_MedioN[j-2] = s_item/qtd_item;			// Valor médio do PAÍS obtido a partir dos itens fornecidos pelo usuário
        }
    }

			// Estado
    for (i=0; i<linhas; i++){
        qtd_item = 0;
        s_item = 0;									// Resetando o valor da Soma e da quantidade para não interferir nos itens seguintes
        for (j=2; j<(itens+2); j++){     
                qtd_item++;
                s_item += m_dados[i][j];
        }
        m_MedioES[i][0] = s_item/qtd_item;		// Valor médio do ESTADO obtido a partir dos itens fornecidos pelo usuário
    }
    
    
    			// Revelando irregularidades dos produtos

    		// Estado
    printf(" \n\n");
    printf("================================================================\n");
    printf("\t\t IRREGULARIDADES ENCONTRADAS NO ESTADO\n");
    printf("================================================================\n");
    for (i=0; i<linhas; i++){
        printf("Valor medio no estado do item de valor %.2f\n", m_MedioES[i][0]);
        for (j=2; j<(itens+2); j++){
            for ( k=0; k<1; k++){
                if ((m_dados[i][j] / m_MedioES[i][k]) > 1.2){				// Divisão da matriz de dados pela média estadual
                    printf("\tIRREGULARIDADE no pregao %.0f e valor %.2f\n", m_dados[i][j-2], m_dados[i][j]);
                }
                else{
                	printf("Nenhuma irregularidade no pregao %.0f\n",m_dados[i][j-2]);
                }
            }
        }
    printf("\n");
    }
    
    		// País
    printf(" \n\n");
    printf("=======================================================================\n");
    printf("\t\t IRREGULARIDADES ENCONTRADAS NO PAIS \n");
    printf("=======================================================================\n");

    for (i=0; i<1; i++){
        for (j=2; j<(itens+2); j++){
            printf("\nValor medio no pais do item %d de valor  = %.2f reais\n", j-1, v_MedioN[j-2]);
            for (k=0; k<linhas; k++){
                if ((m_dados[k][j] / v_MedioN[j-2]) > 1.4){				// Divisão da matriz de dados pela média nacional 
                    printf("\tIRREGULARIDADE no pregao %.0f item %d e valor %.2f\n", m_dados[k][j-2],j-1 , m_dados[k][j]);
                }
                else
                	printf("Nenhuma irregularidade no pregao %.0f\n", m_dados[k][j-2]);
            }  
        }
    printf("\n");
    }
    
    // Finalização da Operação Lava Prato
	printf("================================================================\n");
    printf("\t\t FIM DA OPERACAO LAVA PRATO\n");
	printf("================================================================\n");
    return 0;
}
