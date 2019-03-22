//Programa que simula uma calculadora com as quatro operações básicas: adição, subtração, multiplicação e divisão//
//Assunto: estruturas condicionais Switch//
//Autor: Luciano Moraes da Luz Brum//
#include<stdio.h>
int main(void){
int operando1,operando2,resultado;
char operacao;
printf("Digite o cálculo a ser realizado no formato A + B.\n\n");
scanf("%d %c %d",&operando1,&operacao, &operando2);
fflush(stdin);
switch (operacao) {
    case '+':
		  resultado = operando1 + operando2;
          printf("\n\n%d + %d = %d.", operando1, operando2, resultado);
	break;
	case '-':
	      resultado = operando1 - operando2;
          printf("\n\n%d - %d = %d.", operando1, operando2, resultado);
	      break;
	case '*':
	      resultado = operando1 * operando2;
          printf("\n\n%d * %d = %d.", operando1, operando2, resultado);
	      break;
	case '/':
	      resultado = operando1 / operando2;
          printf("\n\n%d / %d = %d.", operando1, operando2, resultado);
	      break;
	default:
		  printf("Operador inválido !!");
		  break;
}
return 0;
}
