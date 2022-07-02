#include<stdio.h>

// Creamos un arreglo A y lo pedimos llenamos 
// con el teclado, lo guardamos en un B pero invertido...

int main(){
	
	int arrayA[5];
	int arrayB[5];
	
	int i;
	for(i=0;i<5;i++){
		printf("\n\t A[%d] = ",i);
		scanf("%d",&arrayA[i]);
	}
	
	printf("\n\t Arreglo A: ");
	for(i=0;i<5;i++){
		printf(" %d",arrayA[i]);
		arrayB[4-i]=arrayA[i]; // 0 1 2 3 4
	}
	
	printf("\n\t Arreglo B: ");
	for(i=0;i<5;i++){
		printf(" %d",arrayB[i]);
	}
	
	return 0;
	
}
