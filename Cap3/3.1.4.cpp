// C3:p14 3.1.4 - Definiciones formales de O, O y T
#include <bits/stdc++.h>
using namespace std;

// f(n) = n
void ejemplo_lineal(int n) {
    int suma = 0;
    for (int i = 1; i <= n; i++) {
        suma += i;
    }
    cout << "f(n) = " << suma << "\n";
}

// f(n) = n^2
void ejemplo_cuadratico(int n) {
    int suma = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            suma += i * j;
        }
    }
    cout << "f(n^2) = " << suma << "\n";
}

// f(n) = 5n + 3 ? O(n), O(n), T(n)
void ejemplo_lineal_ajustada(int n) {
    int suma = 0;
    for (int i = 0; i < 5 * n + 3; i++) {
        suma++;
    }
    cout << "f(5n+3) = " << suma << "\n";
}

int main() {
    int n = 10000;

    cout << "--- Cotas asint�ticas ---\n";

    // O(n^2) tambi�n es O(n^3), pero no es T(n^3)
    cout << "\nEjemplo de O(n):\n";
    ejemplo_lineal(n);

    cout << "\nEjemplo de O(n^2):\n";
    ejemplo_cuadratico(200); // cuidado con n grande aqu�

    cout << "\nEjemplo de T(n): f(n) = 5n + 3\n";
    ejemplo_lineal_ajustada(n);

    cout << "\nInterpretaci�n:\n";
    cout << " - O(f(n)): l�mite superior ? crece como m�ximo a esa velocidad\n";
    cout << " - O(f(n)): l�mite inferior ? crece al menos a esa velocidad\n";
    cout << " - T(f(n)): crece exactamente a esa velocidad (O y O simult�neos)\n";

    return 0;
}

