//Programa que calcula o fatorial de uma quantidade de números definida pelo usuário//
//Assunto: estruturas de repetição for//
//Autor: Luciano Moraes da Luz Brum//
#include<stdio.h>
#include<stdlib.h>
int main(void){
	int entrada[10], saida[10], fatorial, n, i, j;
	printf("Digite quantos numeros voce deseja calcular o fatorial.\n");
	scanf("%d", &n);
	printf("Digite os %d valores para calcular o fatorial.\n", n);
	for(i=0;i<n;i++){
		scanf("%d", &entrada[i]);
	}

	for(i=0;i<n;i++){
		fatorial=1;
		for(j=1;j<=entrada[i];j++){
			fatorial=fatorial*j;
		}
		saida[i]=fatorial;
	    printf("\n\nFatorial do elemento [%d] %d! = %d\n\n", i, entrada[i], saida[i]);
	}
	return 0;
}







