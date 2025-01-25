#include<stdio.h>

typedef struct{
    char nombre[10];
    int edad;
}Persona;

// Función que imprime una persona usando
// desreferenciación explícita de un apuntador
void imprimirPersona1(Persona *p){
    printf("\n\n\t Usando * y .");
    printf("\n\t Nombre: %s ",(*p).nombre);
    printf("\n\t Edad: %d",(*p).edad);
}

// Función que imprime una persona usando
// una forma más directa para acceder  los mienbros
void imprimirPersona2(Persona *p){
    printf("\n\n\t Usando -> ");
    printf("\n\t Nombre: %s",p->nombre);
    printf("\n\t Edad: %d",p->edad);
    // -> acceso directo a un miebro de una estructura apuntada...
}

int main(){

    Persona persona = {"Carlos",25};

    // Forma simple de acceder a los miembros:
    printf("\n\n\t Forma simple usando .");
    printf("\n\t Nombre: %s",persona.nombre);
    printf("\n\t Edad: %d",persona.edad);

    // Creando un apuntador a una estructura:
    Persona *apt_persona = &persona;

    // Pasando por referencia una estructura a una función:
    imprimirPersona1(apt_persona);
    imprimirPersona2(apt_persona);

    printf("\n\n");
    return 0;
}