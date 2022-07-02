#include<stdio.h>

int main(){
	
	int x;
	// El lenguaje C puede calcular factoriales desde 0 hasta 16
	// con el tipo de dato int:
	
	//FILTRO para números entre 1 y 15
	do{ // Este bloque de código será ejecutado mínimo 1 vez:
		system("cls"); //Da una instrucción MS-DOS (CMD)
		printf("\n\t Dame un numero entero entre 0 y 16: ");
		scanf("%d",&x);
	}while(x<0 || x>16);
	
	// Algoritmo para calcular un factorial
	// 0! = 1, 1! = 1 
	// 4! = 4*3*2*1 = 24
	// 6! = 6*5*4*3*2*1 = 720 
	int i;
	// Nota: las multiplicaciones se inician en uno:
	int factorial=1; 
	
	for(i=x; i>0; i--){
		if(x==0){
			factorial=1;
			break; // Rompe con el ciclo for 
		}
		factorial*=i;	
	}
	
	printf("\n\t %d ! = %d",x,factorial);
	
	/*
		x=4
		
		i=4
		factorial=1*4=4
		factorail=4*3
		factorial=12*2
		factorial=24*1=24
		
	*/
	
	// -4,-3,-2,-1,0,1,2,3,4
	// Cuenta del 0 al 10: -2
	
	return 0;
	
}
