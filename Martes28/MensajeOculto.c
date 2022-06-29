#include<stdio.h>

int main(){
	
	char mensaje[]={'H','o','l','a'};
	int i;
	
	// Cifrando un mensaje: Hola -> Ipmb
	// Cifrado Cesar:
	printf("\n\t Mensaje cifrado: ");
	for(i=0;i<4;i++){
		printf(" %c",(mensaje[i]+3));
	}
	
}
