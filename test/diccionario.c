#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Constanstes definidas, tienen alcance global
#define TAM_P 30
#define TAM_S 80

// Definición de la estructura de un nodo palabra
typedef struct Palabra{
    char palabra[TAM_P]; // Se guarda la palabra
    char significado[TAM_S]; // Se guarda el significado
    struct Palabra* siguiente; // Apuntador a el siguiente nodo
    struct Palabra* anterior; // Apuntador al nodo anterior
}Palabra;

// Definición de la estructura de un nodo Letra
typedef struct Letra{
    char letra;
    struct Palabra* listaPalabras; // Apuntador al primer mnodo de la lista de palabras
    struct Letra* siguiente; // Apuntador al siguiente nodo de la lista de letras
    struct Letra* anterior; // Apuntador al nodo anterior de la lista de letras
}Letra;

// Función para crear un nuevo nodo de tipo palabra:
Palabra* crearPalabra(char palabra[],char significado[]){

    // Reservamos el espacio en memoria de una palabra
    Palabra* nuevaPalabra = (Palabra*)malloc(sizeof(Palabra));

    // Copiamos el arreglo palabra del argumento en el arreglo palabra de la nuevaPalabra
    strcpy(nuevaPalabra->palabra,palabra);

    // Copiamos el arreglo significado del argumento en el arreglo significado de la nuevaPalabra
    strcpy(nuevaPalabra->significado,significado);

    // Por defecto apuntamos a NULL el siguiente y el anterior
    nuevaPalabra->siguiente = NULL; // Se inicializa el apuntador al siguiente nodo
    nuevaPalabra->anterior = NULL; // Se inicializa el apuntador al nodo anterior

}

// Función para crear un nuevo nodo de tipo Letra
Letra* crearLetra(char letra){

    // Reservamos un espacio en memoria para guardar la nueva letra
    Letra* nuevaLetra = (Letra*)malloc(sizeof(Letra));

    // Almacenamos la letra del argumento en el campo letra de la nuevaLetra
    nuevaLetra->letra = letra;

    // Inicializamos todos los apuntadores a NULL
    nuevaLetra->listaPalabras = NULL;
    nuevaLetra->siguiente = NULL;
    nuevaLetra->anterior = NULL;

}

// Función para añadir una nueva palabra al diccionario:
void agregarPalabra(Letra* diccionario, char palabra[],char significado[]){

    // Guardamos la inicial de la palabra
    char primeraLetra = palabra[0];

    // Guardamos la primera letra del diccionario
    Letra* letraActual = diccionario;

    // Buscamos la letra que conincide con la inicial de la palabra a agregar
    while(letraActual->siguiente != NULL && letraActual->letra < primeraLetra){
        letraActual = letraActual->siguiente;
    }

    // Si la letra no está en el diccionario, se crea un nuevo nodo de la letra 
    if(letraActual->letra != primeraLetra){

        // Se crea un nuevo nodo de tipo Letra*
        Letra* nuevaLetra = crearLetra(primeraLetra);

        // Se conectan los apuntadores de acuerdo a la lista de letras
        nuevaLetra->siguiente = letraActual->siguiente;
        nuevaLetra->anterior = letraActual;

        if(letraActual->siguiente != NULL){
            letraActual->siguiente->anterior=nuevaLetra;
        }

        // El siguiente de la letra actual se apunta a la nueva letra:
        letraActual->siguiente = nuevaLetra;

        // Movemos el nodo actual hacia la nueva letra:
        letraActual = nuevaLetra;

    }

    // Creamos un nuevo nodo para la palabra:
    Palabra* nuevaPalabra = crearPalabra(palabra,significado);

    // Validamos en caso de que la lista de palabra esté vacía
    // o en dado caso de que la palabra a guardar vaya después de 
    // la siguiente palabra:
    if(letraActual->listaPalabras==NULL || strcmp(letraActual->listaPalabras->palabra,palabra)>0){
        
        // Se asigna el siguiente de la nueva palabra:
        nuevaPalabra->siguiente = letraActual->listaPalabras;

        // Se valida que la lista de palabras no sea nula
        if(letraActual->listaPalabras != NULL){
            letraActual->listaPalabras->anterior=nuevaPalabra;
        }

        // Se reasigna el apuntador al primer elemento de la lista de palabras
        // a la nueva palabra
        letraActual->listaPalabras = nuevaPalabra;

    }else{

        // Apuntador auxiliar para recorrer la lista:
        // Asignamos la primera palabra de la lista de palabra a apuntador palabraActual:
        Palabra* palabraActual = letraActual->listaPalabras;

        // Se busca la posición adecuada para la nueva palabra en la lista de palabras de la letra
        while(palabraActual->siguiente != NULL && strcmp(palabraActual->siguiente->palabra,palabra)<0){
            
            // Vamos recorriendo el apuntador anterior del elemento siguiente a la palabra actual
            palabraActual=palabraActual->siguiente;

        } // Al final la palabraActual apunta a donde debe colocarse la nuevaPalabra

        // Asignamos los apuntadores de la nuevaPalabra:
        nuevaPalabra->siguiente = palabraActual->siguiente;
        nuevaPalabra->anterior = palabraActual;

        // Si la siguiente palabra de la palabra actual
        // no es el final de la lista, entonces se conecta con el siguiente
        if(palabraActual->siguiente != NULL){
            palabraActual->siguiente->anterior=nuevaPalabra;
        }

        palabraActual->siguiente = nuevaPalabra;

    }

}

