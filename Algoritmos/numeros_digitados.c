//Programa que informa quantos números foram fornecidos pelo usuário//
//Assunto: estruturas de repetição do while//
//Autor: Luciano Moraes da Luz Brum//
#include<stdio.h>
int main(void){
	int n, quantidade;
	quantidade=-1;
	do{
		quantidade=quantidade+1;
		printf("Digite um numero ou 999 para sair\n");
		scanf("%d", &n);
	}
	while(n!=999);
	printf("%d numeros foram digitados\n", quantidade);
	return 0;
}
