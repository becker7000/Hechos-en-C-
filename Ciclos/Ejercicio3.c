#include<stdio.h>

int main(){
	
	// 8, 40, 200, 1000, 5000, ... , 125000
	// 8x5 = 40 
	// 40x5 = 200
	// 200x5 = 1000
	
	int x=8; // Variable de control

	printf("\n\t Sucesion: ");
	do{ // Comunmente do-while lo usamos como filtro 
		printf(" %d",x); // Se imprime el valor de x
		x*=5; // Múltiplicamos x por 5 (x=x*5) Incremento
	}while(x<=125000); // Condición
		
	return 0;
}

/*
	La estructura do-while siempre ejecutará su bloque 
	de código por lo menos 1 vez...
*/



