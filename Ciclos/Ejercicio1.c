#include<stdio.h>

int main(){

	int contador=98; // Variable de control
	int suma=0;
	// 98+93+88+83+..+53
	
	printf("\n\t Suma: ");
	while(contador>=53){ // Condici�n
		printf(" %d ",contador); // Valores en pantalla
		if(contador!=53) printf("+"); // Ya no sale el '+' despues del 53
		suma+=contador; // Acumula la suma de los valores del contador
		contador-=5; // Resta con paso 5 (Incremento o decremento)
	}
		
	printf(" = %d",suma);
	
	return 0;	
}

/* Abstracci�n de lo que hace el lenguaje C con un while

    ENTRADAS:
	suma=0
	cont=98
	
	PROCESOS:
	
	cont=98 >= 53? R: S�
	suma=0+98=98
	cont=98-5=93
	
	cont=93 >= 53? R: S�
	suma=98+93=192
	cont=93-5=88
	
	cont=88 >= 53? R: S�
	suma=192+88=279
	cont=88-5=83
	
	...

	cont=53 >= 53? R: S�
	suma=702+53=755
	cont=53-5=48
	
	cont=48 >= 53? R: NO <- Aqu� termina el ciclo While

*/

/*
	Iterar significa repetir, no existe la palabra iterar en el espa�ol (RAE)
	porque deriva de una palabra ingl�sa "Iterate"

	Autor: Jose Luis Lujan 

	Usamos el ciclo while cuando no sabemos exactamente cuantas 
	veces queremos que se itere (repita) un bloque de c�digo pero s� sabemos
	la condici�n bajo la c�al �ste dejar� de iterarse... (Condificiones complejas)
	
	En cambio usamos el ciclo for cuando s� sabemos exactamente  
	cuantas veces queremos que se itere un bloque c�digo... (Condiciones sencillas)
	
*/


