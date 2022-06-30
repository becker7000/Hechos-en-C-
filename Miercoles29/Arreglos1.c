#include<stdio.h>

int main(){
	
	// Un arreglos es un conjunto de espacios en la memoria
	// que están juntos, así que podemos acceder a cada valor
	// por medio de su dirección:
	
	// Posición : 0, 1, 2, 3, 4, 5
	int edades[] = {21,19,23,18,22,20};
	int i;
	int menor = edades[0];
	int mayor = edades[0];
	float suma = 0, promedio;
	
	for(i=0; i<6; i++){
		printf("\n\t Edad[%d] = %d -> Direccion = %p ",i,edades[i],&edades[i]);
		if(menor>edades[i]){
			menor=edades[i];
		}
		if(mayor<edades[i]){
			mayor=edades[i];
		}
		suma+=edades[i];
	}
	
	promedio=suma/6;
	
	printf("\n\t La edad menor es: %d",menor);
	printf("\n\t La edad mayor es: %d",mayor);
	printf("\n\t El promedio de las edades es: %.2f",promedio);
	
	
	return 0;
	
}
