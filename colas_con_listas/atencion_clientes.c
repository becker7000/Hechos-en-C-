#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura de un nodo para representar un cliente en la cola
typedef struct Nodo {
    int turno;
    char nombre[50];
    struct Nodo* siguiente;
} Nodo;

// Estructura de la cola
typedef struct Cola {
    Nodo* frente;  // Cliente en el frente (próximo a ser atendido)
    Nodo* final;   // Cliente en el final de la cola
    int contador;  // Contador de turnos
} Cola;

// Función para crear una cola vacía
Cola* crearCola() {
    Cola* cola = (Cola*)malloc(sizeof(Cola));
    cola->frente = cola->final = NULL;
    cola->contador = 1; // Inicia con turno 1
    return cola;
}

// Función para agregar un cliente a la cola
void agregarCliente(Cola* cola, char nombre[]) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->turno = cola->contador;
    strcpy(nuevoNodo->nombre, nombre);
    nuevoNodo->siguiente = NULL;

    if (cola->final == NULL) {
        cola->frente = cola->final = nuevoNodo;
    } else {
        cola->final->siguiente = nuevoNodo;
        cola->final = nuevoNodo;
    }

    printf("Cliente agregado: %s (Turno %d)\n", nombre, nuevoNodo->turno);
    cola->contador++; // Incrementa el turno para el siguiente cliente
}

// Función para atender al cliente en el frente de la cola
void atenderCliente(Cola* cola) {
    if (cola->frente == NULL) {
        printf("No hay clientes en espera.\n");
        return;
    }

    Nodo* temp = cola->frente;
    printf("Atendiendo a %s (Turno %d)\n", temp->nombre, temp->turno);
    
    cola->frente = cola->frente->siguiente;

    if (cola->frente == NULL) // Si la cola queda vacía
        cola->final = NULL;

    free(temp);
}

// Función para mostrar la lista de clientes en espera
void mostrarCola(Cola* cola) {
    if (cola->frente == NULL) {
        printf("No hay clientes en espera.\n");
        return;
    }

    Nodo* temp = cola->frente;
    printf("Clientes en espera:\n");
    while (temp != NULL) {
        printf("Turno %d - %s\n", temp->turno, temp->nombre);
        temp = temp->siguiente;
    }
}

// Función para liberar la memoria de la cola
void liberarCola(Cola* cola) {
    Nodo* temp;
    while (cola->frente != NULL) {
        temp = cola->frente;
        cola->frente = cola->frente->siguiente;
        free(temp);
    }
    free(cola);
}

int main() {
    Cola* banco = crearCola();
    int opcion;
    char nombre[50];

    do {
        printf("\n🏦 Sistema de Turnos - Banco 🏦\n");
        printf("1. Agregar cliente\n");
        printf("2. Atender cliente\n");
        printf("3. Mostrar cola de espera\n");
        printf("4. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        getchar(); // Limpiar buffer del teclado

        switch (opcion) {
            case 1:
                printf("Ingrese el nombre del cliente: ");
                fgets(nombre, 50, stdin);
                nombre[strcspn(nombre, "\n")] = '\0'; // Eliminar el salto de línea
                agregarCliente(banco, nombre);
                break;
            case 2:
                atenderCliente(banco);
                break;
            case 3:
                mostrarCola(banco);
                break;
            case 4:
                printf("Saliendo del sistema...\n");
                break;
            default:
                printf("Opción inválida, intente de nuevo.\n");
        }
    } while (opcion != 4);

    liberarCola(banco); // Liberar memoria antes de salir
    return 0;
}
