//Programa que identifica as pessoas com mais de 18 anos de um grupo de dez pessoas//
//Assunto: vetores//
//Autor: Luciano Moraes da Luz Brum//
#include<stdio.h>
#include<stdlib.h>
int main(void){
	int idades[10], i, quantidade;
	printf("Digite a idade de 10 pessoas\n\n");
	quantidade = 0;
	for(i=0;i<=9;i++){		
		scanf("%d", &idades[i]);
		if(idades[i]>=18){
			quantidade++;
		}
	}
	printf("\n\n%d pessoas sao maiores de idade.\n", quantidade);
	return 0;
}

