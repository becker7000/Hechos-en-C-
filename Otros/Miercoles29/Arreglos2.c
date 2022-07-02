#include<stdio.h>
/*
	Ejercicio: crear un arreglo de 5 elementos
	y entonces verificar si alguno de sus elementos
	es la suma del resto de ellos.
	
	45, 3, 20, 2, 20
	suma = 90
	90-45  = 3+20+2+20 ? Sí
*/
int main(){

	//Declarando un arreglo que vamos a llenar
	int arreglo[5];
	int i,suma=0;
	//Banderilla
	int banderilla=0; // Es falso que se ha encontrado el número especial

	for(i=0;i<5;i++){
		printf("\n\t a[%d] = ",i);
		scanf("%d",&arreglo[i]);
		suma+=arreglo[i];
	}
	
	for(i=0;i<5;i++){
		if((suma-arreglo[i])==arreglo[i]){
			printf("\n\t %d es la suma de los otros numeros",arreglo[i]);
			printf("\n\t El elemento esta en el indice: %d",i);
			banderilla=1;
			break; // break termina con la repeticiones 
			//una vez que encontramos lo que estamos buscando...
		}
	}
	
	if(banderilla==0){
		printf("\n\t Ningun numero es la suma de el resto de ellos...");
	}
	
	return 0;
}
	
