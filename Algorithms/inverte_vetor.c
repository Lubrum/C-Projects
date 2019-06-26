//Programa que inverte os valores em um vetor de dez posições//
//Assunto: vetores//
//Autor: Luciano Moraes da Luz Brum//
#include<stdio.h>
#include<stdlib.h>
int main(void){
	int vetor[10], auxiliar, i;
	printf("Digite 10 valores para inverte-los no mesmo vetor.\n\n");
	for(i=0;i<=9;i++){
		scanf("%d", &vetor[i]);
	}

	printf("\n\nVetor Original\n\n");
	for(i=0;i<=9;i++){
		printf("%d - ", vetor[i]);
	}

	for(i=0;i<=4;i++){
		auxiliar=vetor[i];
		vetor[i]=vetor[9-i];
		vetor[9-i]=auxiliar;
	}

	printf("\n\nVetor Invertido\n\n");
	for(i=0;i<=9;i++){
		printf("%d - ", vetor[i]);
	}

return 0;
}
