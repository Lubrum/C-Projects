//Programa que calcula a taxa de transferencia de calor//
//Assunto: variáveis//
//Autor: Luciano Moraes da Luz Brum//
#include <stdio.h>
 int main (){
 	float taxa_calor, h, area, temperatura_superficie, temperatura_fluido, raio, pi;
 	h=10;
 	pi=3.14;

 	printf ("Qual e o raio?");
 	scanf ("%f",&raio);  

 	printf ("Qual e a temperatura da superficie?");
 	scanf ("%f",&temperatura_superficie); 

	area=4*pi*raio*raio;

	printf ("Qual e a temperatura do fluido distante da superficie?"); 
	scanf ("%f",&temperatura_fluido); 

	taxa_calor=h*area*(temperatura_superficie-temperatura_fluido);

	printf ("Quando a temperatura do fluido  e %f, a taxa de transferencia de calor e %f", temperatura_fluido, taxa_calor);  
 	return 0;
}