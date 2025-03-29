#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura de un nodo del árbol
typedef struct Nodo {
    int valor;              // Valor que almacena el nodo
    struct Nodo* izquierda; // Puntero al subárbol izquierdo
    struct Nodo* derecha;   // Puntero al subárbol derecho
} Nodo;

// Función para crear un nuevo nodo
Nodo* nuevo_nodo(int valor) {
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));  // Asignamos memoria para el nodo
    nodo->valor = valor;                       // Asignamos el valor al nodo
    nodo->izquierda = NULL;                    // Inicializamos el hijo izquierdo como NULL
    nodo->derecha = NULL;                      // Inicializamos el hijo derecho como NULL
    return nodo;
}

// Recorrido en preorden (Nodo, Izquierda, Derecha)
void recorrer_preorden(Nodo* raiz) {
    if (raiz == NULL) {
        return; // Si el nodo es NULL, terminamos
    }
    printf("%d ", raiz->valor); // Primero imprimimos el valor del nodo
    recorrer_preorden(raiz->izquierda); // Recorremos el subárbol izquierdo
    recorrer_preorden(raiz->derecha);   // Recorremos el subárbol derecho
}

// Recorrido en inorden (Izquierda, Nodo, Derecha)
void recorrer_inorden(Nodo* raiz) {
    if (raiz == NULL) {
        return; // Si el nodo es NULL, terminamos
    }
    recorrer_inorden(raiz->izquierda); // Recorremos el subárbol izquierdo
    printf("%d ", raiz->valor);        // Imprimimos el valor del nodo
    recorrer_inorden(raiz->derecha);   // Recorremos el subárbol derecho
}

// Recorrido en postorden (Izquierda, Derecha, Nodo)
void recorrer_postorden(Nodo* raiz) {
    if (raiz == NULL) {
        return; // Si el nodo es NULL, terminamos
    }
    recorrer_postorden(raiz->izquierda); // Recorremos el subárbol izquierdo
    recorrer_postorden(raiz->derecha);   // Recorremos el subárbol derecho
    printf("%d ", raiz->valor);          // Finalmente imprimimos el valor del nodo
}

int main() {
    // Crear algunos nodos manualmente para formar el árbol binario
    Nodo* raiz = nuevo_nodo(1);  // Nodo raíz con valor 1
    raiz->izquierda = nuevo_nodo(2);  // Subárbol izquierdo con valor 2
    raiz->derecha = nuevo_nodo(3);   // Subárbol derecho con valor 3

    raiz->izquierda->izquierda = nuevo_nodo(4);  // Subárbol izquierdo del nodo 2
    raiz->izquierda->derecha = nuevo_nodo(5);    // Subárbol derecho del nodo 2

    printf("Recorrido en preorden del árbol binario: ");
    recorrer_preorden(raiz); // Imprime los valores del árbol en preorden
    printf("\n");

    printf("Recorrido en inorden del árbol binario: ");
    recorrer_inorden(raiz); // Imprime los valores del árbol en inorden
    printf("\n");

    printf("Recorrido en postorden del árbol binario: ");
    recorrer_postorden(raiz); // Imprime los valores del árbol en postorden
    printf("\n");

    // Liberar memoria (en un programa más grande, se debe liberar todos los nodos)
    free(raiz->izquierda->izquierda);
    free(raiz->izquierda->derecha);
    free(raiz->izquierda);
    free(raiz->derecha);
    free(raiz);

    return 0;
}

/*
Tipo de Recorrido   	Orden de Visita	Resultado para el árbol dado
Preorden	         Raíz -> Izquierda -> Derecha	4 2 1 3 6 5 7
Inorden	Izquierda -> Raíz -> Derecha	1 2 3 4 5 6 7
Postorden	Izquierda -> Derecha -> Raíz	1 3 2 5 7 6 4

*/