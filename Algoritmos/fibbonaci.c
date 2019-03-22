//Programa que apresenta a série de fibbonaci até o valor limite informado pelo usuário//
//Assunto: estruturas de repetição While Do//
//Autor: Luciano Moraes da Luz Brum//
#include<stdio.h>
#include<stdlib.h>
int main(void){
	int antecessor, atual, sucessor, limite;
	printf("Digite o numero limite para a serie de Fibonacci.\n\n");
	scanf("%d", &limite);
	antecessor=0;
	atual=1;
	sucessor=antecessor+atual;
	printf("-  ");
	while(sucessor<=limite){
		printf("%d  -  ", sucessor);
		antecessor=atual;
		atual=sucessor;
		sucessor=antecessor+atual;
	}
	return 0;
}


