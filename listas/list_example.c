#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int edad;
    struct Nodo *siguiente;
}Nodo;

// Función para agregar un Nodo (usando memoria dinamica):
void agregarNodo(Nodo **cabeza, int edad){
    
    // Reservamos espacio en la memoria para un nuevo nodo
    Nodo *nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    Nodo *ultimo = *cabeza; // Paso del valor del apuntador cabeza

    nuevoNodo->edad = edad;
    nuevoNodo->siguiente = NULL;

    // Si la lista está vacía, ya sabemos que el nuevoNodo va a ser la cabeza
    if(*cabeza == NULL){
        *cabeza = nuevoNodo;
        return; // Termina la función (la interrumpe)
    }

    // Algoritmo definitivo para recorrer una lista:
    // Si la lista no está vacía, recorremos hasta el final:
    while(ultimo->siguiente!=NULL){
        ultimo = ultimo->siguiente;
    }

    ultimo->siguiente = nuevoNodo;

}

void imprimirLista(Nodo *nodo){
    while(nodo!=NULL){
        printf("\n\t Edad: %d, siguiente:%p ", nodo->edad, nodo->siguiente);
        nodo = nodo->siguiente; // Esta línea avanza al siguiente nodo...
    }
}

int main(){

    // Creando una lista vacía...
    Nodo *lista = NULL;

    // La vamos pasando la dirección del apuntador (es decir, una dirección de una dirección):
    agregarNodo(&lista, 23);
    agregarNodo(&lista, 21);
    agregarNodo(&lista, 19);
    agregarNodo(&lista, 25); // El siguiente de este Nodo apuntará a NULL

    printf("\n\n\t Lista enlazada: ");
    imprimirLista(lista);

    return 0;

}