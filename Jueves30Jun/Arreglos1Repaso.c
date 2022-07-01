#include<stdio.h>

/*
	Crear un arreglo de N elementos
	Pedir elemento por elemento
	Imprimir cuantos ceros tiene
	Imprimir cuantos números positivos
	Imprimir cuantos números negativos
	Sumar los negativos e imprimrla
	Sumar lo positivos e imprimirla 
*/

int main(){
	
	// const es una palabra reservada (keyword)
	// nos ayuda a declar un dato constante...
	const int N; // La cantidad de elementos a guarda en el arreglo...
	int i; //Variable de control
	int ceros=0, positivos=0, negativos=0;
	int sumaPos=0, sumaNeg=0; // suma de los positivos y suma de los negativos
	// nota: N=12; //Error por N es const (constante)
	
	// Pedimos cuantos números va a ser ingresados...
	printf("\n\t Escribe cuantos numeros quieres registrar: ");
	scanf("%d",&N); // Se inicializa el valor de N que ya no podrá ser modificado
	
	//Declaramos el arreglo;
	int num[N];
	
	// Todos los arreglos tiene lógica 0: 0,1,2,3
	for(i=0;i<N;i++){
		
		printf("\n\t num[%d] = ",(i+1)); // Lógica 1
		scanf("%d",&num[i]);
	
		// Clasificamos cada dato al mismo que lo vamos capturando:
		if(num[i]==0) ceros++; // Contamos los ceros 
		if(num[i]>0){
			positivos++; // Contamos los positivos
			sumaPos+=num[i]; //Sumamos el número i-ésimo a la sumaPos
		}
		if(num[i]<0){
			negativos++; // Contamos lo negativos
			sumaNeg+=num[i]; // Sumamos el número i-ésimo a la sumaNeg
		}
		
	}
	
	// Mostramos en consola nuestros resultados:
	printf("\n\t Ceros introducidos: %d",ceros);
	printf("\n\t Positivos introducidos: %d",positivos);
	printf("\n\t Negativos introducidos: %d",negativos);
	printf("\n\t La suma de los positivos da: %d",sumaPos);
	printf("\n\t La suma de los negativos da: %d",sumaNeg);
	
	return 0;

}

/*
	Los arreglos en el lenguaje C son fijos o constantes 
	en cuanto a su tamaño, en cambio las listas sí pueden 
	crecer ya que manejan la memoria dinamica (malloc, calloc realloc)
*/
