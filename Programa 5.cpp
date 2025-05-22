#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int calificaciones[30], suma = 0, contador = 0;
    float promedio;

    ifstream archivo("calificaciones.txt");

    if (!archivo) {
        cerr << "No se pudo abrir el archivo" << endl;
        return 1;
    }

    for (int i = 0; i < 30; i++) {
        if (!(archivo >> calificaciones[i])) {
            cerr << "Error: El archivo no contiene suficientes datos." << endl;
            return 1;
        }
        suma += calificaciones[i];
    }

    archivo.close();

    promedio = suma / 30.0;

    for (int i = 0; i < 30; i++) {
        if (calificaciones[i] > promedio) {
            contador++;
        }
    }

    cout << "Promedio general: " << promedio << endl;
    cout << "Estudiantes por encima del promedio: " << contador << endl;

    return 0;
}

