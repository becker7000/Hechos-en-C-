#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura para una tarea
struct Tarea {
    char descripcion[100];  // Cadena para almacenar la descripción de la tarea
    struct Tarea* siguiente; // Puntero al siguiente nodo de la lista
};

// Función para agregar una tarea a la lista
void agregarTarea(struct Tarea** cabeza, char* descripcion) {
    struct Tarea* nuevaTarea = (struct Tarea*)malloc(sizeof(struct Tarea)); // Crear un nuevo nodo de tarea
    strcpy(nuevaTarea->descripcion, descripcion); // Copiar la descripción de la tarea al nuevo nodo
    nuevaTarea->siguiente = *cabeza; // Hacer que el nuevo nodo apunte al anterior nodo (si existe)
    *cabeza = nuevaTarea; // El nuevo nodo pasa a ser la cabeza de la lista
}

// Función para eliminar una tarea de la lista
void eliminarTarea(struct Tarea** cabeza, char* descripcion) {
    struct Tarea* temp = *cabeza; // Apuntar al inicio de la lista
    struct Tarea* previo = NULL;  // Puntero para almacenar el nodo anterior
    
    // Si la tarea a eliminar está en la cabeza de la lista
    if (temp != NULL && strcmp(temp->descripcion, descripcion) == 0) {
        *cabeza = temp->siguiente; // Mover la cabeza de la lista al siguiente nodo
        free(temp); // Liberar la memoria del nodo eliminado
        printf("Tarea eliminada correctamente.\n");
        return;
    }

    // Buscar la tarea en el resto de la lista
    while (temp != NULL && strcmp(temp->descripcion, descripcion) != 0) {
        previo = temp; // Mover el puntero previo al nodo actual
        temp = temp->siguiente; // Mover al siguiente nodo
    }

    // Si la tarea no se encuentra
    if (temp == NULL) {
        printf("Tarea no encontrada.\n");
        return;
    }

    // Eliminar la tarea encontrada
    previo->siguiente = temp->siguiente; // Saltar el nodo que se va a eliminar
    free(temp); // Liberar la memoria del nodo eliminado
    printf("Tarea eliminada correctamente.\n");
}

// Función para mostrar todas las tareas en la lista
void mostrarTareas(struct Tarea* cabeza) {
    struct Tarea* temp = cabeza; // Apuntar al inicio de la lista
    if (temp == NULL) {
        printf("No hay tareas en la lista.\n"); // Si la lista está vacía, informar al usuario
        return;
    }
    printf("Lista de tareas:\n");
    // Recorrer la lista y mostrar cada tarea
    while (temp != NULL) {
        printf("- %s\n", temp->descripcion); // Imprimir la descripción de cada tarea
        temp = temp->siguiente; // Mover al siguiente nodo
    }
}

int main() {
    struct Tarea* listaDeTareas = NULL; // Inicializar la lista de tareas (cabeza de la lista es NULL)
    int opcion; // Variable para almacenar la opción seleccionada en el menú
    char descripcion[100]; // Cadena para almacenar la descripción de la tarea

    do {
        // Mostrar el menú de opciones
        printf("\n--- Menú de tareas ---\n");
        printf("1. Agregar tarea\n");
        printf("2. Ver tareas\n");
        printf("3. Eliminar tarea\n");
        printf("4. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion); // Leer la opción seleccionada por el usuario
        getchar();  // Limpiar el salto de línea residual que queda en el buffer después de leer un número

        switch (opcion) {
            case 1:
                // Agregar tarea
                printf("Ingrese la descripción de la tarea: ");
                fgets(descripcion, sizeof(descripcion), stdin); // Leer la descripción de la tarea
                // Explicación de fgets:
                // fgets(descripcion, sizeof(descripcion), stdin);
                // descripcion: es el arreglo donde se almacenará la cadena leída.
                // sizeof(descripcion): es el tamaño máximo de caracteres que se leerán, asegurando que no se desborde el arreglo.
                // stdin: especifica que la entrada proviene del teclado.
                descripcion[strcspn(descripcion, "\n")] = '\0'; // Eliminar el salto de línea al final de la cadena
                agregarTarea(&listaDeTareas, descripcion); // Agregar la tarea a la lista
                printf("Tarea agregada correctamente.\n");
                break;
            case 2:
                // Ver tareas
                mostrarTareas(listaDeTareas); // Mostrar todas las tareas almacenadas en la lista
                break;
            case 3:
                // Eliminar tarea
                printf("Ingrese la descripción de la tarea a eliminar: ");
                fgets(descripcion, sizeof(descripcion), stdin); // Leer la descripción de la tarea a eliminar
                descripcion[strcspn(descripcion, "\n")] = '\0'; // Eliminar el salto de línea al final de la cadena
                eliminarTarea(&listaDeTareas, descripcion); // Eliminar la tarea de la lista
                break;
            case 4:
                // Salir del programa
                printf("Saliendo del programa...\n");
                break;
            default:
                // Opción inválida
                printf("Opción inválida. Intente de nuevo.\n");
                break;
        }
    } while (opcion != 4); // Continuar mostrando el menú hasta que se seleccione la opción 4 (salir)

    return 0;
}
