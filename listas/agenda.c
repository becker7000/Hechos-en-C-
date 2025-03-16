#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para almacenar información de un contacto
typedef struct {
    char nombre[50];
    char telefono[20];
    char email[50];
} Contacto;

// Nodo de la lista enlazada
typedef struct Nodo {
    Contacto contacto;
    struct Nodo *siguiente;
} Nodo;

// Función para agregar un contacto a la lista
void agregarContacto(Nodo **cabeza, Contacto nuevoContacto) {
    Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
    nuevoNodo->contacto = nuevoContacto;
    nuevoNodo->siguiente = NULL;

    if (*cabeza == NULL) {
        *cabeza = nuevoNodo;
    } else {
        Nodo *temp = *cabeza;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
    }
}

// Función para mostrar todos los contactos
void mostrarContactos(Nodo *cabeza) {
    Nodo *temp = cabeza;
    while (temp != NULL) {
        printf("Nombre: %s, Teléfono: %s, Email: %s\n", temp->contacto.nombre, temp->contacto.telefono, temp->contacto.email);
        temp = temp->siguiente;
    }
}

// Función para guardar la lista de contactos en un archivo binario
void guardarContactos(Nodo *cabeza, const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "wb");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo para guardar.\n");
        return;
    }

    Nodo *temp = cabeza;
    while (temp != NULL) {
        fwrite(&temp->contacto, sizeof(Contacto), 1, archivo);
        temp = temp->siguiente;
    }

    fclose(archivo);
}

// Función para cargar contactos desde un archivo binario
void cargarContactos(Nodo **cabeza, const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "rb");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo para cargar.\n");
        return;
    }

    Contacto tempContacto;
    while (fread(&tempContacto, sizeof(Contacto), 1, archivo)) {
        agregarContacto(cabeza, tempContacto);
    }

    fclose(archivo);
}

int main() {
    Nodo *listaContactos = NULL;

    // Cargar contactos desde el archivo binario al iniciar
    cargarContactos(&listaContactos, "contactos.bin");

    int opcion;
    do {
        printf("\nMenu:\n");
        printf("1. Agregar contacto\n");
        printf("2. Mostrar contactos\n");
        printf("3. Guardar contactos\n");
        printf("4. Salir\n");
        printf("Opción: ");
        scanf("%d", &opcion);
        getchar();  // Para consumir el salto de línea residual después de scanf

        switch (opcion) {
            case 1: {
                Contacto nuevoContacto;
                printf("Ingrese el nombre: ");
                fgets(nuevoContacto.nombre, sizeof(nuevoContacto.nombre), stdin);
                nuevoContacto.nombre[strcspn(nuevoContacto.nombre, "\n")] = '\0';  // Eliminar salto de línea
                printf("Ingrese el teléfono: ");
                fgets(nuevoContacto.telefono, sizeof(nuevoContacto.telefono), stdin);
                nuevoContacto.telefono[strcspn(nuevoContacto.telefono, "\n")] = '\0';  // Eliminar salto de línea
                printf("Ingrese el email: ");
                fgets(nuevoContacto.email, sizeof(nuevoContacto.email), stdin);
                nuevoContacto.email[strcspn(nuevoContacto.email, "\n")] = '\0';  // Eliminar salto de línea
                agregarContacto(&listaContactos, nuevoContacto);
                break;
            }
            case 2:
                mostrarContactos(listaContactos);
                break;
            case 3:
                guardarContactos(listaContactos, "contactos.bin");
                printf("Contactos guardados.\n");
                break;
            case 4:
                printf("¡Hasta luego!\n");
                break;
            default:
                printf("Opción no válida.\n");
                break;
        }
    } while (opcion != 4);

    // Guardar contactos antes de salir
    guardarContactos(listaContactos, "contactos.bin");

    return 0;
}
