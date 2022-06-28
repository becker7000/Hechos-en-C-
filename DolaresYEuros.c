#include<stdio.h>

// Prototipo, declaración o firma:
// Nota: es opcional poner nombres a los parametros
// en los prototipos, pero es recomendable para entender mejor
// nuestro código:
float pesosADolares(float pesos,float costo);
float pesosAEuros(float pesos,float costo);

// Nota: todas la funciones en C, se escriben 3 veces en el archivo
// cuando se declaran, cuando se manda a llamar y cuando de define.

int main(){ //Nota: solamente se ejecuta lo que esta en este bloque

	float pesos;
	const float costoDolares, costoEuros;
	printf("\n\t Dame el precio de 1 peso en dolares: ");
	scanf("%f",&costoDolares);
	printf("\n\t Dame el precio de 1 peso en euros: ");
	scanf("%f",&costoEuros);
	
	//Cabera informativa:
	printf("\n\t | Pesos \t| Dolares \t| Euros");
	printf("\n\t _______________________________________");
	for(pesos=20; pesos<=100; pesos+=5){
		printf("\n\t | $ %.2f \t| $ %.2f \t| € %.2f",pesos,pesosADolares(pesos,costoDolares),pesosAEuros(pesos,costoEuros));
	}
	
	return 0;
}

//Definiendo las funciones:
float pesosADolares(float pesos,float costo){
	// Variable automática: se crea y se destruye bajo demanda
	float dolares = costo*pesos; 
	return dolares; //Nota: el tipo de dato de ser igual 
	// al del retorno en el prototipo (float)
}

float pesosAEuros(float pesos, float costo){
	float euros = costo*pesos;
	return euros;
}





