#include<stdio.h>
#include<stdlib.h>

#define MAX 10

// Estructura para representar la pila
typedef struct{
    int arreglo[MAX];
    int top;
} Pila;

// Función para inicializar la pila
void inicializarPila(Pila *p){
    p->top = -1; // Iniciamos la pila en -1 para indicar que está vacía.
}

// Función para verificar si la pila es vacía
int esVacia(Pila *p){
    return p->top == -1;
}

// Función para verificar si la pila está llena
int esLlena(Pila *p){
    return p->top == MAX-1;
}

void push(Pila *p, int valor){
    if(esLlena(p)){
        printf("\n\t Error, la pila esta llena. Imposible agregar el valor %d ",valor);
    }else{
        p->arreglo[++(p->top)]=valor; // Aumentamos el índice y agregamos el valor.
        printf("\n\t Elemento %d agregado a la pila correctamente",valor);
    }
}

// Función para eliminar un elemento de la pila
// Recordar que pop elimina el ultimo elemento
// por lo tanto no es necesario pasar ni el valor
// ni el indice del elemento a eliminar
int pop(Pila *p){
    if(esVacia(p)){
        printf("\n\t Error: la pila esta vacia. Imposible eliminar el ultimo elemento.");
        return -1; // Retornamos el valor que indica error.
    }else{
        int valor = p->arreglo[(p->top)--]; // Devolvemos el valor eliminado y decrementamos la cima
        return valor;
    }
}

// Función para ver el elemento de la cima sin eliminarlo (peek)
int peek(Pila *p){
    if(esVacia(p)){
        printf("\n\t Error, la pila esta vacia");
        return -1;
    }else{
        return p->arreglo[p->top];
    }
}

int main(){

    Pila p;
    inicializarPila(&p); // Pasamos por referencia la pila (dirección de la pila)

    // Verificamos si la pila está vacía:
    if(esVacia(&p)){
        printf("\n\t La pila esta vacia...");
    }else{
        printf("\n\t La pila no esta vacia...");
    }

    // Intentamos elimina un elemento de la cima (la pila es vacía actualmente)
    pop(&p);

    // Agregamos algunos valores prueba...
    push(&p,10);
    push(&p,20);
    push(&p,30);

    // Mostramos el elemento en la cima
    printf("\n\t El elemento en la cima es: %d", peek(&p));

    // Eliminamos el elemento en la cima
    printf("\n\t Elemento eliminado: %d",pop(&p));

    // Verificamos si la pila está vacía:
    if(esVacia(&p)){
        printf("\n\t La pila esta vacia...");
    }else{
        printf("\n\t La pila no esta vacia...");
    }   

    push(&p,30);
    push(&p,40);
    push(&p,50);
    push(&p,60);
    push(&p,70);
    push(&p,80);
    push(&p,90);
    push(&p,100);
    push(&p,110);

    return 0;
}