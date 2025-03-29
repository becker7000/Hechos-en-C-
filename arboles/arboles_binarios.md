# Árbol Binario

## ¿Qué es un Árbol Binario?

Un **árbol binario** es una estructura de datos en la que cada **nodo** tiene como máximo dos hijos. Estos hijos se denominan:
- **Hijo izquierdo**: El primer hijo de un nodo.
- **Hijo derecho**: El segundo hijo de un nodo.

### Características de un Árbol Binario:
- **Raíz**: Es el nodo inicial del árbol, el que no tiene padres.
- **Nodo**: Cada elemento dentro del árbol.
- **Hoja**: Un nodo que no tiene hijos.
- **Subárbol**: Cualquier nodo y sus descendientes forman un subárbol.

### Tipos de Árboles Binarios:
- **Árbol Binario Completo**: Todos los niveles del árbol están completamente llenos, excepto posiblemente el último nivel, que se llena de izquierda a derecha.
- **Árbol Binario Perfecto**: Todos los nodos tienen exactamente dos hijos, y todos los niveles están completamente llenos.
- **Árbol Binario de Búsqueda (BST)**: Es un tipo de árbol binario en el que para cada nodo:
  - Los valores del subárbol izquierdo son menores que el valor del nodo.
  - Los valores del subárbol derecho son mayores que el valor del nodo.

### Representación Visual de un Árbol Binario:
```
     1
   /   \
  2     3
 / \   / \
4   5 6   7
```

- La raíz es el nodo **1**.
- El subárbol izquierdo tiene la raíz **2** con los nodos **4** y **5** como hijos.
- El subárbol derecho tiene la raíz **3** con los nodos **6** y **7** como hijos.

### Operaciones Comunes en un Árbol Binario:
- **Inserción**: Añadir un nuevo nodo al árbol.
- **Eliminación**: Eliminar un nodo del árbol.
- **Recorridos**: Explorar todos los nodos del árbol de diversas formas (preorden, inorden, postorden).
  
## Usos Comunes de los Árboles Binarios:
- **Estructura de búsqueda eficiente** (en el caso de los árboles binarios de búsqueda).
- **Expresiones aritméticas** (se pueden usar para representar expresiones matemáticas).
- **Estructuras jerárquicas** (por ejemplo, en sistemas de archivos).
- **Optimización de operaciones** (como en los árboles balanceados, que permiten una búsqueda más rápida).

### Tipos de Recorridos en un Árbol Binario:
1. **Preorden**: Raíz -> Izquierda -> Derecha
2. **Inorden**: Izquierda -> Raíz -> Derecha
3. **Postorden**: Izquierda -> Derecha -> Raíz

---

## Resumen:
El árbol binario es una estructura fundamental en informática, utilizada para almacenar datos de forma jerárquica. Su principal característica es que cada nodo tiene como máximo dos hijos, lo que permite representaciones eficientes de datos y operaciones rápidas en muchas aplicaciones, como búsqueda y optimización de algoritmos.


# Recorridos en Árbol Binario

### Árbol Binario:
```
      1
    /   \
   2     3
  / \   / \
 4   5 6   7
```


### Tipos de Recorrido: 

#### 1. **Preorden** (Raíz -> Izquierda -> Derecha):
- Primero se visita la raíz, luego el subárbol izquierdo y finalmente el subárbol derecho.

**Resultado del recorrido en Preorden**: 1 2 4 5 3 6 7


#### 2. **Inorden** (Izquierda -> Raíz -> Derecha):
- Primero se recorre el subárbol izquierdo, luego se visita la raíz y finalmente se recorre el subárbol derecho.

**Resultado del recorrido en Inorden**: 4 2 5 1 6 3 7


#### 3. **Postorden** (Izquierda -> Derecha -> Raíz):
- Primero se recorre el subárbol izquierdo, luego el subárbol derecho y finalmente se visita la raíz.

**Resultado del recorrido en Postorden**: 4 5 2 6 7 3 1


---

### Resumen de los Tres Recorridos:

| Tipo de Recorrido | Orden de Visita                  | Resultado para el árbol dado      |
|-------------------|-----------------------------------|------------------------------------|
| **Preorden**      | Raíz -> Izquierda -> Derecha      | 1 2 4 5 3 6 7                     |
| **Inorden**       | Izquierda -> Raíz -> Derecha      | 4 2 5 1 6 3 7                     |
| **Postorden**     | Izquierda -> Derecha -> Raíz      | 4 5 2 6 7 3 1                     |

---

### Visualización de los Recorridos:

1. **Preorden**: Visita la raíz primero (1), luego el subárbol izquierdo (2, 4, 5), y después el subárbol derecho (3, 6, 7).
2. **Inorden**: Recorre el subárbol izquierdo primero (4, 2, 5), luego visita la raíz (1), y luego recorre el subárbol derecho (6, 3, 7).
3. **Postorden**: Recorre el subárbol izquierdo primero (4, 5, 2), luego el subárbol derecho (6, 7, 3), y finalmente la raíz (1).
