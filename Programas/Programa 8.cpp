#include <iostream>
using namespace std;

int main() {
    int numeros[20], visitado[20] = {0};

    for (int i = 0; i < 20; i++) {
        cout << "Ingrese el numero " << (i + 1) << ": ";
        cin >> numeros[i];
    }

    for (int i = 0; i < 20; i++) {
        if (visitado[i]) continue;

        int frecuencia = 1;
        for (int j = i + 1; j < 20; j++) {
            if (numeros[i] == numeros[j]) {
                frecuencia++;
                visitado[j] = 1;
            }
        }

        cout << "El numero " << numeros[i] << " aparece " << frecuencia << " veces." << endl;
    }

    return 0;
}

