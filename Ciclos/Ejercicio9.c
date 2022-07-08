#include<stdio.h>

void felicitar(); // Declaración: es como aviso a la computadora 

int main(){
	
	felicitar(); // Llamada
	felicitar();
	felicitar();
	
	return 0;
}

// Definición
void felicitar(){
	printf("\n\t Feliz cumpleanios...");
}

/*
	Las funciones son "bloques o subprogramas" de código con un nombre
	Estas tienen la opción de recibir o no recibir "parametros"
	Estaas tiene la opción de dar o no dar un "valor de retorno"
*/
