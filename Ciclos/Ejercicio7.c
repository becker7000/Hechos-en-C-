#include<stdio.h>

int main(){
	
	srand(time(NULL)); // Cambia la semilla por cada ejecución
	// La función rand() nos genera números aleatorios
	// entre 0 y 65000 aproximadamente...
	int moneda = rand()%2; // Acorta los posibles valores a 0 o 1
	//printf("\n\t %d",moneda);
	
	printf("\n\t Da click para echar un volado...");
	getch();
	
	if(moneda==0){
		printf("\n\n\t ----> * SOOOOOL *");
	}else{
		printf("\n\n\t ----> * AGUILA *");
	}
	
	printf("\n\n\t Da click para reiniciar el programa...");
	getch(); // Espera que el usuario de click para seguir 
	system("cls"); // Limpia la pantalla
	return main(); // Reinicia el programa
	
}



// semilla=7
// aleatorio=(semilla*6-3)*7-12


