#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

// Estructura del nodo para la cola priorizada.
struct Nodo {
    int dato;        
    Nodo* izquierdo;  
    Nodo* derecho;   
    Nodo* padre;     

    Nodo(int valor) : dato(valor), izquierdo(nullptr), derecho(nullptr), padre(nullptr) {}
};

// Implementa una fila priorizada utilizando un árbol binario de nodos.
class priority_queue {
private:
    Nodo* raiz;  
    int cantidad;

    // Función para reordenar el heap hacia arriba
    void ordenarArriba(Nodo* nodo);

    // Función para reordenar el heap hacia abajo
    void ordenarAbajo(Nodo* nodo);

    // Función que elimina un nodo
    void eliminarNodo(Nodo* nodo);

    // Función para encontrar el último nodo en el heap
    Nodo* ultimoNodo();
    
public:
    priority_queue();   
    ~priority_queue();  

    // Agrega un dato a la fila priorizada.
    // Parametro: El valor entero que se va a agregar a la fila priorizada.
    void push(int valor);

    // Saca de la fila priorizada el dato que tiene mayor prioridad (el máximo).
    void pop();

    // Regresa el valor del dato que tiene mayor prioridad (el máximo).
    // Return: El entero con mayor prioridad.
    int top() const;

    // Regresa si la fila priorizada está vacía.
    // Return: true si la fila está vacía, false en caso contrario.
    bool empty() const;

    // Regresa la cantidad de datos que tiene la fila priorizada.
    // Return: El número de elementos en la fila priorizada.
    int size() const;

    // Función para imprimir la fila priorizada.
    void print() const;
};

#endif // PRIORITY_QUEUE_H