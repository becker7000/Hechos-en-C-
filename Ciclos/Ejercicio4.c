#include<stdio.h>

int main(){
	
	/* 
	   Construye un programa que muestre los siguientes
	   n�meros: 1/2, 1/4,...,1/20 usando while...
	*/
	
	int denominador=2;//Variable de control

	printf("\n\t Sucesion: ");
	while(denominador<=20){ // Condici�n
		printf(" 1/%d",denominador);
		denominador+=2; // Incremento
	}
	
	return 0;
}
