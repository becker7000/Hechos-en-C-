#include<stdio.h>

int main(){
	
	char letra='a'; //Variable de control
	
	// %c código de format, sirven para imprimir datos 
	// o guardar datos, en este caso char
	
	//Nota: \n y \t son secuencias de escape 
	// \n sirve para dar un salto de línea
	// \t sirve para dar una tabulación (4 espacios)
	printf("\n\t Alfabeto: ");
	while(letra <='z'){ //Condición 
		printf(" %c",letra);
		letra++; //Incremento
	}
	
	return 0;
}
