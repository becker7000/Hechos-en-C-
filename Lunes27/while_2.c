#include<stdio.h>

int main(){
	
	char letra='a'; //Variable de control
	
	// %c c�digo de format, sirven para imprimir datos 
	// o guardar datos, en este caso char
	
	//Nota: \n y \t son secuencias de escape 
	// \n sirve para dar un salto de l�nea
	// \t sirve para dar una tabulaci�n (4 espacios)
	printf("\n\t Alfabeto: ");
	while(letra <='z'){ //Condici�n 
		printf(" %c",letra);
		letra++; //Incremento
	}
	
	return 0;
}
