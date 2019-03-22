//Programa que altera valores digitados pelo usuário//
//Assunto: procedimentos//
//Autor: Luciano Moraes da Luz Brum//
#include<stdio.h>
void altera(int *a, int *b, int *c);
int main(void){
    int a, b, c;
    printf("Digite 3 valores.\n");
    scanf("%d%d%d", &a, &b, &c);
    altera(&a,&b,&c);
    printf("\n\na = %d || b = %d || c = %d\n\n", a, b, c);
    return 0;
}

void altera(int *a, int *b, int *c){
    *a = *a * 2;
    *b = *b * 2;
    *c = *c * 2;
}

