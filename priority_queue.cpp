#include "priority_queue.h"
#include <stdexcept>
#include <iostream>

using namespace std;

// Constructor: Inicializa la raíz como nullptr y la cantidad de elementos como 0
priority_queue::priority_queue() : raiz(nullptr), cantidad(0) {}

// Destructor: Elimina todos los nodos de la cola priorizada
priority_queue::~priority_queue() {
    // Complejidad: O(n log n)
    // Llama a pop() n veces, cada una de las cuales es O(log n)
    while (!empty()) {
        pop();
    }
}

// Función para ordenar el nodo hacia arriba en el heap
void priority_queue::ordenarArriba(Nodo* nodo) {
    // Complejidad: O(log n) en el peor caso
    // En el peor caso, el nodo puede subir hasta la raíz, lo que implica recorrer la altura del árbol, que es log(n) en un heap balanceado.
    while (nodo->padre != nullptr && nodo->dato > nodo->padre->dato) {
        // Intercambiamos los datos
        int temp = nodo->dato;
        nodo->dato = nodo->padre->dato;
        nodo->padre->dato = temp;
        nodo = nodo->padre;
    }
}

// Función para ordenar el nodo hacia abajo en el heap
void priority_queue::ordenarAbajo(Nodo* nodo) {
    // Complejidad: O(log n) en el peor caso
    // En el peor caso, el nodo puede bajar hasta una hoja, lo que implica recorrer la altura del árbol, que es log(n) en un heap balanceado.
    while (true) {
        Nodo* mayor = nodo;
        if (nodo->izquierdo != nullptr && nodo->izquierdo->dato > mayor->dato) {
            mayor = nodo->izquierdo;
        }
        if (nodo->derecho != nullptr && nodo->derecho->dato > mayor->dato) {
            mayor = nodo->derecho;
        }
        if (mayor == nodo) {
            break;
        }

        // Intercambiamos los datos
        int temp = nodo->dato;
        nodo->dato = mayor->dato;
        mayor->dato = temp;
        nodo = mayor;
    }
}

// Función para eliminar un nodo específico del heap
void priority_queue::eliminarNodo(Nodo* nodo) {
    // Complejidad: O(1)
    // Solo realiza operaciones constantes para ajustar punteros y eliminar el nodo.
    if (nodo->padre == nullptr) {
        raiz = nullptr;
    } else if (nodo->padre->izquierdo == nodo) {
        nodo->padre->izquierdo = nullptr;
    } else {
        nodo->padre->derecho = nullptr;
    }
    delete nodo;
    cantidad--;
}

// Función para encontrar el último nodo en el heap
Nodo* priority_queue::ultimoNodo() {
    // Complejidad: O(log n)
    // Puede bajar hasta una hoja, lo que implica recorrer la altura del árbol, que es log(n) en un heap balanceado.
    Nodo* nodo = raiz;
    while (nodo && nodo->izquierdo) {
        nodo = nodo->izquierdo;
    }
    return nodo;
}

// Función para insertar un nuevo valor en el heap
void priority_queue::push(int valor) {
    // Complejidad: O(log n) en el peor caso
    // Inserta un nodo y luego llama a ordenarArriba, que es O(log n).
    Nodo* nodo = new Nodo(valor);
    if (raiz == nullptr) {
        raiz = nodo;
    } else {
        // Inserción de nodo en el último lugar
        Nodo* padre = ultimoNodo();
        if (padre->izquierdo == nullptr) {
            padre->izquierdo = nodo;
        } else {
            padre->derecho = nodo;
        }
        nodo->padre = padre;
        ordenarArriba(nodo);
    }
    cantidad++;
}

// Función para eliminar el nodo con mayor prioridad (la raíz) del heap
void priority_queue::pop() {
    // Complejidad: O(log n) en el peor caso
    // Intercambia la raíz con el último nodo, elimina el último nodo y llama a ordenarAbajo, que es O(log n).
    if (empty()) {
        throw runtime_error("La fila priorizada está vacía.");
    }

    // Intercambiamos los datos de la raíz con el último nodo
    Nodo* ultimo = ultimoNodo();
    int temp = raiz->dato;
    raiz->dato = ultimo->dato;
    ultimo->dato = temp;

    eliminarNodo(ultimo);

    if (raiz != nullptr) {
        ordenarAbajo(raiz);
    }
}

// Función para obtener el valor del nodo con mayor prioridad (la raíz)
int priority_queue::top() const {
    // Complejidad: O(1)
    // Solo accede al valor de la raíz.
    if (empty()) {
        throw runtime_error("La fila priorizada está vacía.");
    }
    return raiz->dato;
}

// Función para verificar si el heap está vacío
bool priority_queue::empty() const {
    // Complejidad: O(1)
    // Solo verifica la cantidad de elementos.
    return cantidad == 0;
}

// Función para obtener el tamaño del heap
int priority_queue::size() const {
    // Complejidad: O(1)
    // Solo devuelve la cantidad de elementos.
    return cantidad;
}

// Función para imprimir los elementos del heap (solo para depuración)
void priority_queue::print() const {
    // Complejidad: O(n)
    // Recorre todos los nodos del heap.
    if (empty()) {
        cout << "La fila priorizada está vacía." << endl;
        return;
    }

    cout << "Fila priorizada: ";
    Nodo* nodo = raiz;
    while (nodo != nullptr) {
        cout << nodo->dato << " ";
        nodo = nodo->izquierdo;
    }
    cout << endl;
}