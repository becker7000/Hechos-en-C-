#include<stdio.h>

int main(){
	
	int i,j;
	
	for(i=1;i<=10;i++){ // Grande
		printf("\n\n");
		printf("\n\t TABLA DEL %d:",i);
		for(j=1;j<=10;j++){ // Chico
			printf("\n\t %d * %d = %d",i,j,(i*j));
		}
	}
	
	return 0;	
}
