#include <stdio.h>

int main() {
    // Abrir archivo en modo binario para escritura
    FILE *archivo = fopen("archivo.bin", "wb");
    
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    int numero = 12345;  // Número que queremos escribir en el archivo
    fwrite(&numero, sizeof(int), 1, archivo);  // Escribir el número binariamente

    fclose(archivo);  // Cerrar el archivo

    printf("Número escrito en archivo.bin\n");
    return 0;
}
