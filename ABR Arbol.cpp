#include <iostream>More actions
#include <limits> // Para limpiar correctamente el buffer
using namespace std;

// Estructura de un nodo del arbol genealogico
struct Nodo {
    string nombre;
    Nodo* izq;
    Nodo* der;
};

// Crear un nuevo nodo
Nodo* nuevoNodo(string nombre) {
    Nodo* nodo = new Nodo();
    nodo->nombre = nombre;
    nodo->izq = NULL;
    nodo->der = NULL;
    return nodo;
}

// Insertar un nodo en el arbol (ordenado alfabeticamente)
Nodo* insertar(Nodo* raiz, string nombre) {
    if (raiz == NULL)
        return nuevoNodo(nombre);

    if (nombre < raiz->nombre)
        raiz->izq = insertar(raiz->izq, nombre);
    else if (nombre > raiz->nombre)
        raiz->der = insertar(raiz->der, nombre);
    else
        cout << "?? El nombre ya existe.\n";
        cout << " El nombre ya existe.\n";

    return raiz;
}

// Recorrido INORDEN
void inorden(Nodo* nodo) {
    if (nodo != NULL) {
        inorden(nodo->izq);
        cout << nodo->nombre << " ";
        inorden(nodo->der);
    }
}

// Recorrido PREORDEN
void preorden(Nodo* nodo) {
    if (nodo != NULL) {
        cout << nodo->nombre << " ";
        preorden(nodo->izq);
        preorden(nodo->der);
    }
}

// Recorrido POSTORDEN
void postorden(Nodo* nodo) {
    if (nodo != NULL) {
        postorden(nodo->izq);
        postorden(nodo->der);
        cout << nodo->nombre << " ";
    }
}

int main() {
    Nodo* raiz = NULL;
    int opcion;
    string nombre;

    do {
        cout << "\n--- MENU ARBOL GENEALOGICO ---\n";
        cout << "1. Insertar familiar\n";
        cout << "2. Mostrar recorrido Inorden\n";
        cout << "3. Mostrar recorrido Preorden\n";
        cout << "4. Mostrar recorrido Postorden\n";
        cout << "5. Salir\n";
        cout << "Opcion: ";
        if (!(cin >> opcion)) {
            cin.clear(); // limpia el error
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida. Intente de nuevo.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia salto de linea

        switch (opcion) {
            case 1:
                cout << "Ingrese nombre del familiar: ";
                getline(cin, nombre);  // Permite ingresar nombres con espacios
                raiz = insertar(raiz, nombre);
                break;
            case 2:
                cout << "Inorden: ";
                inorden(raiz);
                cout << "\n";
                break;
            case 3:
                cout << "Preorden: ";
                preorden(raiz);
                cout << "\n";
                break;
            case 4:
                cout << "Postorden: ";
                postorden(raiz);
                cout << "\n";
                break;
            case 5:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion no valida.\n";
        }

    } while (opcion != 5);
    return 0;
}
