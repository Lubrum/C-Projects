//Programa que identifica o maior elemento do vetor e sua posição//
//Assunto: vetores//
//Autor: Luciano Moraes da Luz Brum//
#include<stdio.h>
int main(){
	int maior, tamanho, i, posicao_maior;
	printf("Digite o tamanho do seu vetor.\n\n");
	scanf("%d", &tamanho);
	int vetor[tamanho];
	printf("\n\nPreencha o seu vetor.\n\n");
	for(i=0;i<tamanho;i++){
		scanf("%d", &vetor[i]);
	}
	maior=0;
	printf("\n\n Exibindo o seu vetor.\n\n");
	for(i=0;i<tamanho;i++){
			printf("%d :: ", vetor[i]);
			if(vetor[i]>maior){
				maior=vetor[i];
				posicao_maior=i;
			}
	}
	printf("\n\nO maior elemento do vetor e %d na posicao %d.\n", maior, posicao_maior);
	return 0;
}