// C4:p11 4.3.2 - Binary Search para encontrar el valor mínimo x tal que valid(x) = true
#include <bits/stdc++.h>
using namespace std;

int k = 8; // número total de trabajos
vector<int> p = {2, 3, 7}; // tiempos de cada máquina

// Valid(x): ¿es posible procesar todos los trabajos en <= x tiempo?
bool valid(int x) {
    long long total = 0;
    for (int t : p) {
        total += x / t;
    }
    return total >= k;
}

int main() {
    cout << "--- Binary Search para solución óptima ---\n";

    // límite superior (por ejemplo usando solo la máquina más rápida)
    int x = -1;
    for (int b = k * p[0]; b >= 1; b /= 2) {
        while (!valid(x + b)) x += b;
    }

    int respuesta = x + 1;
    cout << "Tiempo mínimo necesario para procesar " << k << " trabajos: ";
    cout << respuesta << "\n";

    return 0;
}

