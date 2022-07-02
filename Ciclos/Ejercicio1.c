#include<stdio.h>

int main(){

	int contador=98; // Variable de control
	int suma=0;
	// 98+93+88+83+..+53
	
	printf("\n\t Suma: ");
	while(contador>=53){ // Condición
		printf(" %d ",contador); // Valores en pantalla
		if(contador!=53) printf("+"); // Ya no sale el '+' despues del 53
		suma+=contador; // Acumula la suma de los valores del contador
		contador-=5; // Resta con paso 5 (Incremento o decremento)
	}
		
	printf(" = %d",suma);
	
	return 0;	
}

/* Abstracción de lo que hace el lenguaje C con un while

    ENTRADAS:
	suma=0
	cont=98
	
	PROCESOS:
	
	cont=98 >= 53? R: Sí
	suma=0+98=98
	cont=98-5=93
	
	cont=93 >= 53? R: Sí
	suma=98+93=192
	cont=93-5=88
	
	cont=88 >= 53? R: Sí
	suma=192+88=279
	cont=88-5=83
	
	...

	cont=53 >= 53? R: Sí
	suma=702+53=755
	cont=53-5=48
	
	cont=48 >= 53? R: NO <- Aquí termina el ciclo While

*/

/*
	Iterar significa repetir, no existe la palabra iterar en el español (RAE)
	porque deriva de una palabra inglésa "Iterate"

	Autor: Jose Luis Lujan 

	Usamos el ciclo while cuando no sabemos exactamente cuantas 
	veces queremos que se itere (repita) un bloque de código pero sí sabemos
	la condición bajo la cúal éste dejará de iterarse... (Condificiones complejas)
	
	En cambio usamos el ciclo for cuando sí sabemos exactamente  
	cuantas veces queremos que se itere un bloque código... (Condiciones sencillas)
	
*/


