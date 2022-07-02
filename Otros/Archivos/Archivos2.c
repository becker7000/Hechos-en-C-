#include<stdio.h>

int main(){
	
	FILE* archivo;
	
	archivo = fopen("nuevo.txt","wt");
	
	if(archivo==NULL){
		printf("\n\t El archivo no existe...");
	}else{
		printf("\n\t Archivo disponible...");
	}
	
	float monto=250.67;
	
	fprintf(archivo,"\n\t Escribiendo algo en un archivo, el monto es: %.2f",monto);
	
	
	fclose(archivo);
	return 0;
}






