#include<stdio.h>

// Declaraciones, prototipos o firma:
float pesosADolares(float pesos);
float pesosAEuros(float pesos);

int main(){ // Función principal
	
	float pesos = 20; // Variable de control
	
	printf("\n\t | Pesos \t| Dolares \t| Euros ");
	printf("\n\t ________________________________________");
	while(pesos<=100){ // Condición
		printf("\n\t | $ %.2f \t| $ %.2f \t| E %.2f",pesos,pesosADolares(pesos),pesosAEuros(pesos));
		pesos+=5; // Incremento
	}
	
	return 0;
}

//Definiciones:
float pesosADolares(float pesos){
	float dolares; //Variable temporal o automatica o local
	// Se crea bajo demanda y una vez usada se destruye...
	dolares = 0.050*pesos;
	return dolares;
}

float pesosAEuros(float pesos){
	float euros;
	euros = 0.047*pesos;
	return euros;
}





/* Nota: 
	En el lenguaje C las funciones personalizadas
	se escriben 3 veces:
	1) Cuando se declaran
	2) Cuando se manda a llamar
	3) Cuando se definen

*/
