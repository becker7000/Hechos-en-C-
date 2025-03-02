#include<stdio.h>
#include<stdlib.h>

#define MAX 100

// Estructura para representar una pila
typedef struct{
    char arreglo[MAX]; // Arreglo para guardar 100 caracteres
    int top; // cima es el índice del último elemento que entró a la pila
}Pila;

// Función para inicializar la pila
void inicializarPila(Pila *p){
    p->top = -1;
}

// Función para verificar si la pila está vacía
int esVacia(Pila *p){
    return p->top == -1;
}

// Función para verificar si la pila está llena
int estaLlena(Pila *p){
    return p->top == MAX-1;
}

void push(Pila *p, char valor){
    if(estaLlena(p)){
        printf("\n\t Error, la pila esta llena. Imposible guardar el valor %c.",valor);
    }else{
        p->arreglo[++(p->top)] = valor;
        printf("\n\t Elemento %c guardado correctamente.",valor);
    }
}

char pop(Pila *p){
    if(esVacia(p)){
        printf("\n\t Error, la pila esta vacia, Imposible eliminar un elemento.");
        return 'v'; // Banderilla que indica que la pila esta vacía...
    }else{
        char valor = p->arreglo[(p->top)--];
        return valor;
    }
}

// Función para acceder al elemento que esta cima
char peek(Pila *p){
    if(esVacia(p)){
        printf("\n\t Error, la pila esta vacia...");
        return -1;
    }else{
        return p->arreglo[p->top];
    }
}

// Función para verificar si los parentesis estan balanceados:
int balancearParentesis(char *expresion){   // "[()()]{()()}"  "}([{()()}])"
    Pila pila;
    inicializarPila(&pila); // Cada que se evalua una expresión se inician la pila nuevamente
    char c;
    // Recorremos la expresión
    int i;
    for(i=0;expresion[i]!='\0';i++){ // ( < '\0' -> 80 < 8 -> falso
        c = expresion[i];
        // Si el caracter es un simbolo de apertura y lo guardamos en la pila
        if(c=='(' || c=='[' || c == '{'){
            push(&pila,c);
        }else if(c==')' || c==']' || c=='}'){ // Si el caracter es un simbolo de cierre, verificamos si coincide con el cima de la pila
            if(esVacia(&pila)){
                return 0; // Expresión no balanceada
            }
            char top = pop(&pila); // Quitamos el ultimo elemento que entró
            // Verificamos si el cierre coincide con la apertura
            if(c==')' && top != '(' || c==']' && top != '[' || c=='}' && top != '{'){ // (),[],{}
                return 0; // Expresión no balanceda
            } // Este if se activa por ejemplo: (()()] -> top es diferente de ']' dado que es ( && c==']'
        }
    }
    return esVacia(&pila); // Los parentesis esta balanceados...
}

void evaluarExpresion(char *expresion){
    if(balancearParentesis(expresion)){
        printf("\n\t La expresion '%s' esta bien balanceada",expresion);
    }else{
        printf("\n\t La expresion '%s' NO esta bien balanceada",expresion);
    }
}

int main(){

    // Haciendo una primera prueba
    char expresion1[] = "{[()()]}";
    char expresion2[] = "{[(]]}";
    
    evaluarExpresion(expresion1);
    evaluarExpresion(expresion2);

    return 0;
}

/*
    Hacer una pila de acciones:
    Accion1 (Escribes "hola")
    Accion2 (Escribes " a")
    Accion3 (Escribes " todos")
    Accion4 (Escribes " amigos")
    Simuliar al funcionamiento del ctrl-z

 */