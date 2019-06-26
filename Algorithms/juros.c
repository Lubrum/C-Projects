//Programa que, informando o capital inicial e a taxa de juros, calcula quantos anos leva para atingir o valor de R$ 20.000,00//
//Assunto: estruturas de repetição for//
//Autor: Luciano Moraes da Luz Brum//
#include<stdio.h>
int main(){
	float juros, capital;
	int i;
	printf("Digite o capital inicial e a taxa de juros (Ex: 15000 e 5).\n");
	scanf("%f%f", &capital, &juros);
	juros=juros/100.0;
	for(i=0;i<=20000;i++){
		capital = capital + (capital*juros);
		if(capital>=20000){
			break;
		}
	}
	printf("\nPara ter R$ 20.000,00, levara %d anos.\n", i/12);
	return 0;
}
