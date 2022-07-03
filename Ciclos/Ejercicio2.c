#include<stdio.h>

int main(){

	// Potencias de 3 del 2 al 20 de 2 en 2
	// 1) Variable de control 
	// 2) Condición	(límite)
	// 3) Incremento
	
	int i; 
	
	for(i=2;i<=20;i+=2){ // pow es una función 
		printf("\n\t %d^3 = %d",i,i*i*i); // de la librería math.h
	} // y recibe 2 parametros (base,exponente)
	
	
	return 0;
}

/*
	Ciclos simples
	Ciclos con estructuras de control
	Arreglos
	Funciones
	Archivos

*/


/*
	Partir una hoja carta en 8

	Lado A
	¿Cuales son las 3 parte que siempre lleva un ciclo?
	
	Lado B
	1) Variable de control 
	2) Condición (límite)
	3) Incremento 

*/
