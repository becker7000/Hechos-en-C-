#include<stdio.h>
#define NOMBRE "informe.txt"

int main(){
	
	float monto;
	FILE* archivo; // Apuntador
	
	printf("\n\t Escribe un monto: ");
	scanf("%f",&monto);
	
	Sleep(2000);
	printf("\n\t El monto sin IVA es: %.2f",monto);
	Sleep(2000);
	printf("\n\t El monto con IVA es: %.2f",monto*1.16);
	Sleep(2000);
	// %s es el código de formato usado para imprir cadena (secuencias de caracteres).
	printf("\n\t Escribiendo informe en el archivo %s",NOMBRE);
	
	// Esta línea abre un archivo para sobreescribir en el
	// sin embargo, en caso de no existir, lo crear primero...
	archivo=fopen(NOMBRE,"wt");
	
	Sleep(3000);
	if(archivo==NULL){
		printf("\n\t Archivo no disponible...");
	}else{
		printf("\n\t Procesando archivo...");
	}
	
	fprintf(archivo,"\n\t El monto sin IVA es: %.2f",monto);
	fprintf(archivo,"\n\t El monto con IVA es: %.2f",monto*1.16);
	
	Sleep(2000);
	printf("\n\t El informe se genero correctamente en el archivo...");
	
	fclose(archivo);
	
	return 0;
}