// Función para imprimir las palabras que comienzan con una letra en especifico.
void imprimirPalabras(Letra* diccionario,char letra){

    // Apuntador auxiliar para recorrer las letras del diccionario
    Letra* letraActual = diccionario->siguiente;

    // Buscamos la letra en el diccionario:
    while(letraActual != NULL && letraActual->letra != letra ){
        letraActual = letraActual->siguiente;
    }

    if(letraActual!=NULL){
        
        // Creamos un apuntador auxiliar para imprimir palabra por palabra:
        Palabra* palabraActual = letraActual->listaPalabras;

        // Imprimimos las palabras que comienzan con la letra del argumento
        printf("\n\t +-------------------------------------------\n");
        printf("\n\t | Letra: %c",letra);
        while(palabraActual != NULL){
            printf("\n\t | %s: %s",palabraActual->palabra,palabraActual->significado);
             palabraActual = palabraActual->siguiente;
        }
        printf("\n\t +-------------------------------------------\n\n");

    }else{
        printf("\n\t No hay palabras que comiencen con la letra: %c \n\n",letra);
    }

}

// Función para editar el significado de una palabra existente en el diccionario:
void editarSignificado(Letra* diccionario, char palabra[], char nuevoSignificado[]) {
    Letra* letraActual = diccionario->siguiente;
    while (letraActual != NULL) {
        Palabra* palabraActual = letraActual->listaPalabras;
        while (palabraActual != NULL) {
            if (strcmp(palabraActual->palabra, palabra) == 0) {
                strcpy(palabraActual->significado, nuevoSignificado);
                printf("Significado de la palabra \"%s\" editado correctamente.\n", palabra);
                return;
            }
            palabraActual = palabraActual->siguiente;
        }
        letraActual = letraActual->siguiente;
    }
    printf("La palabra \"%s\" no se encuentra en el diccionario.\n", palabra);
}

// Función para buscar una palabra en el diccionario y mostrar su significado:
void buscarPalabra(Letra* diccionario, char palabra[]) {
    Letra* letraActual = diccionario->siguiente;
    while (letraActual != NULL) {
        Palabra* palabraActual = letraActual->listaPalabras;
        while (palabraActual != NULL) {
            if (strcmp(palabraActual->palabra, palabra) == 0) {
                printf("Palabra: %s\n", palabraActual->palabra);
                printf("Significado: %s\n", palabraActual->significado);
                return;
            }
            palabraActual = palabraActual->siguiente;
        }
        letraActual = letraActual->siguiente;
    }
    printf("La palabra \"%s\" no se encuentra en el diccionario.\n", palabra);
}

// Función para eliminar una palabra del diccionario:
void eliminarPalabra(Letra* diccionario, char palabra[]) {
    Letra* letraActual = diccionario->siguiente;
    while (letraActual != NULL) {
        Palabra* palabraActual = letraActual->listaPalabras;
        while (palabraActual != NULL) {
            if (strcmp(palabraActual->palabra, palabra) == 0) {
                // Conectar nodos anterior y siguiente para eliminar la palabra
                if (palabraActual->anterior != NULL) {
                    palabraActual->anterior->siguiente = palabraActual->siguiente;
                }
                if (palabraActual->siguiente != NULL) {
                    palabraActual->siguiente->anterior = palabraActual->anterior;
                }
                // Liberar memoria del nodo de la palabra
                free(palabraActual);
                printf("Palabra \"%s\" eliminada correctamente.\n", palabra);
                return;
            }
            palabraActual = palabraActual->siguiente;
        }
        letraActual = letraActual->siguiente;
    }
    printf("La palabra \"%s\" no se encuentra en el diccionario.\n", palabra);
}

