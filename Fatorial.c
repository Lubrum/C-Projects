#include<stdio.h>
#include<stdlib.h>
int main(void){
	int a[10], b[10], fat, n, cont, cont2;
	printf("Digite quantos numeros voce deseja calcular o fatorial.\n");
	scanf("%d", &n);
	printf("Digite %d valores para calcular o fatorial deles.\n", n);
	for(cont=0;cont<n;cont++){
		scanf("%d", &a[cont]);
	}

	for(cont=0;cont<n;cont++){
		fat=1;
		for(cont2=1;cont2<=a[cont];cont2++){
			fat=fat*cont2;
		}
		b[cont]=fat;
	    printf("Fatorial do elemento %d [%d]: %d\n", cont, a[cont], b[cont]);
	}
	system("pause");
}







