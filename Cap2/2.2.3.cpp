// C2:P6 2.2.3 - Problema de las N reinas
#include <bits/stdc++.h>
using namespace std;

int n = 8; // Valor fijo para pruebas
int count_solutions = 0;
vector<int> col, diag1, diag2;

void search(int y) {
    if (y == n) {
        count_solutions++;
        return;
    }
    for (int x = 0; x < n; x++) {
        if (col[x] || diag1[x + y] || diag2[x - y + n - 1]) continue;
        col[x] = diag1[x + y] = diag2[x - y + n - 1] = 1;
        search(y + 1);
        col[x] = diag1[x + y] = diag2[x - y + n - 1] = 0;
    }
}

int main() {
    // Inicializar vectores de control
    col.assign(n, 0);
    diag1.assign(2 * n - 1, 0);
    diag2.assign(2 * n - 1, 0);

    // Iniciar búsqueda
    search(0);

    // Mostrar número de soluciones
    cout << "Soluciones para " << n << " reinas: " << count_solutions << "\n";
    return 0;
}

