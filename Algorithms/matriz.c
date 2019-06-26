//Programa que lê e imprime uma matriz com um número de linhas e colunas definidas pelo usuário//
//Assunto: matrizes//
//Autor: Luciano Moraes da Luz Brum//
#include<stdio.h>
#include<stdlib.h>
int main(void){
	int linha, coluna, numero_colunas, numero_linhas;
	printf("Digite o numero de linhas e colunas da matriz.\n\n");
	scanf("%d%d", &numero_linhas, &numero_colunas);
    int matriz[numero_linhas][numero_colunas];
	printf("\n\nDigite os valores da matriz.\n\n");
	for(linha=0;linha<numero_linhas;linha++){
		for(coluna=0;coluna<numero_colunas;coluna++){
			scanf("%d", &matriz[linha][coluna]);
		}
	}

	printf("\n\n- Impressao da matriz -\n\n");
	for(linha=0;linha<numero_linhas;linha++){
		printf("\n");
		for(coluna=0;coluna<numero_colunas;coluna++){
			printf("%d  ", matriz[linha][coluna]);
		}
	}
	return 0;
}