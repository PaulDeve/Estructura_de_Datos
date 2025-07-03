// C2:P5 2.2.2 - Generar permutaciones con next_permutation
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 3; // Fijamos n para pruebas: {1, 2, 3}
    vector<int> permutation;

    // Inicializar vector con 1, 2, ..., n
    for (int i = 1; i <= n; i++) {
        permutation.push_back(i);
    }

    // Generar todas las permutaciones en orden lexicográfico
    do {
        for (int x : permutation) cout << x << " ";
        cout << "\n";
    } while (next_permutation(permutation.begin(), permutation.end()));

    return 0;
}

