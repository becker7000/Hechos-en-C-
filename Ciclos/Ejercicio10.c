#include<stdio.h> 
// Ciclo while 

int main(){
	
	float suma=0; // Suma de calificaciones
	float nota=0; // Calificacion (variable de control)
	int div=0;
	
	printf("\n\t Escribe tus calificaciones (Nota: -1 para terminar)");
	while(nota!=-1){ // Condici�n compleja
		suma+=nota; /// Sumamos la calificaci�n a la variable suma...
		printf("\n\t Nota: ");
		// Incremento o decremento
		scanf("%f",&nota); // Se guarda de forma temporal una calificaci�n...
		div++;
	}
	
	float promedio=suma/(div-1);
	printf("\n\t Tu promedio es: %.2f",promedio);
	
	return 0;
}
