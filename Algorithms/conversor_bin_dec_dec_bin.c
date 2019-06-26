//Programa que converte números de binário para decimal ou vice-versa//
//Assunto: estruturas de repetição e condição//
//Autor: Luciano Moraes da Luz Brum//
#include<stdio.h>
#include<stdlib.h>
int main(void){
	int menu, numero, quociente, resto, binario[8], posicao, i, digitos, valor_bit, resultado;
    do{
		printf("\n\nDigite: \n1 para transformar de decimal para binario.\n2 para transformar de binario para decimal.\n999 para sair.\n");
		scanf("%d", &menu);
		switch (menu){
			case 1: {
				printf("\nDigite o numero que voce quer converter.\n");
				scanf("%d", &numero);
				posicao=0;
				while(numero!=0){
					quociente=numero/2;
					resto=numero%2;
					numero=quociente;
					binario[posicao]=resto;
					posicao++;
				}
				posicao--;
				printf("\nResultado:  ");
				while(posicao>=0){
					printf("%d ", binario[posicao]);
					posicao--;
				}
			break;
			}

			case 2: {
				printf("\n\nDigite a quantidade de digitos do numero em binario.\n\n");
				scanf("%d", &digitos);
				int binario_2[digitos];
				printf("\n\nEscreva cada digito do seu numero em binario.\n\n");
				for(i=0;i<digitos;i++){
					scanf("%d", &binario_2[i]);
					while(binario_2[i]!=0&&binario_2[i]!=1){
						printf("\n\nErro, por favor digite os valores 0 ou 1.\n\n");
						scanf("%d", &binario_2[i]);
					}
				}
				valor_bit=1;
				numero=0;
				resultado=0;
				for(i=digitos-1;i>=0;i--){
					numero=binario_2[i]*valor_bit;
					valor_bit=valor_bit*2;
					resultado=resultado+numero;
				}
				printf("\nNumero convertido para decimal: %d.\n",resultado);
				break;
			}

			case 999: {
				printf("\n\nVoce saiu do programa""\n\n");
				break;
			}
		}
	}
	while(menu!=999);
	return 0;
}





