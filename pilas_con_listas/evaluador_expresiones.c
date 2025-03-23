#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Estructura de la pila para operadores y operandos
typedef struct Pila {
    char *arr;
    int top;
    int capacity;
} Pila;

// Función para crear la pila
Pila* crear_pila(int capacity) {
    Pila *pila = (Pila*)malloc(sizeof(Pila));
    pila->capacity = capacity;
    pila->top = -1;
    pila->arr = (char*)malloc(pila->capacity * sizeof(char));
    return pila;
}

// Función para verificar si la pila está vacía
int es_vacia(Pila *pila) {
    return pila->top == -1;
}

// Función para agregar un elemento a la pila
void apilar(Pila *pila, char valor) {
    if (pila->top == pila->capacity - 1) {
        printf("¡Pila llena!\n");
        return;
    }
    pila->arr[++(pila->top)] = valor;
}

// Función para sacar un elemento de la pila
char desapilar(Pila *pila) {
    if (es_vacia(pila)) {
        return -1; // Si la pila está vacía
    }
    return pila->arr[(pila->top)--];
}

// Función para ver el elemento en la cima de la pila sin eliminarlo
char cima(Pila *pila) {
    if (es_vacia(pila)) {
        return -1; // Si la pila está vacía
    }
    return pila->arr[pila->top];
}

// Función para obtener la precedencia de los operadores
int precedencia(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Función para aplicar el operador a dos operandos
int aplicar(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    return 0;
}

// Función que evalúa una expresión infija usando una pila
int evaluar_expresion(char* expr) {
    Pila* pila_valores = crear_pila(100);  // Pila para operandos
    Pila* pila_operadores = crear_pila(100);  // Pila para operadores

    for (int i = 0; expr[i] != '\0'; i++) {
        // Si es un espacio, ignoramos
        if (expr[i] == ' ') continue;

        // Si es un número, lo apilamos
        if (isdigit(expr[i])) {
            int valor = 0;
            while (isdigit(expr[i])) {
                valor = valor * 10 + (expr[i] - '0');
                i++;
            }
            i--;  // Para deshacer el incremento extra
            apilar(pila_valores, valor);  // Apilamos el valor
        }
        // Si es un operador
        else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
            while (!es_vacia(pila_operadores) && precedencia(cima(pila_operadores)) >= precedencia(expr[i])) {
                char op = desapilar(pila_operadores);
                int b = desapilar(pila_valores);
                int a = desapilar(pila_valores);
                apilar(pila_valores, aplicar(a, b, op));  // Apilamos el resultado de la operación
            }
            apilar(pila_operadores, expr[i]);  // Apilamos el operador
        }
        // Si es un paréntesis de apertura
        else if (expr[i] == '(') {
            apilar(pila_operadores, expr[i]);
        }
        // Si es un paréntesis de cierre
        else if (expr[i] == ')') {
            while (cima(pila_operadores) != '(') {
                char op = desapilar(pila_operadores);
                int b = desapilar(pila_valores);
                int a = desapilar(pila_valores);
                apilar(pila_valores, aplicar(a, b, op));  // Apilamos el resultado de la operación
            }
            desapilar(pila_operadores);  // Eliminamos el paréntesis de apertura
        }
    }

    // Procesamos los operadores restantes
    while (!es_vacia(pila_operadores)) {
        char op = desapilar(pila_operadores);
        int b = desapilar(pila_valores);
        int a = desapilar(pila_valores);
        apilar(pila_valores, aplicar(a, b, op));  // Apilamos el resultado de la operación
    }

    // El resultado final es el único valor restante en la pila de valores
    int resultado = desapilar(pila_valores);

    // Liberamos la memoria de las pilas
    free(pila_valores->arr);
    free(pila_valores);
    free(pila_operadores->arr);
    free(pila_operadores);

    return resultado;
}

int main() {

    char expresion[100];
    
    // Solicitar al usuario la expresión matemática
    printf("Introduce una expresión matemática: ");
    fgets(expresion, sizeof(expresion), stdin);
    expresion[strcspn(expresion,"\n")]='\0';
    
    // Evaluar la expresión y mostrar el resultado
    int resultado = evaluar_expresion(expresion);
    printf("El resultado de la expresión '%s' es: %d", expresion, resultado);

    return 0;
}

/*
3 → Apilar en pila_valores: [3]

+ → Apilar en pila_operadores: [+]

5 → Apilar en pila_valores: [3, 5]

* → Apilar en pila_operadores: [+, *]

( → Apilar en pila_operadores: [+, *, (]

2 → Apilar en pila_valores: [3, 5, 2]

- → Apilar en pila_operadores: [+, *, (, -]

8 → Apilar en pila_valores: [3, 5, 2, 8]

) → Realizar 2 - 8 = -6, apilar en pila_valores: [3, 5, -6]

* → Realizar 5 * -6 = -30, apilar en pila_valores: [3, -30]

+ → Realizar 3 + (-30) = -27, apilar en pila_valores: [-27]

*/


/*
    Evaluar: 

3 + 5 * (2 - 8)

10 + 2 * 6

(5 + 3) * 2

12 / (4 + 2)

15 - (7 + 3) * 2

3 * (4 + 5) / (2 + 3)

7 + 8 * 3 - 4

4 * (3 + 2) + 1

(9 + 4) * (5 - 3)

20 / (5 + 5) * 3

*/
