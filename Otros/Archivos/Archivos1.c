#include<stdio.h>
#define direccion "Hola.txt"
#define PI 3.1416 // Constante de tipo definida

int main(){
	
	// FILE es un apuntador de tipo archivo...
	// Un apuntador es una variable que guarda
	// la dirección de un espacio...
	
	FILE* archivo; // Declaración
	// Este apuntador alamcena algo así: 0000000B5E993C
	
	// fopen -> file open
	// Modos de apetura de un archivo 
	// r -> significa read (sólo lectura)
	// w -> significa write (sólo escritura)
	// wt -> significa write 
	archivo = fopen(direccion,"r");
	
	// NULL es un valor que puede tomar un apuntador
	// %p es el código de formato para imprimir una dirección 
	// de memoria en la consola
	printf("\n\t Valor del apuntador: %p", archivo);
	
	// Se considera buena practica lanzar una mensaje
	// en caso de que archivo no exista...
	if(archivo==NULL){
		printf("\n\t Archivo no encontrado...");
	}else{
		printf("\n\t Archivo disponible...");
	}
	
	// Ejemplo con un número flotante
	// printf("\n\t PI: %f",PI);
	
	// Esta variable va a ir guardando cada caracter 
	// contenido en el archivo..
	char letra;
	int caracteres=0;
	
	printf("\n\n\t Archivo: \n\n");
	while(letra!=EOF){ //EOF significa End Of File
		letra = fgetc(archivo); // Se va leyendo caracter por caracter 
		printf("%c",letra);
		caracteres++;
	}
	
	printf("\n\n\tEste archivo tiene: %d caracteres...",caracteres);
	
	// Cerramos el archivo
	fclose(archivo);
	
	
	return 0;
	
}
