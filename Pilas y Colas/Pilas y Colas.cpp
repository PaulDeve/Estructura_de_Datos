#include <iostream>
using namespace std;

const int MAX = 100;

struct Pila {
    int datos[MAX];
    int tope = -1;

    bool vacia() { return tope == -1; }

    void push(int x) {
        if (tope < MAX - 1) {
            datos[++tope] = x;
        }
    }

    int pop() {
        if (!vacia()) {
            return datos[tope--];
        }
        return -1; // valor de error
    }

    int peek() {
        return datos[tope];
    }
};

struct Cola {
    int datos[MAX];
    int frente = 0;
    int final = 0;

    bool vacia() { return frente == final; }

    void enqueue(int x) {
        if (final < MAX) {
            datos[final++] = x;
        }
    }

    int dequeue() {
        if (!vacia()) {
            return datos[frente++];
        }
        return -1; // valor de error
    }
};

// TRANSFER: mueve n elementos de pila a cola
void TRANSFER(Pila& pila, Cola& cola, int n) {
    int contador = 0;
    while (!pila.vacia() && contador < n) {
        int x = pila.pop();
        cola.enqueue(x);
        contador++;
    }
}

// Función para mostrar contenido de la cola
void mostrarCola(Cola& cola) {
    cout << "Cola: ";
    for (int i = cola.frente; i < cola.final; i++) {
        cout << cola.datos[i] << " ";
    }
    cout << endl;
}

// Función para mostrar contenido de la pila
void mostrarPila(Pila& pila) {
    cout << "Pila: ";
    for (int i = 0; i <= pila.tope; i++) {
        cout << pila.datos[i] << " ";
    }
    cout << endl;
}

int main() {
    Pila miPila;
    Cola miCola;

    // Agregamos elementos a la pila
    miPila.push(10);
    miPila.push(20);
    miPila.push(30);
    miPila.push(40);

    cout << "Antes de TRANSFER:\n";
    mostrarPila(miPila);
    mostrarCola(miCola);

    // Transferimos 3 elementos
    TRANSFER(miPila, miCola, 3);

    cout << "\nDespues de TRANSFER:\n";
    mostrarPila(miPila);
    mostrarCola(miCola);

    return 0;
}

