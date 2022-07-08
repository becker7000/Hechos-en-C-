#include<stdio.h>

int main(){
	
	//La estructura if es la más importante
	int edad;
	
	printf("\n\t Dame tu edad: ");
	scanf("%d",&edad);
	
	// Condición: edad>=18  -> nos devuelve un verdadero o falso
	if(edad>=18){ // Si la edad es mayor o igual a 18 
		printf("\n\t Puedes votar..."); // esta línea
	}else{ // Pero sino se ejecuta el siguiente bloque
		printf("\n\t Aún no puedes votar...");
	}
	
	return 0;
	
}

/*
	Estructuras de control:
	1) Selección: if, if-else, switch
	2) Repetición: for, while,do-while

*/
