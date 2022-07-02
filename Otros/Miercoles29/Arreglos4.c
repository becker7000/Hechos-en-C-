#include<stdio.h>

int main(){
	
	//Generando un arreglo de números aleatorios:
	int num[10];
	
	//Llenando el arreglo:
	int i;
	printf("\n\t Arreglo generado: ");
	for(i=0;i<10;i++){
		num[i]=rand()%100; //0 65345
		printf(" %d",num[i]);
	}
	
	//Algoritmo de ordenamiento por el método de la burbuja:
	printf("\n\t Arreglo ordenado: ");
	int j; // 7 4 3 8 9 -> si el tamaño es 5, las comparaciones = 4
	// Comparaciones=4
	// 7>4 Sí -> 4 7 3 8 9
	// 7>3 Sí -> 4 3 7 8 9
	// 7>8 No -> 4 3 7 8 9
	// 8>9 No -> 4 3 7 8 9
	
	//Comparaciones=3
	// 4>3 Sí -> 3 4 7 8 9 El arreglo ya está ordenado
	
	for(i=0;i<10;i++){
		for(j=0;j<9;j++){
			if(num[j]>num[j+1]){
				//Intercambio
				int aux=num[j];
				num[j]=num[j+1];
				num[j+1]=aux;
			}
		}
	}
	
	for(i=0;i<10;i++){
		printf(" %d",num[i]);
	}
	
	
}
