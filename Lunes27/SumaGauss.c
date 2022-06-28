#include<stdio.h>

// 1+2+3+4+5=15
// 1+2+3+...+100=5050

int main(){
	
	int contador=1; // 1,2,3,4,5,..,100  <- variable de control
	int suma=0; //Nota: las sumas inician en 0
	
	while(contador<=100){ // Condición
		suma+=contador;
		printf("\n\t %d",suma);
		contador++; // Incremento
	}
	
	printf("\n\t La suma de Gauss del 1 al 100 es: %d",suma);
	
	return 0;
}
