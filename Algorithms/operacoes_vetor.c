//Programa que preenche, modifica e exibe vetores na tela com procedimentos//
//Assunto: procedimentos//
//Autor: Luciano Moraes da Luz Brum//
#include<stdio.h>
void preenche(int vetor[], int n){
	int i;
	printf("Digite valores para o vetor.\n\n");
	for(i=0;i<n;i++){
		scanf("%d",&vetor[i]);
	}
}

void altera(int vetor[], int n){
	int i;
	printf("\n\nModificando valores do vetor...\n\n");
	for(i=0;i<n;i++){
		vetor[i]=vetor[i]*10;
	}
}

void exibir(int vetor[], int n){
	int i;
	printf("Exibindo valores do vetor.\n\n");
	for(i=0;i<n;i++){
		printf("%d  ",vetor[i]);
	}
}

int main(void){
	int tamanho;
	printf("Digite o tamanho do vetor.\n\n");
	scanf("%d", &tamanho);
	int vetor[tamanho];
	preenche(vetor,tamanho);
	altera(vetor,tamanho);
	exibir(vetor,tamanho);
	return 0;
}
