#include<stdio.h>

int main(){
	
	srand(time(NULL)); // Es modificar la semilla 
	// del algoritmo generador de numeros aleatorios
	// para que estos cambien con cada ejecución
	
	//Arreglo bidimensional
	char matrix[3][3]; //Matriz de caracteres de 3x3
	int i,j; //Variables de control
	
	//Llenando una matriz (arreglo de 3x3)
	for(i=0;i<3;i++){ // Este ciclo recorre fila por fila
		for(j=0;j<3;j++){ // Este ciclo recorre columna por columna
			matrix[i][j]=rand()%26+65; // Aunque se guarde un número
			                           // este será manupulo como letra	
		}// semilla 5
	}
	
	//Imprimiendo la matriz en forma de matriz
	printf("\n\t Matriz de letra mayusculas aleatorias de 3x3: ");
	for(i=0;i<3;i++){
		printf("\n\n");
		for(j=0;j<3;j++){
			printf("\t %c",matrix[i][j]);
		}
	}
	
	return 0;
	
	
}
