#include <stdio.h>

int main() {
    // Abrir archivo en modo binario para lectura
    FILE *archivo = fopen("archivo.bin", "rb");
    
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    int numero;  // Variable para almacenar el número leído
    fread(&numero, sizeof(int), 1, archivo);  // Leer el número desde el archivo

    fclose(archivo);  // Cerrar el archivo

    printf("Número leído: %d\n", numero);  // Mostrar el número leído
    return 0;
}
