#include<stdio.h>

int main(){
	
	int numero;
	printf("\n\t Dame un numero entero: ");
	scanf("%d",&numero);
	
	int i=1; // Variable de control
	while(i<=10){ //Condición
		printf("\n\t %d * %d = %d",numero,i,(numero*i));
		i++; //Incremento
	}
	
}
