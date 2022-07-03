#include<stdio.h>

int main(){
	
	float pesos;
	float dolares;
	
	printf("\n\n\n\t | Pesos \t| Dolares \t|");
	printf("\n\t _________________________________");
	for(pesos=100;pesos<=150;pesos+=5){
		dolares=pesos*0.049;
		printf("\n\t | $%.2f \t| $%.2f \t|",pesos,dolares);
	}
	
	
	return 0;
}

