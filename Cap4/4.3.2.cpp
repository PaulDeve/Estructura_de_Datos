// C4:p11 4.3.2 - Binary Search para encontrar el valor m�nimo x tal que valid(x) = true
#include <bits/stdc++.h>
using namespace std;

int k = 8; // n�mero total de trabajos
vector<int> p = {2, 3, 7}; // tiempos de cada m�quina

// Valid(x): �es posible procesar todos los trabajos en <= x tiempo?
bool valid(int x) {
    long long total = 0;
    for (int t : p) {
        total += x / t;
    }
    return total >= k;
}

int main() {
    cout << "--- Binary Search para soluci�n �ptima ---\n";

    // l�mite superior (por ejemplo usando solo la m�quina m�s r�pida)
    int x = -1;
    for (int b = k * p[0]; b >= 1; b /= 2) {
        while (!valid(x + b)) x += b;
    }

    int respuesta = x + 1;
    cout << "Tiempo m�nimo necesario para procesar " << k << " trabajos: ";
    cout << respuesta << "\n";

    return 0;
}

