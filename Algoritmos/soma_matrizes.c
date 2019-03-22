//Programa que soma duas matrizes A e B de tamanho definido pelo usuário//
//Assunto: matrizes//
//Autor: Luciano Moraes da Luz Brum//
#include<stdio.h>
int main(){
	int n,i,j;
	printf("Digite o tamanho das matrizes A e B (N x N).\n");
	scanf("%d", &n);
	int	matriz_a[n][n], matriz_b[n][n],matriz_c[n][n];
	printf("Digite valores para a matriz A.\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d", &matriz_a[i][j]);
		}
	}

	printf("\n\nDigite valores para a matriz b.\n\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d", &matriz_b[i][j]);
		}
	}

	printf("\n\nMatriz resultado.\n\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			matriz_c[i][j] = matriz_a[i][j] + matriz_b[i][j];
			printf("%d ",matriz_c[i][j]);
		}
		printf("\n");
	}
	return 0;
}
