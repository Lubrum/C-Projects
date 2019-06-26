//Programa que calcula o fatorial de um número definido pelo usuário//
//Assunto: funções//
//Autor: Luciano Moraes da Luz Brum//
#include<stdio.h>
int fatorial(int n){
	int i, fatorial;
	fatorial=1;
	for(i=1;i<=n;i++){
		fatorial=fatorial*i;
	}
	return fatorial;
}

int main(void){
	int n, resultado;
	printf("Digite o valor para calcular o fatorial.\n\n");
	scanf("%d", &n);
	resultado=fatorial(n);
	printf("\n\nO fatorial de %d eh: %d", n, resultado);
	return 0;
}
