#include<stdio.h>

int main(){
	
	float pesos = 20; // Variable de control
	float dolares, euros;
	
	printf("\n\t | Pesos \t| Dolares \t| Euros ");
	printf("\n\t ________________________________________");
	while(pesos<=100){ // Condición
		dolares=0.050*pesos; // 40*0.050
		euros=0.047*pesos; // 40*0.047
		printf("\n\t | $ %.2f \t| $ %.2f \t| E %.2f",pesos,dolares,euros);
		pesos+=5; // Incremento
	}
	
	return 0;
}
