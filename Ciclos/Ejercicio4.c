#include<stdio.h>

int main(){
	
	/* 
	   Construye un programa que muestre los siguientes
	   números: 1/2, 1/4,...,1/20 usando while...
	*/
	
	int denominador=2;//Variable de control

	printf("\n\t Sucesion: ");
	while(denominador<=20){ // Condición
		printf(" 1/%d",denominador);
		denominador+=2; // Incremento
	}
	
	return 0;
}
