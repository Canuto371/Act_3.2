// Act 3.2 - Árbol Heap: Implementando una fila priorizada
// Elizabeth Jauregui Zarate (A01253381)

/* Este programa permite al usuario interactuar con una cola priorizada. 
   Los usuarios pueden agregar elementos, eliminar el de mayor prioridad, 
   mostrar el elemento con mayor prioridad, verificar si la cola está vacía 
   y mostrar el tamaño de la cola. La implementación utiliza un árbol binario 
   para mantener el orden de los elementos según su prioridad.
*/   

#include "priority_queue.cpp"
#include <iostream>
#include <limits> 

using namespace std;

// Función para validar la entrada del usuario
int getValidInteger() {
    int num;
    while (true) {
        cin >> num;
        if (cin.fail()) { // Comprobamos si la entrada es válida
            cin.clear(); // Limpia el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora la entrada no válida
            cout << "Entrada no válida. Por favor, ingrese un número entero: ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora el resto de la línea
            return num;
        }
    }
}

int main() {
    priority_queue pq; // Crear una instancia de la cola priorizada
    int n;

    cout << "\nIngrese la cantidad de elementos: ";
    n = getValidInteger(); // Usamos la función de validación para obtener un número entero

    int* arr = new int[n]; // Crear un arreglo dinámico para almacenar los elementos
    cout << "Ingrese los elementos (enteros): \n";
    for (int i = 0; i < n; i++) {
        arr[i] = getValidInteger(); // Validamos cada elemento ingresado
    }

    // Insertar los elementos en la cola priorizada
    for (int i = 0; i < n; i++) {
        pq.push(arr[i]);
    }

    cout << endl;
    pq.print(); //Imprimir la cola priorizada

    delete[] arr; // Liberamos la memoria del arreglo

    int opcion;
    do {
        cout << endl;
        cout << "=========================================\n";
        cout << "                 Opciones                \n";
        cout << "=========================================\n";
        cout << "\n1. Agregar dato a la fila priorizada" << endl;
        cout << "2. Mostrar el dato con mayor prioridad" << endl;
        cout << "3. Sacar dato de la fila priorizada" << endl;
        cout << "4. Mostrar si la fila está vacía" << endl;
        cout << "5. Mostrar tamaño de la fila priorizada" << endl;
        cout << "6. Salir" << endl;
        cout << "=========================================\n";
        cout << "Elija una opción: ";
        opcion = getValidInteger(); // Validamos la opción elegida

        switch (opcion) {
            case 1: {
                // Agregar un dato a la fila priorizada
                
                cout << " \nIngrese el dato a agregar: ";
                int dato = getValidInteger(); // Validamos el dato ingresado
                pq.push(dato);
                cout << "Dato agregado exitosamente." << endl<< endl;
                pq.print(); //Imprimir la cola priorizada
                break;
            }
            case 2: {
                // Mostrar el dato con mayor prioridad
                if (pq.empty()) {
                    cout << "\nLa fila priorizada está vacía." << endl;
                } else {
                    cout << "\nEl dato con mayor prioridad es: " << pq.top() << endl;
                }
                break;
            }
            case 3: {
                // Sacar el dato con mayor prioridad de la fila priorizada
                if (pq.empty()) {
                    cout << "\nLa fila priorizada está vacía." << endl;
                } else {
                    pq.pop();
                    cout << "\nDato eliminado exitosamente." << endl;
                    pq.print(); //Imprimir la cola priorizada
                }
                break;
            }
            case 4: {
                // Mostrar si la fila está vacía
                cout << "\nLa fila priorizada " << (pq.empty() ? "está vacía." : "no está vacía.") << endl;
                break;
            }
            case 5: {
                // Mostrar el tamaño de la fila priorizada
                cout << "\nEl tamaño de la fila priorizada es: " << pq.size() << endl;
                break;
            }
            case 6: {
                cout << "\nSaliendo..." << endl;
                break;
            }
            default: {
                cout << "Opción no válida. Inténtelo de nuevo." << endl;
                break;
            }
        }
    } while (opcion != 6); // Repetir el menú hasta que se elija la opción de salir
}