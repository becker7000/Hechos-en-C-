#include<stdio.h>

int main(){
	
	srand(time(NULL)); // Es modificar la semilla 
	// del algoritmo generador de numeros aleatorios
	// para que estos cambien con cada ejecución
	
	//Arreglo bidimensional
	int matrix[3][3];
	int i,j; //Variables de control
	
	//Llenando una matriz (arreglo de 3x3)
	for(i=0;i<3;i++){ // Este ciclo recorre fila por fila
		for(j=0;j<3;j++){ // Este ciclo recorre columna por columna
			matrix[i][j]=rand()%50; // Generamos numeros menores a 50	
		}// semilla 5
	}
	
	//Imprimiendo la matriz en forma de matriz
	printf("\n\t Matriz aleatoria de 3x3: ");
	for(i=0;i<3;i++){
		printf("\n\n");
		for(j=0;j<3;j++){
			printf("\t %d",matrix[i][j]);
		}
	}
	
	return 0;
	
}
