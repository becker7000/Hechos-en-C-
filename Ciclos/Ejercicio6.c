#include<stdio.h>

int main(){
	
	//La estructura if es la m�s importante
	int edad;
	
	printf("\n\t Dame tu edad: ");
	scanf("%d",&edad);
	
	// Condici�n: edad>=18  -> nos devuelve un verdadero o falso
	if(edad>=18){ // Si la edad es mayor o igual a 18 
		printf("\n\t Puedes votar..."); // esta l�nea
	}else{ // Pero sino se ejecuta el siguiente bloque
		printf("\n\t A�n no puedes votar...");
	}
	
	return 0;
	
}

/*
	Estructuras de control:
	1) Selecci�n: if, if-else, switch
	2) Repetici�n: for, while,do-while

*/
