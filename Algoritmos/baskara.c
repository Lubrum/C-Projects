#include <stdio.h>
#include <math.h>
int main (){
	float a, b, c, bask1, bask2, delta, pol;

	printf("Qual o valor de a:\n");
	scanf("%f",&a);
	printf("Qual o valor de b:\n");
	scanf("%f",&b);
	printf("Qual o valor de c:\n");
	scanf("%f",&c);

	printf("Polinomio: %.0f*x*x + %.0f*x + %.0f = 0\n\n", a, b, c);

	delta = (b*b)-(4*a*c);

	if (delta == 0){
		bask1 = ((-b) + sqrt(delta)/(2*a));
		bask2 = ((-b) - sqrt(delta)/(2*a));
		printf("\n\nAs raizes desse polinomio sao iguais: %f e %f.", bask1, bask2);
	}

	if (delta < 0){
		printf("\n\nNao existem raizes reias.");
	}

	if (delta > 0){
		bask1 = ((-b) + sqrt(delta)/(2*a));
		bask2 = ((-b) - sqrt(delta)/(2*a));
		printf("\n\nAs raizes desse polinomio sao %f e %f.",bask1, bask2);
	}

return 0;
}