// Función para imprimir todo el diccionario
void imprimirDiccionario(Letra* diccionario) {
    Letra* letraActual = diccionario->siguiente;
    while (letraActual != NULL) {
        Palabra* palabraActual = letraActual->listaPalabras;
        printf("\n-----------------------------------------\n");
        printf("\nLetra: %c\n", letraActual->letra);
        while (palabraActual != NULL) {
            printf("Palabra: %s\n", palabraActual->palabra);
            printf("Significado: %s\n", palabraActual->significado);
            palabraActual = palabraActual->siguiente;
        }
        printf("\n-----------------------------------------\n");
        letraActual = letraActual->siguiente;
    }
}

// Función para guardar el diccionario en un archivo de texto
void guardarDiccionarioEnArchivo(Letra* diccionario, const char* nombreArchivo) {
    FILE* archivo = fopen(nombreArchivo, "w");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo para escribir.\n");
        return;
    }

    Letra* letraActual = diccionario->siguiente;
    while (letraActual != NULL) {
        Palabra* palabraActual = letraActual->listaPalabras;
        fprintf(archivo,"\n---------------------------------------\n");
        fprintf(archivo, "Letra: %c\n", letraActual->letra);
        while (palabraActual != NULL) {
            fprintf(archivo, "Palabra: %s\n", palabraActual->palabra);
            fprintf(archivo, "Significado: %s\n", palabraActual->significado);
            palabraActual = palabraActual->siguiente;
        }
        fprintf(archivo,"\n---------------------------------------\n");
        letraActual = letraActual->siguiente;
    }

    fclose(archivo);
    printf("Diccionario guardado en el archivo \"%s\".\n", nombreArchivo);
}


int main(){

    // Creamos el diccionario:
    Letra* diccionario = crearLetra(' '); // Nodo inicial para palabras que comienzan con espacio

    // Variables auxiliares para guardar los valores:
    int opcion;
    char palabra[TAM_P];
    char significado[TAM_S];

    
    do {
        // Menú de opciones
        printf("\nMenú:\n");
        printf("1. Añadir una palabra nueva\n");
        printf("2. Editar significado de palabra\n");
        printf("3. Buscar palabra\n");
        printf("4. Eliminar palabra\n");
        printf("5. Imprimir diccionario\n");
        printf("6. Imprimir palabras de una letra\n");
        printf("7. Salir\n");
        printf("Seleccione una opción: ");
        fflush(stdin);
        scanf("%d", &opcion);

        fflush(stdin);
        switch (opcion) {
            case 1:
                // Añadir una nueva palabra al diccionario
                printf("Ingrese la palabra: ");
                scanf("%s", palabra);
                printf("Ingrese el significado: ");
                scanf("%s", significado);
                agregarPalabra(diccionario, palabra, significado);
                break;
            case 2:
                // Editar significado de palabra
                printf("Ingrese la palabra que desea editar: ");
                scanf("%s", palabra);
                printf("Ingrese el nuevo significado: ");
                scanf("%s", significado);
                editarSignificado(diccionario, palabra, significado);
                break;
            case 3:
                // Buscar palabra
                printf("Ingrese la palabra que desea buscar: ");
                scanf("%s", palabra);
                buscarPalabra(diccionario, palabra);
                break;
            case 4:
                // Eliminar palabra
                printf("Ingrese la palabra que desea eliminar: ");
                scanf("%s", palabra);
                eliminarPalabra(diccionario, palabra);
                break;
            case 5:
                // Imprimir diccionario
                // Implementa esta funcionalidad si deseas mostrar todo el diccionario
                printf("Imprimiendo el diccionario");
                imprimirDiccionario(diccionario);
                break;
            case 6:
                // Imprimir palabras de una letra
                printf("Ingrese la letra: ");
                char letra; 
                scanf(" %c", &letra);
                imprimirPalabras(diccionario, letra);
                break;
            case 7:
                guardarDiccionarioEnArchivo(diccionario,"diccionario.txt");
                printf("\n\tCerrando diccionario...");
        }
        
    }while(opcion!=7);

    printf("\n\t Fin del programa...");    

    return 0;
}
