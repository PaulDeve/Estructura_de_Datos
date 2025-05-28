#include <iostream>
using namespace std;

struct Curso {
    string nombre;
    Curso* prereq, *sig;
};

int main() {
    bool aprobado;
    Curso* cursos = new Curso{"Analisis y Diseno de Algoritmos", null, null};
    cursos->sig = new Curso{"Estructura de Datos", cursos, null};
    cursos->sig->sig = new Curso{"Lenguajes de Programacion I", cursos, null};

    cout << "¿Aprobaste Analisis y Diseno de Algoritmos? (1 = si, 0 = no): ";
    cin >> aprobado;

    if (aprobado) {
        for (Curso* c = cursos->sig; c; c = c->sig)
            cout << "Puedes llevar: " << c->nombre << endl;
    } else {
        cout << "No puedes llevar cursos dependientes hasta aprobar Analisis y Diseno de Algoritmos.\n";
    }
    return 0;
}

