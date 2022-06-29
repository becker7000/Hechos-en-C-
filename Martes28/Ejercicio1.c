#include<stdio.h>

int main(){

	int x=1; // Variable
	
	while(x<=12){ // Condición
		
		// Estructura de control por selección
		if(x%2==0){ // %d es el código de formato para entero
			printf("\n\t x = %d es par",x);
		}else{
			printf("\n\t x = %d es impar",x);	
		}
		x++; // Incremento
	}

	// 11%7=4, 5%2=1, 20%8=4
	// 12%5=2, 15%9=6, 30%4=2
	
	return 0;
}


/*
	Estructuras de control: 
	
	Son estructuras que nos ayudan a darle flujo a código 
	según nuestros algoritmos.
	
	Existen dos tipos de estructuras de control:
	1) Control por selección: if, if-else, switch...
	2) Control por repetición: for, while, do-while...

*/
