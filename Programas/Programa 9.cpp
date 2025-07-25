#include <iostream>
using namespace std;

int main() {
    int A[10], B[10], iguales = 0;

    cout << "Ingrese 10 elementos para el arreglo A:\n";
    for (int i = 0; i < 10; i++) {
        cout << "A[" << i + 1 << "]: ";
        cin >> A[i];
    }

    cout << "Ingrese 10 elementos para el arreglo B:\n";
    for (int i = 0; i < 10; i++) {
        cout << "B[" << i + 1 << "]: ";
        cin >> B[i];
    }

    for (int i = 0; i < 10; i++) {
        if (A[i] == B[i]) {
            iguales++;
        }
    }

    cout << "Elementos iguales en la misma posicion: " << iguales << endl;

    return 0;
}

