#include<stdio.h>

void felicitar(); // Declaraci�n: es como aviso a la computadora 

int main(){
	
	felicitar(); // Llamada
	felicitar();
	felicitar();
	
	return 0;
}

// Definici�n
void felicitar(){
	printf("\n\t Feliz cumpleanios...");
}

/*
	Las funciones son "bloques o subprogramas" de c�digo con un nombre
	Estas tienen la opci�n de recibir o no recibir "parametros"
	Estaas tiene la opci�n de dar o no dar un "valor de retorno"
*/
