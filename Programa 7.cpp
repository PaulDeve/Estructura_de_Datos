#include <iostream>
using namespace std;

int main() {
    int numeros[10], temp;

    for (int i = 0; i < 10; i++) {
        cout << "Ingrese el numero " << (i + 1) << ": ";
        cin >> numeros[i];
    }

    temp = numeros[9];
    for (int i = 9; i > 0; i--) {
        numeros[i] = numeros[i - 1];
    }
    numeros[0] = temp;

    cout << "Arreglo rotado a la derecha: ";
    for (int i = 0; i < 10; i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;

    return 0;
}

