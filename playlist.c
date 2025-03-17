#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definimos la estructura de cada nodo de la lista
typedef struct Cancion {
    char titulo[100];
    char artista[100];
    int duracion;  // Duración en segundos
    struct Cancion* siguiente;
    struct Cancion* anterior;
} Cancion;

// Función para crear un nuevo nodo (canción)
Cancion* crearCancion(char* titulo, char* artista, int duracion) {
    Cancion* nuevaCancion = (Cancion*)malloc(sizeof(Cancion));
    if (nuevaCancion == NULL) {
        printf("Error de memoria\n");
        return NULL;
    }
    strcpy(nuevaCancion->titulo, titulo);
    strcpy(nuevaCancion->artista, artista);
    nuevaCancion->duracion = duracion;
    nuevaCancion->siguiente = NULL;
    nuevaCancion->anterior = NULL;
    return nuevaCancion;
}

// Función para agregar una canción al final de la lista
void agregarCancion(Cancion** cabeza, char* titulo, char* artista, int duracion) {
    Cancion* nuevaCancion = crearCancion(titulo, artista, duracion);
    if (*cabeza == NULL) {
        *cabeza = nuevaCancion;
    } else {
        Cancion* temp = *cabeza;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevaCancion;
        nuevaCancion->anterior = temp;
    }
}

// Función para eliminar una canción de la lista
void eliminarCancion(Cancion** cabeza, char* titulo) {
    Cancion* temp = *cabeza;
    while (temp != NULL && strcmp(temp->titulo, titulo) != 0) {
        temp = temp->siguiente;
    }
    if (temp == NULL) {
        printf("Canción no encontrada.\n");
        return;
    }
    if (temp->anterior != NULL) {
        temp->anterior->siguiente = temp->siguiente;
    }
    if (temp->siguiente != NULL) {
        temp->siguiente->anterior = temp->anterior;
    }
    if (temp == *cabeza) {
        *cabeza = temp->siguiente;
    }
    free(temp);
    printf("Canción '%s' eliminada.\n", titulo);
}

// Función para mostrar la lista de canciones desde el principio
void mostrarLista(Cancion* cabeza) {
    Cancion* temp = cabeza;
    if (temp == NULL) {
        printf("La lista está vacía.\n");
        return;
    }
    while (temp != NULL) {
        printf("Título: %s, Artista: %s, Duración: %d segundos\n", temp->titulo, temp->artista, temp->duracion);
        temp = temp->siguiente;
    }
}

// Función para mostrar la lista de canciones desde el final
void mostrarListaReversa(Cancion* cabeza) {
    if (cabeza == NULL) {
        printf("La lista está vacía.\n");
        return;
    }
    // Ir al final de la lista
    Cancion* temp = cabeza;
    while (temp->siguiente != NULL) {
        temp = temp->siguiente;
    }
    // Recorrer la lista hacia atrás
    while (temp != NULL) {
        printf("Título: %s, Artista: %s, Duración: %d segundos\n", temp->titulo, temp->artista, temp->duracion);
        temp = temp->anterior;
    }
}

int main() {
    Cancion* lista = NULL;

    // Agregamos algunas canciones
    agregarCancion(&lista, "Bohemian Rhapsody", "Queen", 355);
    agregarCancion(&lista, "Imagine", "John Lennon", 183);
    agregarCancion(&lista, "Like a Rolling Stone", "Bob Dylan", 360);

    printf("Lista de canciones:\n");
    mostrarLista(lista);

    printf("\nLista de canciones en reversa:\n");
    mostrarListaReversa(lista);

    printf("\nEliminando la canción 'Imagine':\n");
    eliminarCancion(&lista, "Imagine");

    printf("\nLista de canciones después de la eliminación:\n");
    mostrarLista(lista);

    printf("\nLista de canciones en reversa después de la eliminación:\n");
    mostrarListaReversa(lista);

    // Liberar memoria
    while (lista != NULL) {
        eliminarCancion(&lista, lista->titulo);
    }

    return 0;
}
