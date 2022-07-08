#include<stdio.h>

int main(){
	
	printf("\n\t Llena el arreglo con 5 numeros...\n");
	// Arreglo de tamaño 5
	int enteros[5];
	int ceros=0,positivos=0,negativos=0;
	int sumaPos=0, sumaNeg=0;
	
	//LLENAMOS EL ARREGLO
	int i; // Variable de control
	for(i=0;i<5;i++){ // Condición e incremento
		printf("\t entero #%d: ",i);
		scanf("%d",&enteros[i]);
		// Clasificamos los números como: ceros, positivos y negativos
		if(enteros[i]==0){
			ceros++; //Incrementamos la variable ceros
		}
		if(enteros[i]>0){
			positivos++;
			sumaPos+=enteros[i];
		}
		if(enteros[i]<0){
			negativos++;
			sumaNeg+=enteros[i];
		}
		
	}
	
	//IMPRIMIMOS EL ARREGLO
	printf("\n\t Valores del arreglo: ");
	for(i=0;i<5;i++){
		printf(" %d",enteros[i]);
	}
	
	printf("\n\t Ceros: %d",ceros);
	printf("\n\t Positivos: %d",positivos);
	printf("\n\t Negativos: %d",negativos);
	printf("\n\t Suma de los positivos: %d",sumaPos);
	printf("\n\t Suma de los negativos: %d",sumaNeg);
	
	return 0;
}

/*
	Crear un arreglo que guarde 5 números enteros
	Pedir al usuario número por número
	
	1) Imprimir en consola cuantos ceros fueron capturados
	2) Imprimir en consola cuantos positivos fueron capturados
	3) Imprimir en consola cuantos negativos fueron capturados
	4) Imprimir en consola la suma de los positivos
	5) Imprimir en consola la suma de los negativos

*/
