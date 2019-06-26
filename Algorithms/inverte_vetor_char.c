//Programa que preenche um vetor de letras e inverte em um segundo vetor e exibe na tela o resultado//
//Assunto: vetores//
//Autor: Luciano Moraes da Luz Brum//
#include<stdio.h>
int main(){
	char A[15],B[15];
	int i,j,posicao;
	printf("Digite até 15 letras (digite 0 para interromper a leitura).\n");
	for(i=0;i<15;i++){
		scanf("%c", &A[i]);
		fflush(stdin);
		if(A[i]=='0'){
			A[i]='\0';
			posicao=i-1;
			break;
		}
	}
	for(i=0, j=posicao; i<posicao+1; i++, j--){
		B[j]=A[i];
	}
	printf("\n\nResultado invertido:\n\n");
	for(i=0;i<posicao+1;i++){
		printf("%c", B[i]);
	}
	return 0;
}