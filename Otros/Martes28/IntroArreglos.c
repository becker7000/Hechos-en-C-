#include<stdio.h>

int main(){
	
	// Un arreglo sirve para no tener que declarar
	// muchas variables del mismo tipo:
	// Los arreglos tiene indices, indica la posición
	// de un elemento del arreglo y es independiente del valor
	
	int nums[] = {3,6,9,12,15};
	//posiciones: 0 1 2 3  4
	// Los arreglos tienen lógica cero (contar desde cero)
	// Si un arreglo tiene 5 posiciónes el índice máximo será 4.
	int i;
	for(i=0;i<5;i++){
		printf("\n\t nums[%d] = %d",i,nums[i]);
	}
	
	return 0;
	
}
